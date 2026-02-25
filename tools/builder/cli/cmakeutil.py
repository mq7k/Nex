import subprocess
import json

def to_cmake_bool(value):
    return "ON" if value else "OFF"

def to_cmake_list(arr):
    return ';'.join(arr)

def format_group(group):
    return ''.join([ c if c == 'x' else c.upper() for c in group ])

def get_cpuid_from_stm32_id(cpu):
    arch = {
        '0': ('cortex', 'cortex_m0', 'cm0'),
        '1': ('cortex', 'cortex_m3', 'cm3'),
        '2': ('cortex', 'cortex_m3', 'cm3'),
        '3': ('cortex', 'cortex_m4', 'cm4'),
        '4': ('cortex', 'cortex_m4', 'cm4'),
        '7': ('cortex', 'cortex_m7', 'cm7')
    }

    arr = arch[cpu]
    return {
        'brand': arr[0],
        'model': arr[1],
        'model_short': arr[2]
    }

def parse_mcu_specs(config):
    mcu = config['mcu']
    family = mcu[0:5]
    series = mcu[5]
    core = mcu[6]
    cpuid = get_cpuid_from_stm32_id(core)
    mcu_family_line = f'{family}{series}{core}'
    ld_family_dir = f'{series}x'
    groups = [ format_group(group) for group in config['groups'] ]
    return {
        'family': family,
        'cpu_brand': cpuid['brand'],
        'cpu_model': cpuid['model'],
        'cpu_model_short': cpuid['model_short'],
        'mcu_family_line': mcu_family_line,
        'mcu_fullname': mcu,
        'ld_family_dir': ld_family_dir,
        'ld_script_path': config['ld'],
        'groups': groups
    }

def generate_cmake_command(*, generator, toolchain, output_dir,
                            build_type, platform, target,
                            build_tests, build_examples, devmode,
                            libcom_tests, system_tests, syn_sources, nocstd=False
                           ):
    mcu_specs = parse_mcu_specs(target)

    cmd = [
        'cmake', '-B', output_dir,
        f'-G', generator,
        f'-DNEX_TARGET_FAMILY={mcu_specs["family"]}',
        f'-DNEX_TARGET_ARCH={mcu_specs["cpu_model_short"]}',
        f'-DNEX_TARGET_CPU_FAMILY={mcu_specs["cpu_brand"]}',
        f'-DNEX_PLATFORM={platform.lower()}',
        f'-DNEX_BUILD_TESTS={to_cmake_bool(build_tests)}',
        f'-DNEX_BUILD_EXAMPLES={to_cmake_bool(build_examples)}',
        f'-DCMAKE_BUILD_TYPE={build_type}',
        f'-DNEX_CPU_BRAND={mcu_specs["cpu_brand"].upper()}',
        f'-DNEX_CPU_MODEL={mcu_specs["cpu_model"].upper()}',
        f'-DNEX_MCU_FAMILY={mcu_specs["family"].upper()}',
        f'-DNEX_MCU_FAMILY_LINE={mcu_specs["mcu_family_line"].upper()}',
        f'-DNEX_MCU_FULLNAME={mcu_specs["mcu_fullname"]}',
        f'-DNEX_LD_SCRIPT={mcu_specs["ld_script_path"]}',

        # Always enable devmode when building tests.
        f'-DNEX_INCLUDE_DEVMODE={to_cmake_bool(devmode or build_tests)}', 

        f'-DSYN_MCU_PERIPH_DRIVERS={to_cmake_list(syn_sources.mcu.drivers)}',
        f'-DSYN_MCU_EXAMPLES={to_cmake_list(syn_sources.mcu.examples)}',
        f'-DNEX_MCU_TESTS={to_cmake_list(syn_sources.mcu.tests)}',

        f'-DSYN_ARCH_PERIPH_DRIVERS={to_cmake_list(syn_sources.arch.drivers)}',
        f'-DSYN_ARCH_EXAMPLES={to_cmake_list(syn_sources.arch.examples)}',
        f'-DSYN_ARCH_TESTS={to_cmake_list(syn_sources.arch.tests)}',

        f'-DLIBCOM_TESTS={to_cmake_list(libcom_tests)}',
        f'-DNEX_SYSTEM_TESTS={to_cmake_list(system_tests)}',

        f'-DNEX_NOCSTD={to_cmake_bool(nocstd)}'
    ]

    compiler_flags = []
    linker_flags = []

    if platform == 'desktop':
        compiler_flags.extend(syn_sources.mcu.compiler_flags.desktop_flags)
        compiler_flags.extend(syn_sources.arch.compiler_flags.desktop_flags)

        linker_flags.extend(syn_sources.mcu.linker_flags.desktop_flags)
        linker_flags.extend(syn_sources.arch.linker_flags.desktop_flags)
    elif platform == 'arm':
        compiler_flags.extend(syn_sources.mcu.compiler_flags.arm_flags)
        compiler_flags.extend(syn_sources.arch.compiler_flags.arm_flags)

        linker_flags.extend(syn_sources.mcu.linker_flags.arm_flags)
        linker_flags.extend(syn_sources.arch.linker_flags.arm_flags)
    else:
        raise ValueError('Unknown platform.')

    if compiler_flags:
        cmd.extend([ f'-DNEX_COMPILER_FLAGS={to_cmake_list(compiler_flags)}' ])

    if linker_flags:
        cmd.extend([ f'-DNEX_LINKER_FLAGS={to_cmake_list(linker_flags)}' ])

    if toolchain:
        cmd.extend([ f'-DCMAKE_TOOLCHAIN_FILE={toolchain}' ])

    compact_list = to_cmake_list(mcu_specs['groups'])
    cmd.extend([ f'-DNEX_MCU_GROUPS={compact_list}' ])

    return cmd

def generate_cmake_build_command(output_dir, parallel):
    cmd = [
        'cmake',
        '--build',
        output_dir
    ]

    if parallel:
        cmd.append('--parallel')

    return cmd
