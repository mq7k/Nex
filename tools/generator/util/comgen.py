from util.scope import Scope, ScopeStack
from util.guard import ScopeGuard
from gens.common import generate_args_combinations
from util.parser import get_test_fn_name

def generate_decorator(writer, function, callback_fn, variables=None):
    fn = function['fn']
    test_fn = get_test_fn_name(function)
    reg = function.get('reg')

    ss = ScopeStack()
    btm_scope = ss.push_scope()
    btm_scope.shift = function.get('shift')
    btm_scope.mask = function.get('mask')
    btm_scope.reg = reg
    btm_scope.ifdef = function.get('ifdef', [])
    btm_scope.value = function.get('value', 1)

    if isinstance(btm_scope.ifdef, str):
        btm_scope.ifdef = [ btm_scope.ifdef ]

    with ScopeGuard(writer, btm_scope):
        writer.fndecl(test_fn)
        writer.open_bracket()

        if variables:
            for var in variables:
                writer.write(f'{var};')

            writer.newline()

        args = function.get('args')

        if args:
            for scope in generate_args_combinations(args, ss):
                with ScopeGuard(writer, scope):
                    callback_fn(scope)
        else:
            callback_fn(btm_scope)
        
        writer.close_bracket()

