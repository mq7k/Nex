def gen_setupfn(writer, periph, struct):
    if periph.startswith('_'):
        writer.write(f'volatile struct {struct}* {periph};')

    writer.newline()

    writer.write('void')
    writer.write('setup(void)')

    writer.open_bracket()
    writer.write(f'{periph} = (struct {struct}*) membuf;')
    writer.close_bracket()
    
    writer.newline()
