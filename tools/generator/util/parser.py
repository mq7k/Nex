import re

regex = re.compile('{(\\w+)}')

def get_scope_reg(scope):
    return apply_args(scope.reg, **scope.varsmap)

def apply_args(signature, **kargs):
    for key, value in kargs.items():
        signature = signature.replace(f'{{{key}}}', f'{value}')
    return signature

def get_function_name(function):
    return function['fn']

def get_bitval(scope):
    value = scope.value
    shift = scope.shift
    return f'({value}u << {shift})'

def get_signature(function):
    return function.get('signature', '{periph}')

def get_test_fn_name(function):
    fn = function['fn']
    test_fn = function.get('test_fn', fn)
    test_fn = test_fn.replace(f'{{fn}}', fn)
    test_fn = f'test_{test_fn}'
    return test_fn

def get_param_name(signature, args, *, ignore=None):
    global re
    params = re.findall(regex, signature)
    param_name = [ name for name in params if name != 'periph' ]
    keys = args.keys()
    param_name = [ name for name in param_name if name not in keys ]

    if ignore:
        param_name = [ name for name in param_name if name not in ignore ]

    if len(param_name) > 0:
        return param_name[0]

    return None

def parse_int(text, bases=None):
    if isinstance(text, int):
        return text

    if not bases:
        bases = [ 10, 16, 2 ]

    for base in bases:
        try:
            return int(text, base)
        except:
            pass

    raise ValueError(f'Invalid literal \'{text}\' for int() with bases = {bases}')


