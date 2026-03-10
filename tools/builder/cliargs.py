import argparse

class SynParser(argparse.ArgumentParser):
    def error(self, message):
        self.exit(2, f"{message}\n")

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
        type=str,
        help='Selects the target MCU.',
        required=True
    )

    # Specifies the cmake toolchain file to use.
    # This file configures CMake to cross-compiling targets
    # for a different environment relative to the host.
    parser.add_argument(
        '--toolchain',
        type=str,
        default=None,
        help='Path to toolchain file (Default: %(default)s).'
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
        # default='arm',
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

    if args.tests or args.platform is None:
        args.platform = 'desktop'
    elif args.examples:
        args.platform = 'arm'

    if args.build_dir is None:
        # Same name for the directory.
        args.build_dir = args.platform

    args.build_dir = args.build_dir.lower()
    args.build_type = args.build_type.lower()
    return args
