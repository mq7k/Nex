#!/usr/bin/python

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
            return res.returncode
    except subprocess.TimeoutExpired:
        return False

def print_err_log():
    with open(ERR_LOG_FILE_NAME, 'r') as file:
        print(file.read())

def try_compile(file):
    print(f'Try compiling target {file}... ', end='', flush=True)
    cmd = [
            'tools/builder/build.py',
            f'--target={file}',
            '--build-type=Release',
            '--tests'
    ]

    code = execute_cmd(cmd)
    if code:
        print(f'Error (code={code})')
        print_err_log()
        sys.exit(code)

    print('Success')

def load_mcu_list():
    arr = []
    path = 'tools/ecoguard/lists'
    for file in os.listdir(path):
        with open(f'{path}/{file}', 'r') as f:
            mcus = [ line.replace('\n', '') for line in f.readlines() ]
            arr.extend(mcus)
    return arr

def try_compile_all(mcu_list):
    for mcu in mcu_list:
        try_compile(mcu)

def main():
    mcu_list = load_mcu_list()
    try_compile_all(mcu_list)

if __name__ == '__main__':
    main()
