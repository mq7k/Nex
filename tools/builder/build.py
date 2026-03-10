#!/usr/bin/python

import subprocess
import cliargs
import cmake
import sys
import fs

def get_options(args):
    build_dir = f"build/{args.build_dir}/{args.build_type}"
    return {
            'build_dir': build_dir,
            'build_type': args.build_type.lower(),
            'generator': args.generator
    }

def run_tests(path):
    cmd = cmake.generate_cmake_tests_command(path)
    return execute_cmd(cmd)

def execute_cmd(cmd):
    try:
        p = subprocess.run(cmd, shell=False)
        return p.returncode == 0
    except subprocess.TimeoutExpired:
        return False

def main():
    args = cliargs.get_cli_args()

    try:
        build_config = cmake.parse_cmake_vars(args)
    except ValueError as ve:
        print(f'Error parsing args: {ve}')
        return

    # These options are not used inside any *.cmake file,
    # but they are still necessary to build the project.
    options = get_options(args)

    # Generates build files (Makefile, Ninja, Visual Studio, ...)
    cmd = cmake.generate_cmake_gen_command(options, build_config)
    if not execute_cmd(cmd):
        print('Failed to generate build files.')
        print('CMake exited with non-zero code or the subprocess timed out')
        sys.exit(1)

    # Uses those generated files to compile the project.
    cmd = cmake.generate_cmake_build_command(options['build_dir'])
    if not execute_cmd(cmd):
        print('Failed to build the project.')
        print('CMake exited with non-zero code or the subprocess timed out')
        sys.exit(1)

    # Creates a symlink in `build/compile_commands.json`
    # to allow tools to easily find it.
    fs.create_symlink(
        f'{args.build_dir}/{args.build_type.lower()}/compile_commands.json',
        f'build/compile_commands.json'
    )

    if args.tests:
        build_dir = options['build_dir']

        if not run_tests(f'{build_dir}/appstack/synapse'):
            print('Error while executing synapse tests: non-zero exit code or timed out')

        if not run_tests(f'{build_dir}/appstack/system'):
            print('Error while executing system tests: non-zero exit code or timed out')

if __name__ == '__main__':
    main()
