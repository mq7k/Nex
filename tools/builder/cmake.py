def to_cmake_bool(value):
    return "ON" if value else "OFF"

def parse_target_path(args):
    family = parse_mcu_family(args)
    series = args.target[5:7]
    fullname = args.target
    return f'{family}/{series}/{fullname}'

def parse_mcu_fullname(args):
    if len(args.target) < 5:
        raise ValueError(f'Invalid fullname: "{args.target}"')

    return args.target

def parse_mcu_family(args):
    # We already checked the len
    # in parse_mcu_fullname().
    return args.target[:5]

def parse_mcu_family_line(args):
    return args.target[:7]

def parse_arch_family(args):
    # We already checked the len
    # in parse_mcu_fullname().
    mcu_family = args.target[:5]
    match mcu_family:
        case 'stm32':
            return 'cortex'

    return 'Unknown'

def parse_platform(args):
    if args.tests:
        return 'desktop'

    if args.examples:
        return 'arm'

    platform = args.platform
    if platform is None:
        platform = 'arm'
    return platform

def parse_toolchain(args):
    if args.toolchain:
        return args.toolchain

    platform = parse_platform(args)
    if platform == 'arm':
        # Use default toolchain file.
        return 'cmake/arm_toolchain.cmake'

    return args.toolchain

def parse_cmake_vars(args):
    vars_table = {
            'CMAKE_TOOLCHAIN_FILE': parse_toolchain,
            'CMAKE_BUILD_TYPE': args.build_type,
            'NEX_TARGET_PATH': parse_target_path,
            'NEX_MCU_FULLNAME': parse_mcu_fullname,
            'NEX_MCU_FAMILY': parse_mcu_family,
            'NEX_MCU_FAMILY_LINE': parse_mcu_family_line,
            'NEX_CPU_FAMILY': parse_arch_family,
            'NEX_PLATFORM': parse_platform,
            'NEX_BUILD_EXAMPLES': args.examples,
            'NEX_BUILD_TESTS': args.tests,
            'NEX_INCLUDE_DEVMODE': to_cmake_bool(args.devmode or args.tests)
    }

    table = {}
    for key, value in vars_table.items():
        if callable(value):
            v = value(args)
            if v:
                table[key] = value(args)
        else:
            table[key] = value

    return table

def generate_cmake_gen_command(options, table):
    cmd = [
            'cmake',
            '-B', options['build_dir'],
            '-G', options['generator']
    ]

    for key, value in table.items():
        cmd.append(f'-D{key}={value}')

    return cmd

def generate_cmake_build_command(build_dir):
    return [
            'cmake', '--build', build_dir
    ]

def generate_cmake_tests_command(path):
    return [
            'ctest', '--test-dir', path, '--output-on-failure'
    ]
