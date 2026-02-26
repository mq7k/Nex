from util.parser import get_test_fn_name

def gen_mainfn(writer, functions):
    writer.write('int')
    writer.write('main(void)')

    writer.open_bracket()

    if len(functions) == 0:
        writer.write('return 0;')
    else:
        writer.write('const test_function_t tests[] =')
        writer.open_bracket()

        for function in functions:
            if 'ifdef' in function:
                macros = function['ifdef']
                writer.ifdef(macros)

            if 'ifndef' in function:
                macros = function['ifndef']
                writer.ifndef(macros)

            test_fn = get_test_fn_name(function)
            writer.write(f'TEST_FUNC({test_fn}),')
            if 'ifdef' in function:
                writer.endif()
            if 'ifndef' in function:
                writer.endif()

        writer.close_bracket(newline=False)
        writer.write(';', skip_indent=True)

        writer.newline()
        writer.write('return TESTS_RUN(tests);')

    writer.close_bracket()
