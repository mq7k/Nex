from util.testwriter import TestWriter

def gen_preprocessor(writer: TestWriter, path: str):
    writer.write('#include "libcom/util.h"')
    writer.write('#include "libcom/types.h"')

    writer.newline()

    writer.write(f'#include "synapse/{path}"')
    writer.write('#include "libtest/libtest.hpp"')

    writer.newline()
