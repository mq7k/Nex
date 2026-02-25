from util.consts import INT32_MAX
from util.comgen import generate_decorator
from util.parser import get_function_name, get_signature, get_scope_reg, parse_int

def gen_fnget(writer, header, function):
    callback_fn = lambda scope: gen_fnget_body(writer, header, function, scope)
    generate_decorator(writer, function, callback_fn, variables=['u32 res'])

def gen_fnget_body(writer, header, function, scope):
    if (not scope.shift or scope.shift == 0) and (not scope.mask or scope.mask == 0):
        # Reads the entire register
        gen_fnget_body_read_reg(writer, header, function, scope)
        return

    # Reads N bits (N < 32)
    if scope.mask and parse_int(scope.mask) == 1:
        gen_fnget_body_read_bit(writer, header, function, scope)
        return

    gen_fnget_body_read_bits(writer, header, function, scope)

def gen_fnget_body_read_reg(writer, header, function, scope):
    writer.write('// read_reg')

    reg = get_scope_reg(scope)
    periph = header.periph
    fn = get_function_name(function)
    signature = get_signature(function)

    writer.assign_reg(periph, reg=reg, value=0)
    writer.fncall(fn, signature, res='res', periph=periph, **scope.varsmap)
    writer.assert_reg_eq(val='res', exp=0)
    writer.assert_execution_status(scope.halt)

    writer.newline()

    if not scope.halt:
        writer.assign_reg(periph, reg=reg, value=f'{hex(INT32_MAX)}')
        writer.fncall(fn, signature, res='res', periph=periph, **scope.varsmap)
        writer.assert_reg_eq(val='res', exp=f'{hex(INT32_MAX)}')
        writer.assert_execution_status(scope.halt)

        writer.newline()

def gen_fnget_body_read_bit(writer, header, function, scope):
    writer.write('// read_bit')

    reg = get_scope_reg(scope)
    periph = header.periph
    fn = get_function_name(function)
    signature = get_signature(function)
    shift = scope.shift or 0
    mask = scope.mask or 0

    writer.assign_reg(periph, reg=reg, value=0)
    writer.fncall(fn, signature, res='res', periph=periph, **scope.varsmap)
    writer.assert_reg_eq(val='res', exp=0)
    writer.assert_execution_status(scope.halt)

    writer.newline()

    writer.assign_reg(periph, reg=reg, value=f'~({mask}u << {shift})')
    writer.fncall(fn, signature, res='res', periph=periph, **scope.varsmap)
    writer.assert_reg_eq(val='res', exp=0)
    writer.assert_execution_status(scope.halt)

    writer.newline()

    if not scope.halt:
        writer.assign_reg(periph, reg=reg, value=f'{mask}u << {shift}')
        writer.fncall(fn, signature, res='res', periph=periph, **scope.varsmap)
        writer.assert_reg_eq(val='res', exp=f'{mask}u << {shift}')
        writer.assert_execution_status(scope.halt)

        writer.newline()

def gen_fnget_body_read_bits(writer, header, function, scope):
    writer.write('// read_bits')

    reg = get_scope_reg(scope)
    periph = header.periph
    fn = get_function_name(function)
    signature = get_signature(function)
    shift = scope.shift or 0
    mask = scope.mask or 0

    writer.assign_reg(periph, reg=reg, value=0)
    writer.fncall(fn, signature, res='res', periph=periph, **scope.varsmap)
    writer.assert_reg_eq(val='res', exp=0)
    writer.assert_execution_status(scope.halt)

    writer.newline()

    writer.assign_reg(periph, reg=reg, value=f'~({mask}u << {shift})')
    writer.fncall(fn, signature, res='res', periph=periph, **scope.varsmap)
    writer.assert_reg_eq(val='res', exp=0)
    writer.assert_execution_status(scope.halt)

    writer.newline()

    writer.assign_reg(periph, reg=reg, value=f'{mask}u << {shift}')
    writer.fncall(fn, signature, res='res', periph=periph, **scope.varsmap)
    writer.assert_reg_eq(val='res', exp=f'{mask}')
    writer.assert_execution_status(scope.halt)

    writer.newline()
