from util.consts import INT32_MAX
from util.comgen import generate_decorator
from util.parser import get_param_name, get_function_name, get_bitval, get_signature, get_scope_reg

def gen_enumset(writer, header, function):
    callback_fn = lambda scope: gen_enumset_body(writer, header, function, scope)
    generate_decorator(writer, function, callback_fn)

def gen_enumset_body(writer, header, function, scope):
    writer.write(f'// {scope=}')

    reg = get_scope_reg(scope)
    periph = header.periph
    fn = get_function_name(function)
    signature = get_signature(function)
    bit = get_bitval(scope)
    shift = scope.shift or 0
    mask = scope.mask or 0

    writer.assign_reg(periph, reg=reg, value=0)
    writer.fncall(fn, signature, periph=periph, **scope.varsmap)
    writer.assert_reg_eq(periph=periph, reg=reg, exp=bit)
    writer.assert_execution_status(scope.halt)

    writer.newline()

    writer.assign_reg(periph, reg=reg, value=f'~({mask}u << {shift})')
    writer.fncall(fn, signature, periph=periph, **scope.varsmap)
    writer.assert_reg_eq(periph=periph, reg=reg, exp=f'~({mask}u << {shift}) | {bit}')
    writer.assert_execution_status(scope.halt)

    writer.newline()
