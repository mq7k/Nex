from util.consts import INT32_MAX
from util.comgen import generate_decorator
from util.parser import get_param_name, get_function_name, get_bitval, get_signature, get_scope_reg

def gen_flagclear(writer, header, function):
    callback_fn = lambda scope: gen_flagclear_body(writer, header, function, scope)
    generate_decorator(writer, function, callback_fn)

def gen_flagclear_body(writer, header, function, scope):
    if 'clear_mode' not in function:
        writer.write(f'Missing \'clear_mode\' properties')
        writer.write(f'Source: {function["fn"]}')
        return

    clear_mode = function['clear_mode']
    if clear_mode == 'w0':
        gen_flagclear_body_w0(writer, header, function, scope)
    elif clear_mode == 'w1':
        gen_flagclear_body_w1(writer, header, function, scope)

def gen_flagclear_body_w0(writer, header, function, scope):
    reg = get_scope_reg(scope)
    periph = header.periph
    fn = get_function_name(function)
    signature = get_signature(function)
    bit = get_bitval(scope)

    writer.assign_reg(periph, reg=reg, value=f'{bit}')
    writer.fncall(fn, signature, periph=periph, **scope.varsmap)

    if scope.halt:
        writer.assert_reg_eq(periph=periph, reg=reg, exp=bit)
    else:
        writer.assert_reg_eq(periph=periph, reg=reg, exp=0)

    writer.assert_execution_status(scope.halt)

    writer.newline()

    writer.assign_reg(periph, reg=reg, value=f'{hex(INT32_MAX)}')
    writer.fncall(fn, signature, periph=periph, **scope.varsmap)

    if scope.halt:
        writer.assert_reg_eq(periph=periph, reg=reg, exp=f'{hex(INT32_MAX)}')
    else:
        writer.assert_reg_eq(periph=periph, reg=reg, exp=f'~{bit}')

    writer.assert_execution_status(scope.halt)

    writer.newline()

def gen_flagclear_body_w1(writer, header, function, scope):
    reg = get_scope_reg(scope)
    periph = header.periph
    fn = get_function_name(function)
    signature = get_signature(function)
    bit = get_bitval(scope)

    writer.assign_reg(periph, reg=reg, value=0)
    writer.fncall(fn, signature, periph=periph, **scope.varsmap)

    if scope.halt:
        writer.assert_reg_eq(periph=periph, reg=reg, exp=0)
    else:
        writer.assert_reg_eq(periph=periph, reg=reg, exp=bit)

    writer.assert_execution_status(scope.halt)

    writer.newline()

    writer.assign_reg(periph, reg=reg, value=f'~{bit}')
    writer.fncall(fn, signature, periph=periph, **scope.varsmap)

    if scope.halt:
        writer.assert_reg_eq(periph=periph, reg=reg, exp=f'~{bit}')
    else:
        writer.assert_reg_eq(periph=periph, reg=reg, exp=f'{hex(INT32_MAX)}')

    writer.assert_execution_status(scope.halt)

    writer.newline()
