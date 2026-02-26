#!/usr/bin/python

# To generate tests.
# tools/generator/gen.py --output-dir tests/periph --path tools/generator/templates/drivers

# To build a target.
# tools/builder/build.py --target=targets/stm32/f4/stm32f446mc.json --build-type=Release --tests

import os
import subprocess
import sys

def execute_cmake_cmd(cmd, timeout):
    try:
        with open('guard.log', 'w') as file:
            res = subprocess.run(cmd, shell=False, cwd=os.getcwd(), stdout=file, stderr=file)
            print(f'Return code: {res.returncode}')

        if res.returncode != 0:
            with open('guard.log', 'r') as file:
                print(file.read())
            sys.exit(0)
        return True
    except subprocess.TimeoutExpired as te:
        return False

def explore_family(path, family):
    print(f'>>> {family=}')

    for mcu in os.listdir(f'{path}/{family}'):
        full_path = f'{path}/{family}/{mcu}'
        print(f'Compiling "{full_path}"')
        cmd = [
            'tools/builder/build.py',
            f'--target={full_path}',
            '--build-type=Release',
            '--tests'
        ]
        execute_cmake_cmd(cmd, 5)
        # time.sleep(3)

def explore_target(target):
    path = f'targets/{target}'
    for family in os.listdir(path):
        explore_family(path, family)

def main():
    # Execute this once.
    # Clear tests/periph content if necessary.
    # tools/generator/gen.py --output-dir tests/periph --path tools/generator/templates/drivers
    
    targets = os.listdir('targets')
    for target in targets:
        explore_target(target)

if __name__ == '__main__':
    main()
