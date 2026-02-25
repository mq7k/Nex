import os
import json
import sys
import re

from types import SimpleNamespace
from typing import TextIO

from util.testwriter import TestWriter
from gens.gen_bienumset import gen_bienumset
from gens.gen_fntoggle import gen_fntoggle
from gens.gen_flagisset import gen_flagisset
from gens.gen_flagclear import gen_flagclear
from gens.gen_enumset import gen_enumset
from gens.gen_fnget import gen_fnget
from gens.gen_fncall import gen_fncall
from gens.gen_bitmap import gen_bitmap
from gens.gen_fnsetvalue import gen_fnsetvalue
from gens.gen_enumtoggle import gen_enumtoggle

from gens.gen_preprocessor import gen_preprocessor
from gens.gen_setupfn import gen_setupfn
from gens.gen_mainfn import gen_mainfn

from parser.tl_parser import parse_tl_file

GENERATORS_MAP = {
    'bienum_set': gen_bienumset,
    'fn_toggle': gen_fntoggle,
    'flag_is_set': gen_flagisset,
    'flag_clear': gen_flagclear,
    'fn_get': gen_fnget,
    'fn_call': gen_fncall,
    'enum_toggle': gen_enumtoggle,
    'fn_set_value': gen_fnsetvalue,
    'enum_set': gen_enumset,
    'bitmap': gen_bitmap
}

def get_fn(fntype):
    return GENERATORS_MAP.get(fntype)

def generate_from_template(template: str, outfile: TextIO):
    writer = TestWriter(outfile = outfile)
    # writer = TestWriter(outfile = sys.stdout)

    header = { 
      'periph': template['periph'],
      'path': template['path'],
      'struct': template['struct']
    }
    header = SimpleNamespace(**header)

    gen_preprocessor(writer, header.path)
    gen_setupfn(writer, header.periph, header.struct)

    functions = template['functions']
    generators = []

    for function in functions:
        fntype = function['type']
        fnname = function['fn']
        genfn = get_fn(function['type'])
        if not genfn:
            text = f'└─Skipping type \'{fntype}\' ({fnname})'
            writer.write(f'// {text}')
            print(text)
            continue

        try:
            genfn(writer, header, function)
        except Exception as e:
            print(f'Error while generating {fnname}')
            raise e
            return

        generators.append(function)

    gen_mainfn(writer, generators)
    print()

def generate_all_in_directory(directory_in, directory_out, filename_fmt):
    files = os.listdir(directory_in)
    for file in files:
        handle_input_file(
            f'{directory_in}/{file}',
            directory_out,
            filename_fmt
        )

def load_json_file(filename):
    try:
        with open(filename, 'r') as srcfile:
            template = json.load(srcfile)
            return template
    except json.decoder.JSONDecodeError as e:
        print(f'!! Failed to parse json template file {filename}', file=sys.stderr)
        print(e)

def load_tl_file(filename):
    try:
        with open(filename, 'r') as srcfile:
            template = parse_tl_file(srcfile.read())
            return template
    except Exception as e:
        print(f'Failed to parse tl template file {filename}')
        raise e

def handle_input_file(filename, directory_out, filename_fmt):
    if filename.endswith('.json'):
        template = load_json_file(filename)
    elif filename.endswith('.tl'):
        template = load_tl_file(filename)
    else:
        print(f'Unknown file type: "{filename}".')
        return

    if not template:
        return

    rawname = filename[filename.rfind("/") + 1:]
    in_filename = rawname[:rawname.find(".")]
    filename = filename_fmt.replace('{file}', in_filename)
    output_dir = template.get('output_dir')

    if not output_dir:
        output_dir = re.sub('[\\d]+$', '', template['periph']).lower()

    parent_dir = f'{directory_out}/{output_dir}'
    if not os.path.exists(parent_dir):
        os.mkdir(parent_dir)

    full_path = f'{parent_dir}/{filename}'

    if os.path.exists(full_path):
        print(f'File \'{full_path}\' already exists.')
        return

    with open(full_path, 'w') as file:
        print(f'Opening file: \'{rawname}\'')
        generate_from_template(template, file)

