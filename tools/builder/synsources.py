import json

def get_examples_list(project, group, examples_file):
    path = f'tools/builder/config/{project}/{examples_file}'

    with open(path, 'r') as file:
        doc = json.load(file)

    examples = doc['examples']
    arr = []
    for k,v in examples.items():
        if group in v:
            arr.append(k)
            continue
        for item in v:
            if item in group:
                arr.append(k)
                continue

    return arr

def get_config_doc(project, group, group_type):
    path = f'tools/builder/config/{project}/{group_type}/{group}.json'

    with open(path, 'r') as file:
        doc = json.load(file)

    return doc

class SynapseSources:
    def __init__(self, mcu_group, mcu_example_file, arch_example_file):
        self.mcu = SourceFiles(
            project='synapse',
            group=mcu_group,
            group_type='mcu_groups',
            examples_file=mcu_example_file
        )

        arch_group = self.mcu.arch
        self.arch = SourceFiles(
            project='synapse',
            group=arch_group,
            group_type='arch_groups',
            examples_file=arch_example_file
        )

class SourceFiles:
    def __init__(self, project, group, group_type, examples_file):
        doc = get_config_doc(project, group, group_type)

        self.compiler_flags = BuildFlags(doc.get('compiler_flags', {}))
        self.linker_flags = BuildFlags(doc.get('linker_flags', {}))

        self.arch = doc.get('arch')
        self.drivers = doc['avb_periphs']
        self.tests = doc['avb_periphs']
        self.examples = get_examples_list(project, group, examples_file)

class BuildFlags:
    def __init__(self, doc):
        self._raw_arm_flags = doc.get('arm', [])
        self._raw_desktop_flags = doc.get('desktop', [])
        self.com_flags = doc.get('com', [])

        self.arm_flags = []
        self.arm_flags.extend(self._raw_arm_flags)
        self.arm_flags.extend(self.com_flags)

        self.desktop_flags = []
        self.desktop_flags.extend(self._raw_desktop_flags)
        self.desktop_flags.extend(self.com_flags)
