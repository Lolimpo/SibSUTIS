import re
import pprint
from math import log2


def preprocess_file(filename):
    with open(filename, 'r') as f:
        whole_file = f.read().lower().replace('\n', ' ')
        whole_file = re.sub(r'[^a-zA-Z\s]', ' ', whole_file)
    return re.sub(r'\s{2,}', ' ', whole_file)


def calc_entropy(prepared_string, symb_in_row):
    split_line = [prepared_string[i: i + symb_in_row] for i in range(0, len(prepared_string), 1)]
    symb_occur = {}
    for c in split_line:
        if c[0] == 'e':
            if c in symb_occur:
                symb_occur.update({c: symb_occur.get(c) + symb_in_row})
            else:
                symb_occur.update({c: 1})
    print(symb_occur)
    e_count = sum(symb_occur.values())
    print(e_count)

    ratio = {}
    for key, value in symb_occur.items():
        ratio.update({key: float(value) / e_count})
    print(f'Probabilities: {sorted(ratio.items())}')
    print(int(sum(ratio.values())))

    result = 0.0
    for temp in ratio.values():
        result += temp * log2(temp)
    return f'Shanon entropy: {-result / symb_in_row}'


def count_alphabet_entropy(filename: str) -> None:
    prepared_string = preprocess_file(filename)
    # print(prepared_string)
    print(f'For {2} symbols in a row: {calc_entropy(prepared_string, 2)}')


def main() -> int:
    count_alphabet_entropy('text.txt')
    return 0


if __name__ == '__main__':
    exit(main())
