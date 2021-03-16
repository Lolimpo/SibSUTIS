import random
from math import log2


def create_file(alphabet, filename, symbols_num):
    symbols = list(alphabet.keys())
    weights = list(alphabet.values())
    with open(filename, 'w') as f:
        for i in range(symbols_num):
            f.write(''.join(random.choices(symbols, weights)))


def calc_entropy(filename, symb_in_row):
    with open(filename, 'r') as f:
        line = f.read()
    split_line = [line[i: i + symb_in_row] for i in range(0, len(line), symb_in_row)]

    symb_occur = {}
    for c in split_line:
        if c in symb_occur:
            symb_occur.update({c: symb_occur.get(c) + symb_in_row})
        else:
            symb_occur.update({c: 1})

    ratio = {k: v / len(line) for k, v in symb_occur.items()}
    print(f'Probabilities: {sorted(ratio.items())}')

    result = -sum(x * log2(x) for x in ratio.values())

    return f'Shanon entropy: {result / symb_in_row}'


def count_alphabet_entropy(alphabet: dict[str, float], filename: str, symbols_num: int) -> None:
    create_file(alphabet, filename, symbols_num)
    print(f'Alphabet: {alphabet}')
    for i in range(1, 3):
        print(f'For {i} symbols in a row: {calc_entropy(filename, i)}')
    print()


def main() -> int:
    equal_prob = {'a': 0.25, 'b': 0.25, 'c': 0.25, 'd': 0.25}
    diff_prob = {'a': 0.5, 'b': 0.2, 'c': 0.2, 'd': 0.1}

    count_alphabet_entropy(equal_prob, 'equal_prob.txt', 50000)
    count_alphabet_entropy(diff_prob, 'diff_prob.txt', 50000)
    return 0


if __name__ == '__main__':
    exit(main())
