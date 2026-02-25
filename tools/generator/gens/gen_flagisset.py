from util.consts import INT32_MAX
from util.parser import get_param_name, get_function_name, get_bitval, get_signature, get_scope_reg
from util.comgen import generate_decorator

def gen_flagisset(writer, header, function):
    callback_fn = lambda scope: gen_flagisset_body(writer, header, function, scope)
    generate_decorator(writer, function, callback_fn, variables=['u32 res'])

def gen_flagisset_body(writer, header, function, scope):
    reg = get_scope_reg(scope)
    periph = header.periph
    fn = get_function_name(function)
    signature = get_signature(function)
    bit = get_bitval(scope)

    writer.assign_reg(periph, reg=reg, value=0)
    writer.fncall(fn, signature, res='res', periph=periph, **scope.varsmap)
    writer.assert_reg_eq(val='res', exp=0)
    writer.assert_execution_status(scope.halt)

    writer.newline()

    writer.assign_reg(periph, reg=reg, value=f'{bit}')
    writer.fncall(fn, signature, res='res', periph=periph, **scope.varsmap)
    writer.assert_reg_eq(val='res', exp=bit)
    writer.assert_execution_status(scope.halt)

    writer.newline()

    writer.assign_reg(periph, reg=reg, value=f'~{bit}')
    writer.fncall(fn, signature, res='res', periph=periph, **scope.varsmap)
    writer.assert_reg_eq(val='res', exp=0)
    writer.assert_execution_status(scope.halt)

    writer.newline()

    writer.assign_reg(periph, reg=reg, value=f'{hex(INT32_MAX)}')
    writer.fncall(fn, signature, res='res', periph=periph, **scope.varsmap)
    writer.assert_reg_eq(val='res', exp=bit)
    writer.assert_execution_status(scope.halt)

    writer.newline()

