import json
import os

def fmt_name(name):
    return f"{name.split('.')[0]}.cmake"

ignore_list = [ 'script.py' ]
files = [ file for file in os.listdir('.') if file not in ignore_list and file.endswith('.json') ]

for file in files:
    with open(file, 'r') as src_file:
        c = src_file.read()
    print(f"Loading {file}...")
    doc = json.loads(c)
    print(f"{fmt_name(file)}")
    fullname = doc['mcu']
    ld_script = doc['ld']
    with open(fmt_name(file), 'w') as dst_file:
        print(f'set(NEX_MCU_FULLNAME "{fullname}")', file=dst_file)
        print('set(NEX_MCU_GROUPS', file=dst_file)
        for group in doc['groups']:
            print(f"  {group}", file=dst_file)
        print(')', file=dst_file)
        print(f'set(NEX_MCU_LD_SCRIPT "{ld_script}")', file=dst_file)
        print(f'set(NEX_MCU_DRIVERS_GROUP "{fullname[:-2]}")', file=dst_file)
        print(f'set(NEX_ARCH_DRIVERS_GROUP "cm4")', file=dst_file)
        print(f"{fmt_name(file)} complete.")

