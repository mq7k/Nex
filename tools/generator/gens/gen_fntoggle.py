from util.consts import INT32_MAX
from util.comgen import generate_decorator
from util.parser import get_function_name, get_bitval, get_signature, get_scope_reg

DEFAULT_SUFFIXES = {
    'enable': '_enable',
    'disable': '_disable'
}

def gen_fntoggle(writer, header, function):
    callback_fn = lambda scope: gen_fntoggle_body(writer, header, function, scope)
    generate_decorator(writer, function, callback_fn)

def gen_fntoggle_body(writer, header, function, scope):
    reg = get_scope_reg(scope)
    periph = header.periph
    fn = get_function_name(function)
    signature = get_signature(function)
    bit = get_bitval(scope)
    suffixes = function.get('suffixes', DEFAULT_SUFFIXES)

    options = function.get('options', [])
    is_inverted = 'inverted' in options
    suf_enable = suffixes['disable'] if is_inverted else suffixes['enable']
    suf_disable = suffixes['enable'] if is_inverted else suffixes['disable']

    if 'no_set' not in options:
        writer.assign_reg(periph, reg = reg, value = 0)
        writer.fncall(f'{fn}{suf_enable}', signature, periph=periph, **scope.varsmap)

        if scope.halt:
            writer.assert_reg_eq(periph=periph, reg=reg, exp=0)
        else:
            writer.assert_reg_eq(periph=periph, reg=reg, exp=bit)

        writer.assert_execution_status(scope.halt)

        writer.newline()

        writer.assign_reg(periph, reg = reg, value = f'~{bit}')
        writer.fncall(f'{fn}{suf_enable}', signature, periph=periph, **scope.varsmap)

        if scope.halt:
            writer.assert_reg_eq(periph=periph, reg=reg, exp = f'~{bit}')
        else:
            writer.assert_reg_eq(periph=periph, reg=reg, exp = f'{hex(INT32_MAX)}')

        writer.assert_execution_status(scope.halt)

        writer.newline()

    if 'no_clear' not in options:
        writer.assign_reg(periph, reg = reg, value = f'{bit}')
        writer.fncall(f'{fn}{suf_disable}', signature, periph=periph, **scope.varsmap)

        if scope.halt:
            writer.assert_reg_eq(periph=periph, reg=reg, exp=bit)
        else:
            writer.assert_reg_eq(periph=periph, reg=reg, exp=0)

        writer.assert_execution_status(scope.halt)

        writer.newline()

        writer.assign_reg(periph, reg = reg, value = f'{hex(INT32_MAX)}')
        writer.fncall(f'{fn}{suf_disable}', signature, periph=periph, **scope.varsmap)

        if scope.halt:
            writer.assert_reg_eq(periph=periph, reg=reg, exp = f'{hex(INT32_MAX)}')
        else:
            writer.assert_reg_eq(periph=periph, reg=reg, exp = f'~{bit}')

        writer.assert_execution_status(scope.halt)

        writer.newline()
