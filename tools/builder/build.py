#!/usr/bin/python

from typing import List
from cli.cliargs import get_cli_args 
from cli.cmakeutil import generate_cmake_command, generate_cmake_build_command
from synsources import SynapseSources
from libcomsources import get_libcom_tests
from systemsources import get_system_tests

import subprocess
import fs
import os
import sys

def execute_cmake_cmd(cmd, timeout):
    try:
        return subprocess.run(cmd, shell=False)
    except subprocess.TimeoutExpired as te:
        return None

def execute_tests(path):
    print(f'Executing tests at {path}')
    cmd = [
        'ctest',
        '--test-dir',
        # f'{path}/appstack/synapse',
        f'{path}',
        '--output-on-failure'
    ]

    return execute_cmake_cmd(cmd, timeout=5)

def main():
    args = get_cli_args()
    output_dir = f'build/{args.build_dir}/{args.build_type.lower()}'

    if args.reset:
        fs.unlink(output_dir)

    # mcu_periph_group = args.target['mcu_periph_group']
    mcu_periph_group = args.target['mcu'][:9]

    synapse_sources = SynapseSources(
        mcu_group=mcu_periph_group,
        mcu_example_file='mcu_examples.json',
        arch_example_file='arch_examples.json'
    )

    libcom_tests: List[str] = get_libcom_tests()
    system_tests: List[str] = get_system_tests()

    toolchain = None
    if args.toolchain:
        toolchain = args.toolchain
    elif args.platform == 'arm':
        # Use default toolchain file.
        toolchain = 'cmake/arm_toolchain.cmake'

    cmake_cmd = generate_cmake_command(
        generator=args.generator,
        toolchain=toolchain,
        output_dir=output_dir,
        build_type=args.build_type,
        platform=args.platform,
        target=args.target,
        build_tests=args.tests,
        build_examples=args.examples,
        devmode=args.devmode,

        libcom_tests=libcom_tests,
        system_tests=system_tests,
        syn_sources=synapse_sources,

        nocstd=args.nocstd
    )
    print(f'Executing CMake command: {" ".join(cmake_cmd)}')

    timeout = 5
    res = execute_cmake_cmd(cmake_cmd, timeout)
    if not res:
        print(f'Timeout reached after {timeout}s', file=sys.stderr)
        exit(1)

    if res.returncode != 0:
        print(f'Failed to generate build files.')
        sys.exit(res.returncode)

    fs.create_symlink(
        f'{args.build_dir}/{args.build_type.lower()}/compile_commands.json',
        f'build/compile_commands.json'
    )

    cmake_build_cmd = generate_cmake_build_command(output_dir, args.parallel)

    res = execute_cmake_cmd(cmake_build_cmd, timeout)
    if not res:
        print(f'Timeout reached after {timeout}s', file=sys.stderr)
        exit(1)

    if res.returncode != 0:
        print(f'Failed to compile project.')
        sys.exit(res.returncode)

    if args.tests:
        # mcu_tests_dir = f'{output_dir}/tests'
        mcu_tests_dir = output_dir
        if os.path.exists(mcu_tests_dir):
            execute_tests(f'{output_dir}/appstack/synapse')
            execute_tests(f'{output_dir}/appstack/system')
        else:
            print(f'{mcu_tests_dir} does not exists.')

if __name__ == '__main__':
    main()

