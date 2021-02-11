from dataclasses import dataclass
from typing import Dict, List


@dataclass
class Grammar:
    """Class to keep grammar in."""
    VT: List[str]
    VN: List[str]
    P: Dict[str, List[str]]
    S: str


def data_input():
    result = dict()
    VT = list(map(str, input("Enter terminals: ").split()))
    result["VT"] = VT
    VN = list(map(str, input("Enter non-terminals: ").split()))
    result["VN"] = VN
    n = int(input("Enter number of rules: "))
    P = dict()
    for _ in range(n):
        r = input("Enter rule terminal: ")
        rs = input("Enter rule:").split()
        P[r] = rs
    S = str(input("Enter leading symbol: "))
    return {"VT": VT, "VN": VN, "P": P, "S": S}


data = {"VT": ["0", "1", "2"], "VN": ["A", "B", "C"], "P": {"A": ["aBbbC"], "B": ["aaBb", ""], "C": ["cC", ""]}, "S": "A"}
# data = data_input()
left_border, right_border = map(int, input("Enter words size FROM TO\n").split())


if __name__ == '__main__':
    grammar = Grammar(data["VT"], data["VN"], data["P"], data["S"])
    print(grammar)
    rules = list(grammar.S)
    used_seq = set()
    while rules:
        sequence = rules.pop()
        if sequence in used_seq:
            continue
        used_seq.add(sequence)
        only_term = True
        for i, symbol in enumerate(sequence):
            if symbol in grammar.VN:
                only_term = False
                for elem in grammar.P[symbol]:
                    temp = sequence[:i] + elem + sequence[i + 1:]
                    if len(temp) <= right_border + 1:
                        rules.append(temp)
        if only_term and left_border <= len(sequence) <= right_border:
            print(sequence if sequence else "lam")
