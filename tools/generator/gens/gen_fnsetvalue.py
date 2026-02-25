from util.consts import INT32_MAX
from gens.common import generate_args_combinations
from util.comgen import generate_decorator
from util.parser import get_param_name, get_function_name, get_bitval, get_signature, get_scope_reg, parse_int

def gen_fnsetvalue(writer, header, function):
    if 'args' not in function:
        function['args'] = {}

    if 'val' not in function['args']:
        values = []
        values.append({ 'value': 0 })
        mask = parse_int(function.get('mask', str(INT32_MAX)))

        if mask != INT32_MAX:
            values.append({ 'value': function['mask'] })
            values.append({ 'value': hex(parse_int(function['mask']) + 1), 'halt': True })

        function['args']['val'] = values

    callback_fn = lambda scope: gen_fnsetvalue_body(writer, header, function, scope)
    generate_decorator(writer, function, callback_fn)

def gen_fnsetvalue_body(writer, header, function, scope):
    reg = get_scope_reg(scope)
    periph = header.periph
    fn = get_function_name(function)
    signature = get_signature(function)
    shift = scope.shift or 0
    mask = scope.mask or 0

    value = scope.varsmap['val']
    writer.assign_reg(periph, reg=reg, value=0)
    writer.fncall(fn, signature, periph=periph, **scope.varsmap)

    if not scope.halt or 1:
        writer.assert_reg_eq(periph=periph, reg=reg, exp=f'{value}u << {shift}')
    else:
        writer.assert_reg_eq(periph=periph, reg=reg, exp=0)

    writer.assert_execution_status(scope.halt)

    writer.newline()

    options = function.get('options', [])
    if 'ioreg' in options and parse_int(mask) != INT32_MAX:
        return

    writer.assign_reg(periph, reg=reg, value=f'{hex(INT32_MAX)}')
    writer.fncall(fn, signature, periph=periph, **scope.varsmap)

    if mask == 0:
        writer.assert_reg_eq(periph=periph, reg=reg, exp=value)
    else:
        m = f'~({mask}u << {shift})'
        v = f'({value}u << {shift})'
        writer.assert_reg_eq(periph=periph, reg=reg, exp=f'{m} | {v}')

    # if not scope.halt:
    #     m = f'~({mask}u << {shift})'
    #     v = f'({value}u << {shift})'
    #     writer.assert_reg_eq(periph=periph, reg=reg, exp=f'{m} | {v}')
    # else:
    #     writer.assert_reg_eq(periph=periph, reg=reg, exp=f'{mask}u << {shift}')

    writer.assert_execution_status(scope.halt)

    writer.newline()
