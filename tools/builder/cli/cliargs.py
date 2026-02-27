import argparse
import os
import json

from cli.synparser import SynParser

def _assert_file_exists(path, message):
    if not os.path.exists(path):
        raise argparse.ArgumentTypeError(message)

def _resolve_stm32_path(arg):
    family = arg[5]
    series = arg[6]
    fullname = arg if arg.endswith('.json') else f'{arg}.json'
    return f'targets/stm32/{family}{series}/{fullname}'

def _try_resolve_target_path(arg):
    if arg.startswith('stm32'):
        return _resolve_stm32_path(arg)

    return None

def target(arg):
    # Let's first see if arg is already a valid path.
    if not os.path.exists(arg):
        path = _try_resolve_target_path(arg)
        if path is None:
            return argparse.ArgumentTypeError(f'Cannot resolve target: \'{path}\'')
        arg = path

    _assert_file_exists(arg, f'Target file not found: \'{arg}\'')
    with open(arg, 'r') as file:
        config = json.load(file)

    if not isinstance(config, dict):
        type_name = type(config).__name__
        raise argparse.ArgumentTypeError(f'Root element must be an object, not {type_name}.')

    required_keys = [ 'mcu', 'groups', 'ld' ]
    missing_keys = [ key for key in required_keys if key not in config ]
    if len(missing_keys) > 0:
        fmt = [ f'\'{item}\'' for item in missing_keys ]
        fmt = ' '.join(fmt)
        raise argparse.ArgumentTypeError(f'Missing required key(s) ({fmt}).')

    if len(config['groups']) == 0:
        raise argparse.ArgumentTypeError(f'\'groups\' key is present but empty.')

    return config

def toolchain(arg):
    _assert_file_exists(arg, f'Toolchain file not found: \'{arg}\'')
    return arg

def get_cli_args():
    parser = SynParser(
        prog='SynBuilder',
        description='Configurable CMake build.'
    )

    # Selects the target MCU to build for.
    # Available targets can be found in the 'targets' directory.
    # This is a required argument.
    parser.add_argument(
        '--target',
        type=target,
        help='Selects the target MCU.',
        required=True
    )

    # Specifies the cmake toolchain file to use.
    # This file configures CMake to cross-compiling targets
    # for a different environment relative to the host.
    parser.add_argument(
        '--toolchain',
        type=toolchain,
        default=None,
        help='Path to toolchain file (default: %(default)s).'
    )

    # Release and Debug toggle compiler / linker flags 
    # about performance and binary size (such as '-O3', '-Os', etc).
    # They do not automatically include or exclude tools such as
    # devmode or profiler.
    # See `--devmode` and `--profiler`.
    parser.add_argument(
        '--build-type',
        choices=['Release', 'Debug'],
        default='Release',
        type=str,
        help='Selects the build type configuration (Default: %(default)s).',
        required=True
    )

    parser.add_argument(
        '--platform',
        choices=['desktop', 'arm'],
        default='arm',
        type=str,
        help='Selects the target platform to build for (Default: %(default)s). If \'--examples\' or \'--tests\' are specified, this flag is ignored.'
    )

    # Specifies the build generator that CMake will use.
    # We won't perform any validation here, since this value may change
    # according to the OS and/or installed build system.
    # For example, 'Visual Studio' is only available if 'VS' is installed.
    # Same thing for 'MinGW' and 'Xcode'.
    # We let CMake handle this.
    parser.add_argument(
        '--generator',
        type=str,
        default='Ninja',
        help='CMake generator (Default: %(default)s).'
    )

    # Deletes the build directory before starting the current build process.
    # This only deletes 'build/$build_dir', not the entire 'build' directory. 
    # See 'build_dir'.
    parser.add_argument(
        '--reset',
        default=False,
        action='store_true',
        help='Clean build directory before building (Default: %(default)s).'
    )

    # Enables tests verbose stdout/stderr output.
    # By default, only the result (success or fail) is shown.
    parser.add_argument(
        '--show-tests-output',
        default=False,
        action='store_true',
        help='Enable all tests output (Default: %(default)s).'
    )

    # Specifies the build directory.
    # By default, generated files are placed in:
    # 'build/desktop' -> If building 'tests' to run a desktop;
    # 'build/arm' -> If building 'examples' to run on a MCU;
    # 'build_dir' overrides 'desktop' or 'arm', if given.
    parser.add_argument(
        '--build-dir',
        type=str,
        help='Output build directory (Default: %(default)s).'
    )

    # Includes devmode in the final binary.
    # Useful to validate functions parameters
    # and transmits errors via a communication 
    # peripheral (user-defined).
    # Not recommended in production builds due
    # to performance penalties.
    # If disabled, functions are completely removed.
    parser.add_argument(
        '--devmode',
        action='store_true',
        help='Include devmode in the final build (Not recommended in production builds).'
    )

    # Toggles CMake parallel build.
    # If enabled, CMake will use >= core to build the project.
    # If disabled, compilation time might be slower.
    parser.add_argument(
        '--parallel',
        action=argparse.BooleanOptionalAction,
        help='Toggles CMake parallel build (Default: %(default)s).'
    )

    parser.add_argument(
        '--nocstd',
        action='store_true',
        help='Do not link against standard C library.'
    )

    group = parser.add_mutually_exclusive_group()

    # Enables tests building.
    # This flag sets build_dir to 'desktop' (Unless explicitly given)
    # and sets the compiler to 'gcc' to build and run on a desktop.
    # Cannot be used together with '--examples'.
    group.add_argument(
        '--tests',
        action='store_true',
        help='Enable tests (Mutually exclusive with \'--examples\'). Overrides \'--platform\'.'
    )

    # Enables examples building.
    # This flags sets 'build_dir' to 'arm' (Unless explicitly given)
    # and sets the compiler to 'arm-none-eabi-gcc' to build and run on a MCU.
    # Cannot be used together with '--tests'.
    group.add_argument(
        '--examples',
        action='store_true',
        help='Enable examples (Mutually exclusive with \'--tests\'). Overrides \'--platform\'.'
    )

    args = parser.parse_args()

    if (args.platform is None) or (args.tests or args.examples):
        # '--examples' and '--tests' have higher priority
        # compared to '--platform'.
        args.platform = 'desktop' if args.tests else 'arm'

    if args.build_dir is None:
        # Same name for the directory.
        args.build_dir = args.platform

    if args.toolchain is None and args.examples:
        args.toolchain = 'cmake/arm_toolchain.cmake'

    return args
