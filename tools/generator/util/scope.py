class Scope:
    def __init__(self):
        self.reg = None
        self.shift = None
        self.mask = None
        self.value = 1
        self.varsmap = {}
        self.ifdef = []
        self.ifndef = []
        self.halt = False

    def apply(self, name, var):
        # if not self.reg:
        #     self.reg = var['reg']

        if 'reg' in var:
            self.reg = var['reg']

        if 'shift' in var:
            if isinstance(var['shift'], str) and var['shift'].startswith('+'):
                self.shift += int(var['shift'])
            else:
                self.shift = var['shift']

            # if self.shift is None:
            #     self.shift = var['shift']
            # elif isinstance(var['shift'], str) and var['shift'].startswith('+'):
            #     self.shift += int(var['shift'])

        # if not self.mask and 'mask' in var:
        #     self.mask = var['mask']

        if 'mask' in var:
            self.mask = var['mask']

        if 'ifdef' in var:
            if isinstance(var['ifdef'], str):
                self.ifdef.append(var['ifdef'])
            else:
                self.ifdef.extend(var['ifdef'])

        if 'ifndef' in var:
            if isinstance(var['ifndef'], str):
                self.ifndef.append(var['ifndef'])
            else:
                self.ifndef.extend(var['ifndef'])

        if 'halt' in var:
            self.halt = self.halt or var['halt']

        if 'value' in var:
            self.value = var['value']

        # self.varsmap[name] = var['enum']
        self.varsmap[name] = var.get('enum', var.get('value'))

    def __repr__(self):
        return f'{self.reg=}, {self.shift=}, {self.mask=}, {self.varsmap=}, {self.value=}, {self.ifdef=}, {self.halt=}'

def inherit_fields(src, dst):
    dst.__dict__.update(src.__dict__)
    dst.ifdef = [ name for name in src.ifdef ]
    dst.ifndef = [ name for name in src.ifndef ]

class ScopeStack:
    def __init__(self):
        self.scope = Scope()
        self.stack = [ self.scope ]

    def push_scope(self):
        scope = Scope()
        inherit_fields(src=self.scope, dst=scope)

        # Do not inherit function's entry ifdef macros.
        if len(self.stack) == 2:
            scope.ifdef = []
            scope.ifndef = []

        self.stack.append(scope)
        self.scope = scope
        return scope

    def pop_scope(self):
        self.stack.pop()
        self.scope = self.stack[-1]
