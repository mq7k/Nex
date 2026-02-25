def gen_setupfn(writer, periph, struct):
    writer.write('void')
    writer.write('setup(void)')

    writer.open_bracket()
    writer.write(f'{periph} = (struct {struct}*) membuf;')
    writer.close_bracket()
    
    writer.newline()
