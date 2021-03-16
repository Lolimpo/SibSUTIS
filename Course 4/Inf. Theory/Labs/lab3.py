import re
from math import log2


def preprocess_file(filename):
    with open(filename, 'r') as f:
        whole_file = f.read()
        whole_file = re.sub(r'(?m)\s*[/][/].*', '', whole_file)
        whole_file = re.sub(r'(?m)^\s*', '', whole_file)
        whole_file = re.sub(r'(?m).*System.out.*', '', whole_file)
        return re.sub(r'^(?:[\t ]*(?:\r?\n|\r))+', '', whole_file)


def calc_entropy(prepared_string, symb_in_row):
    split_line = [prepared_string[i: i + symb_in_row] for i in range(0, len(prepared_string), symb_in_row)]
    symb_occur = {}
    for c in split_line:
        if c in symb_occur:
            symb_occur.update({c: symb_occur.get(c) + symb_in_row})
        else:
            symb_occur.update({c: 1})

    ratio = {}
    for key, value in symb_occur.items():
        ratio.update({key: float(value) / len(prepared_string)})
    print(f'Probabilities: {sorted(ratio.items())}')

    result = 0.0
    for temp in ratio.values():
        result += temp * log2(temp)
    return f'Shanon entropy: {-result / symb_in_row}'


def count_alphabet_entropy(filename: str) -> None:
    prepared_string = preprocess_file(filename)
    print(prepared_string)
    for i in range(1, 3):
        print(f'For {i} symbols in a row: {calc_entropy(prepared_string, i)}')


def main() -> int:
    count_alphabet_entropy('Main.java')
    return 0


if __name__ == '__main__':
    exit(main())
