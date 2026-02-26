import sys

from .parser import apply_args

class TestWriter:
    def __init__(self, *, indent_len=2, indent_char=' ', outfile=sys.stdout):
        self.indent_len = indent_len
        self.cur_indent = 0
        self.indent_char = indent_char
        self.outfile = outfile

    def indent(self):
        self.cur_indent += self.indent_len 

    def deindent(self):
        self.cur_indent -= self.indent_len

    def open_bracket(self, newline=True):
        self.write('{', newline=newline)
        self.indent()

    def close_bracket(self, newline=True):
        self.deindent()
        self.write('}', newline=newline)

    def newline(self):
        print(file=self.outfile)

    def assign_reg(self, periph, reg, value):
        self.write(f'{periph}->{reg} = {value};')

    def assert_reg_eq(self, *, periph=None, reg=None, exp, val=None):
        if val:
            self.write(f'ASSERT_EQ({val}, {exp});')
        else:
            self.write(f'ASSERT_EQ({periph}->{reg}, {exp});')

    def assert_execution_status(self, should_halt):
        if should_halt:
            self.assert_execution_halted()
            self.execution_resume()
        else:
            self.assert_execution_running()

    def assert_execution_running(self):
        self.write('ASSERT_FALSE(execution_halted());')

    def assert_execution_halted(self):
        self.write('ASSERT_TRUE(execution_halted());')

    def execution_resume(self):
        self.write('execution_resume();')

    def fndecl(self, name):
        self.write('void')
        self.write(f'{name}(void)')

    def fncall(self, fn, signature, *, res=None, **kargs):
        # for key, value in kargs.items():
        #     signature = signature.replace(f'{{{key}}}', f'{value}')

        signature = apply_args(signature, **kargs)
        text = f'{fn}({signature});'
        if res:
            text = f'{res} = {text}'

        self.write(text)

    def ifdef(self, macros):
        if isinstance(macros, str):
            macros = [ macros ]

        macros = [ f'defined({item})' for item in macros ]
        fmt_str = ' && '.join(macros)
        self.write(f'#if {fmt_str}')

    def ifndef(self, macros):
        if isinstance(macros, str):
            macros = [ macros ]

        macros = [ f'!defined({item})' for item in macros ]
        fmt_str = ' && '.join(macros)
        self.write(f'#if {fmt_str}')

    def endif(self):
        self.write('#endif')

    def write(self, text, skip_indent=False, newline=True):
        if not text.startswith('#') and not skip_indent:
            print(self.indent_char * self.cur_indent, end='', file=self.outfile)
        print(text, file=self.outfile, end='\n' if newline else '')
