from util.consts import INT32_MAX
from util.comgen import generate_decorator
from util.parser import get_function_name, get_bitval, get_signature, get_scope_reg

def gen_fncall(writer, header, function):
    callback_fn = lambda scope: gen_fncall_body(writer, header, function, scope)
    generate_decorator(writer, function, callback_fn)

def gen_fncall_body(writer, header, function, scope):
    reg = get_scope_reg(scope)
    periph = header.periph
    fn = get_function_name(function)
    signature = get_signature(function)
    bit = get_bitval(scope)

    writer.assign_reg(periph, reg=reg, value=0)
    writer.fncall(fn, signature, periph=periph, **scope.varsmap)
    writer.assert_reg_eq(periph=periph, reg=reg, exp=bit)
    writer.assert_execution_status(scope.halt)

    writer.newline()

    writer.assign_reg(periph, reg=reg, value=f'~{bit}')
    writer.fncall(fn, signature, periph=periph, **scope.varsmap)
    writer.assert_reg_eq(periph=periph, reg=reg, exp=f'{hex(INT32_MAX)}')
    writer.assert_execution_status(scope.halt)

    writer.newline()
