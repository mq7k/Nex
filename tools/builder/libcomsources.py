import json
from typing import List

def get_libcom_tests() -> List[str]:
    path = 'tools/builder/config/libcom/libcom_tests.json'
    
    with open(path, 'r') as file:
        doc = json.load(file)

    return doc.get('tests', [])
