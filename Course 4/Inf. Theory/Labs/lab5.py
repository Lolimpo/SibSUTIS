import re
from dataclasses import dataclass
from math import log2, ceil


def preprocess_file(filename: str) -> str:
    with open(filename, 'r') as f:
        whole_file = f.read().lower().replace('\n', ' ')
        whole_file = re.sub(r'[^a-zA-Z\s]', ' ', whole_file)
    return re.sub(r'\s{2,}', ' ', whole_file)


def calc_entropy(prepared_string, symb_in_row):
    split_line = [prepared_string[i: i + symb_in_row] for i in range(len(prepared_string) - symb_in_row + 1)]
    symb_occur = {}
    for c in split_line:
        if c in symb_occur:
            symb_occur.update({c: symb_occur.get(c) + symb_in_row})
        else:
            symb_occur.update({c: 1})

    ratio = {}
    for key, value in symb_occur.items():
        ratio.update({key: float(value) / len(prepared_string)})
    # (f'Probabilities: {sorted(ratio.items())}')

    result = -sum(x * log2(x) for x in ratio.values())
    return result / symb_in_row


def shanon_code(text: str):
    split_line = [text[i: i + 1] for i in range(len(text) - 1 + 1)]
    symb_occur = {}
    for c in split_line:
        if c in symb_occur:
            symb_occur.update({c: symb_occur.get(c) + 1})
        else:
            symb_occur.update({c: 1})
    symb_occur = list(symb_occur.items())
    symb_occur.sort(key=lambda x: x[1], reverse=True)
    symb_occur = {k: v for k, v in symb_occur}
    # print(symb_occur)

    probabilities = {k: v / len(text) for k, v in symb_occur.items()}
    # print(probabilities)

    l = [ceil(-log2(i)) for i in probabilities.values()]
    # print(l)

    cumulative_probs = [float(0) for _ in range(len(probabilities))]
    for i in range(1, len(probabilities)):
        cumulative_probs[i] = cumulative_probs[i - 1] + list(probabilities.values())[i - 1]
    # print(cumulative_probs)

    res = list('' for _ in range(len(l)))
    for i in range(len(cumulative_probs)):
        k = 1/3
        p = 1/9
        for j in range(l[i]):
            if cumulative_probs[i] > k:
                res[i] += '1'
                k += p
            elif 2 * k > cumulative_probs[i] > k:
                res[i] += '0'
                k -= p
            p /= 3
        print(f'{list(probabilities.keys())[i]}: {list(probabilities.values())[i]:.4f} - {res[i]}')

    l_average = sum(list(probabilities.values())[i] * l[i] for i in range(len(probabilities.items())))
    print(l_average)

    with open('coded_text.txt', 'w') as f:
        for i in text:
            index = list(probabilities.keys()).index(i)
            f.write(res[index])

    with open('coded_text.txt', 'r') as f:
        print(calc_entropy(f.readline(), 1))
    return l_average


def main() -> int:
    text = preprocess_file('text.txt')
    orig_entropy = calc_entropy(text, 1)
    print('Original text:', orig_entropy)
    print('r =', shanon_code(text) - orig_entropy)
    return 0


if __name__ == '__main__':
    exit(main())
