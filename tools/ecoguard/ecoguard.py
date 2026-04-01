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

def open_dir(path):
    print(f'Opening dir: {path}')
    for file in os.listdir(path):
        fullpath = f'{path}/{file}'
        if os.path.isdir(fullpath):
            open_dir(fullpath)
        elif file.endswith('.cmake'):
            try_compile(file)

def main():
    path = 'appstack/synapse/cmake/targets'
    open_dir(path)

if __name__ == '__main__':
    main()
