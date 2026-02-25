class Context:
    def __init__(self, lines):
        self.lines = lines
        self.idx = 0

    def line(self):
        return self.lines[self.idx]

    def next_line(self):
        self.idx += 1

    def end(self):
        return self.idx >= len(self.lines)

def parse_tl_file(input, delimiter='\n'):
    root = {}

    lines = input.split(delimiter)
    cur_scope = root

    ctx = Context(lines)

    while not ctx.end():
        parse_line(ctx, root)

    return root

def parse_scope(ctx, cur_scope):

    while True:
        line = ctx.line().strip()
        words = line.split(' ')

        if not line:
            ctx.next_line()
            continue

        match words[0]:
            case 'scope':
                ctx.next_line()
                scope = {}
                parse_scope(ctx, scope)
                name = words[1]
                cur_scope[name] = scope
                pass

            case 'list':
                ctx.next_line()
                arr = []
                parse_list(ctx, arr)
                name = words[1]
                cur_scope[name] = arr
                pass

            case 'end':
                ctx.next_line()
                return

            case _:
                key = words[0]
                value = words[1]
                cur_scope[key] = value
                ctx.next_line()
                pass

def parse_list(ctx, cur_arr):
    while True:
        line = ctx.line().strip()
        words = line.split(' ')
        if words[0] == 'end':
            return

        if words[0] != 'entry':
            raise ValueError(f'Expected "entry" token, got \'{words[0]}\'.')

        obj = {}
        for word in words:
            arr = word.split('=')
            key = arr[0]
            if key == 'entry':
                continue
            value = arr[1] if len(arr) > 1 else True

            if isinstance(value, str) and ';' in value:
                value = value.split(';')

            obj[key] = value

        cur_arr.append(obj)
        ctx.next_line()

def parse_line(ctx, cur_scope):
    line = ctx.line()
    words = line.split(' ')

    if not line:
        ctx.next_line()
        return

    match words[0]:
        case 'scope':
            scope = {}
            ctx.next_line()
            parse_scope(ctx, scope)
            name = words[1]
            cur_scope[name] = scope
            pass

        case 'list':
            arr = []
            ctx.next_line()
            parse_list(ctx, arr)
            name = words[1]
            cur_scope[name] = arr
            pass

        case 'end':
            ctx.next_line()
            pass

        case 'entry':
            entry = parse_entry()
            pass

        case _:
            key = words[0]
            value = words[1]
            cur_scope[key] = value
            ctx.next_line()


import sys

def main():
    with open(sys.argv[1], 'r') as file:
        c = file.read()
        root = parse_tl_file(c)
        print(root)

