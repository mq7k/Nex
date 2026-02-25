import json
from typing import List

def get_sys_tests() -> List[str]:
    path = 'tools/builder/config/system/systests.json'
    
    with open(path, 'r') as file:
        doc = json.load(file)

    return doc.get('tests', [])
