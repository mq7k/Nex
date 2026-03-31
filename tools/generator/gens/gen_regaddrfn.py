def gen_regaddrfn(writer, struct, regs):
    writer.write('void')
    writer.write('test_reg_addr(void)')
    writer.open_bracket()

    for entry in regs:
        if 'ifdef' in entry:
            writer.ifdef(entry['ifdef'])

        name = entry['name']
        offset = entry['offset']
        s = entry.get('struct', struct)
        writer.write(f'ASSERT_ADDR(struct {s}, {name}, {offset}lu);')

        if 'ifdef' in entry:
            writer.endif()

    writer.close_bracket()
    writer.newline()
