from util.scope import ScopeStack

def parse_encoded_value(text):
    args = text.split(':')
    map = {}
    map['enum'] = args[0]

    if len(args) == 1:
        return map

    for arg in args[1:]:
        if arg.startswith('<<'):
            map['shift'] = arg[2:]

        if arg.startswith('=='):
            map['value'] = arg[2:]

        if arg.startswith('$'):
            map['reg'] = arg[1:]

        if arg.startswith('#'):
            map['ifdef'] = arg[1:].split(';')

        if arg.startswith('!#'):
            map['ifndef'] = arg[2:].split(';')

    return map

def _recv(keys, args, idx, ss):
    key = keys[idx]
    values = args[key]
    for value in values:
        if isinstance(value, str):
            if ':' in value:
                value = parse_encoded_value(value)
            else:
                value = { 'enum': value }

        scope = ss.push_scope()
        scope.apply(key, value)

        if idx + 1 < len(keys):
            yield from _recv(keys, args, idx + 1, ss)
            ss.pop_scope()
            continue

        yield scope
        ss.pop_scope()

def generate_args_combinations(args, ss):
    items = args.items()
    keys = list(args.keys())

    yield from _recv(keys, args, 0, ss)
