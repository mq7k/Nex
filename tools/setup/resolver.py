import json

def do_install(pm, path):
    with open(path, 'r') as file:
        packages = json.load(file)

    fmt_list = ' '.join(packages)
    result = pm.install(fmt_list)
    return result.returncode == 0
