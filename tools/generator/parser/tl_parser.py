import sys

def tokenize(content):
    arr = []

    quotes = None
    reading_text = False
    text = ''
    comment = False
    for c in content:
        if comment and c != '\n':
            continue

        print(f'{c=}')
        match c:
            case '{':
                print('Open Curly')
                arr.append({ 'type': 'OPEN_CURLY' })
            case '}':
                print('Close Curly')
                arr.append({ 'type': 'CLOSE_CURLY' })
            case '[':
                print('Open Square')
                arr.append({ 'type': 'OPEN_SQUARE' })
            case ']':
                print('Close Square')
                arr.append({ 'type': 'CLOSE_SQUARE' })
            case '\'' | '"':
                if not quotes:
                    print('Open quotes')
                    quotes = c
                else:
                    arr.append({'type': 'LITERAL', 'value': text})
                    text = ''
                    quotes = None
                    print('Close quotes')
            case ' ' | '\t':
                if quotes or reading_text:
                    text += c
                    print('Appending char (1)')
            case '\n':
                if reading_text:
                    arr.append({'type': 'LITERAL', 'value': text})
                    text = ''
                    reading_text = False
                    print('New line')
            case '#':
                if not quotes:
                    comment = True
                    print('Comment')
            case _:
                reading_text = True
                text += c
                print('Appending char (2)')

    return arr

def parse_tl_file(text):
    tokens = tokenize(text)
    return tokens

def main():
    with open(sys.argv[1], 'r') as file:
        c = file.read()
        root = parse_tl_file(c)
        print(root)
        print(c)

if __name__ == '__main__':
    main()
