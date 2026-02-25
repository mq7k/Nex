from util.consts import INT32_MAX
from util.comgen import generate_decorator
from util.parser import get_param_name, get_function_name, get_bitval, get_signature, get_scope_reg

def gen_bitmap(writer, header, function):
    callback_fn = lambda scope: gen_bitmap_body(writer, header, function, scope)
    generate_decorator(writer, function, callback_fn)

def gen_bitmap_body_toggle(writer, header, function, scope):
    reg = get_scope_reg(scope)
    periph = header.periph
    fn = get_function_name(function)
    signature = get_signature(function)
    bit = get_bitval(scope)

    enum_set = function['set']
    enum_clear = function['clear']

    bit_arg_name = function['bits']['name']
    bit_min = function['bits']['min']
    bit_max = function['bits']['max']

    extra_vars = {}

    for i in range(bit_min, bit_max):
        bit = f'(1u << {i})'
        extra_vars[bit_arg_name] = i

        writer.assign_reg(periph, reg=reg, value=0)
        writer.fncall(f'{fn}_enable', signature, periph=periph, **extra_vars, **scope.varsmap)
        writer.assert_reg_eq(periph=periph, reg=reg, exp=bit)
        writer.assert_execution_status(scope.halt)

        writer.newline()

        writer.assign_reg(periph, reg=reg, value=f'~{bit}')
        writer.fncall(f'{fn}_enable', signature, periph=periph, **extra_vars, **scope.varsmap)
        writer.assert_reg_eq(periph=periph, reg=reg, exp=f'{hex(INT32_MAX)}')
        writer.assert_execution_status(scope.halt)

        writer.newline()

        writer.assign_reg(periph, reg=reg, value=0)
        writer.fncall(f'{fn}_disable', signature, periph=periph, **extra_vars, **scope.varsmap)
        writer.assert_reg_eq(periph=periph, reg=reg, exp=0)
        writer.assert_execution_status(scope.halt)

        writer.newline()

        writer.assign_reg(periph, reg=reg, value=f'{hex(INT32_MAX)}')
        writer.fncall(f'{fn}_disable', signature, periph=periph, **extra_vars, **scope.varsmap)
        writer.assert_reg_eq(periph=periph, reg=reg, exp=f'~{bit}')
        writer.assert_execution_status(scope.halt)

        writer.newline()

def gen_bitmap_body(writer, header, function, scope):
    options = function.get('options', [])
    if 'toggle' in options:
        gen_bitmap_body_toggle(writer, header, function, scope)
        return

    reg = get_scope_reg(scope)
    periph = header.periph
    fn = get_function_name(function)
    signature = get_signature(function)
    bit = get_bitval(scope)

    enum_set = function['set']
    enum_clear = function['clear']

    bit_arg_name = function['bits']['name']
    bit_min = function['bits']['min']
    bit_max = function['bits']['max']

    param_name = get_param_name(signature, function.get('args', {}), ignore=[ bit_arg_name ])

    extra_vars = {}

    for i in range(bit_min, bit_max):
        bit = f'(1u << {i})'

        if param_name:
            extra_vars[param_name] = enum_set

        extra_vars[bit_arg_name] = i

        writer.assign_reg(periph, reg=reg, value=0)
        writer.fncall(fn, signature, periph=periph, **extra_vars, **scope.varsmap)
        writer.assert_reg_eq(periph=periph, reg=reg, exp=bit)
        writer.assert_execution_status(scope.halt)

        writer.newline()

        writer.assign_reg(periph, reg=reg, value=f'~{bit}')
        writer.fncall(fn, signature, periph=periph, **extra_vars, **scope.varsmap)
        writer.assert_reg_eq(periph=periph, reg=reg, exp=f'{hex(INT32_MAX)}')
        writer.assert_execution_status(scope.halt)

        writer.newline()

        if not param_name:
            continue

        extra_vars[param_name] = enum_clear

        writer.assign_reg(periph, reg=reg, value=0)
        writer.fncall(fn, signature, periph=periph, **extra_vars, **scope.varsmap)
        writer.assert_reg_eq(periph=periph, reg=reg, exp=0)
        writer.assert_execution_status(scope.halt)

        writer.newline()

        writer.assign_reg(periph, reg=reg, value=f'{hex(INT32_MAX)}')
        writer.fncall(fn, signature, periph=periph, **extra_vars, **scope.varsmap)
        writer.assert_reg_eq(periph=periph, reg=reg, exp=f'~{bit}')
        writer.assert_execution_status(scope.halt)

        writer.newline()
