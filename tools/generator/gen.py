#!/usr/bin/python

import argparse
import json
import os

from gens.generator import generate_all_in_directory, handle_input_file
from util import fs

def template(arg: str) -> str:
    if not os.path.exists(arg):
        raise argparse.ArgumentTypeError(f'No such file: \'{arg}\'')

    return arg

def path(arg: str) -> str:
    if not os.path.exists(arg):
        raise argparse.ArgumentTypeError(f'Directory \'{arg}\' not found.')

    if not os.path.isdir(arg):
        raise argparse.ArgumentTypeError(f'File \'{arg}\' exists but it\'s not a directory.')

    return arg

def output(arg: str) -> str:
    if not os.path.exists(arg):
        raise argparse.ArgumentTypeError(f'Directory \'{arg}\' not found.')

    if not os.path.isdir(arg):
        raise argparse.ArgumentTypeError(f'File \'{arg}\' exists but it\'s not a directory.')

    return arg

def get_cli_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description='')

    _ = parser.add_argument(
        '--auto',
        default=False,
        action='store_true',
        help='Automatic tests generation. Mutually exclusive with (\'--output-dir\', \'--path\' and \'--template\').'
    )

    _ = parser.add_argument(
        '--output-dir',
        default='.',
        type=output,
        help='Specify the directory to place output files.'
    )

    _ = parser.add_argument(
        '--filename-fmt',
        default='{file}_test.c',
        type=str,
        help='Specify the input file to generate the output test.'
    )

    _ = parser.add_argument(
        '--empty-dir',
        default=False,
        action='store_true',
        help='WARNING! This will remove *everything* inside the output directory.'
    )
    
    group = parser.add_mutually_exclusive_group()

    _ = group.add_argument(
        '--template',
        type=template,
        help='Specify the input file to generate the output test.'
    )

    _ = group.add_argument(
        '--path',
        type=path,
        help='Directory containing input files. Each file in the directory is processed independently and produces a corresponding output file.'
    )

    return parser.parse_args()

def main() -> None:
    args: argparse.Namespace = get_cli_args()

    if args.auto:
        if args.output_dir == '.' and not args.template and not args.path:
            # Generates mcu drivers tests.
            path = 'tools/generator/templates/mcu'
            output_dir = 'appstack/synapse/tests/periph'
            generate_all_in_directory(path, output_dir, args.filename_fmt)
            
            # Generate arch drivers tests.
            path = 'tools/generator/templates/arch'
            output_dir = 'appstack/synapse/tests/arch'
            generate_all_in_directory(path, output_dir, args.filename_fmt)

            return
        else:
            print(f'Cannot specify \'--auto\' alongside \'--output-dir\', \'--path\' or \'--template\'.')
            return

    if args.empty_dir and os.path.exists(args.output_dir):
        print(f'Removing all files in \'{args.output_dir}\'')
        for file in os.listdir(args.output_dir):
            fs.unlink(f'{args.output_dir}/{file}')

    if args.template:
        handle_file_input(args.template, args.output_dir, args.filename_fmt)
        return

    if args.path:
        generate_all_in_directory(args.path, args.output_dir, args.filename_fmt)
        return

if __name__ == '__main__':
    main()
