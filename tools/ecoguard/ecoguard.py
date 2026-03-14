#!/usr/bin/python

# To generate tests.
# tools/generator/gen.py --output-dir tests/periph --path tools/generator/templates/drivers

# To build a target.
# tools/builder/build.py --target=targets/stm32/f4/stm32f446mc.json --build-type=Release --tests

import os
import subprocess
import sys

ERR_LOG_FILE_NAME = 'guard.log'

def execute_cmd(cmd, timeout=None):
    try:
        with open(ERR_LOG_FILE_NAME, 'w') as file:
            res = subprocess.run(
                cmd,
                shell=False,
                timeout=timeout,
                cwd=os.getcwd(),
                stdout=file,
                stderr=file
            )
            print(f'Return code: {res.returncode}')

            return res.returncode == 0
        # if res.returncode != 0:
        #     with open('guard.log', 'r') as file:
        #         print(file.read())
        #     sys.exit(0)
        # return True
    except subprocess.TimeoutExpired:
        return False

# def explore_family(path, family):
#     print(f'>>> {family=}')
#
#     for mcu in os.listdir(f'{path}/{family}'):
#         full_path = f'{path}/{family}/{mcu}'
#         print(f'Compiling "{full_path}"')
#         cmd = [
#             'tools/builder/build.py',
#             f'--target={full_path}',
#             '--build-type=Release',
#             '--tests'
#         ]
#         execute_cmake_cmd(cmd, 5)

# def explore_target(target):
#     path = f'targets/{target}'
#     for family in os.listdir(path):
#         explore_family(path, family)

def print_err_log():
    with open(ERR_LOG_FILE_NAME, 'r') as file:
        print(file.read())

def try_compile(file):
    print(f'Try compiling target {file}... ', end='')
    cmd = [
            'tools/builder/build.py',
            f'--target={file}',
            '--build-type=Release',
            '--tests'
    ]

    if not execute_cmd(cmd):
        print('Error while trying to compile')
        print_err_log()
        sys.exit(1)
    print('Success')

def open_dir(path):
    print(f'Opening dir: {path}')
    for file in os.listdir(path):
        fullpath = f'{path}/{file}'
        if os.path.isdir(fullpath):
            open_dir(fullpath)
        elif file.endswith('.cmake'):
            try_compile(file)

def main():
    # Execute this once.
    # Clear tests/periph content if necessary.
    # tools/generator/gen.py --output-dir tests/periph --path tools/generator/templates/drivers
    
    path = 'appstack/synapse/cmake/targets'
    open_dir(path)
    # targets = os.listdir('targets')
    # for target in targets:
    #     explore_target(target)

if __name__ == '__main__':
    main()
