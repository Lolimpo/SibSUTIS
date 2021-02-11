import json
from collections import deque

from colorama import Fore, init
init(autoreset=True)


filename = input(Fore.BLUE + 'Введите название файла с данными: ')
try:
    with open(filename + '.json', 'r') as file:
        data = json.load(file)
except FileNotFoundError:
    print(Fore.RED + 'Ошибка! Файл с данными не найден.')
    exit(-1)
states = data["states"]
alphabet = data["alphabet"]
stack_al = data["stack_al"]
start = data["start"]
stack = deque(data["stack"])
ends = data["ends"]


def check_word(word: str) -> None:
    global start, stack
    stack = deque(data["stack"])
    start = data["start"]
    print(f'δ({start}, {word}, {list(stack)})')
    while stack:
        if len(word) == 0:
            word = 'e'
        if word[0] not in alphabet and word[0] != 'e':
            try:
                if stack[0] in states[start]['e']:
                    stack.popleft()
                    print(f'δ({start}, {word if word else "ε"}, {"".join(stack) if stack else "ε"})')
                    continue
            except KeyError:
                print(Fore.RED + 'Ошибка. Слово состоит из символов, '
                                 'не принадлежащих алфавиту и лямбда-такты невозможны.\n')
                return
        if word[0] in states[start]:
            try:
                if stack[0] in states[start][word[0]]:
                    if states[start][word[0]][stack[0]][1][0] != 'e':
                        stack.appendleft(states[start][word[0]][stack[0]][1][0])
                        start = states[start][word[0]][stack[0]][0]
                        word = word[1:]
                        print(f'δ({start}, {word}, {"".join(stack) if stack else "ε"})')
                    else:
                        start = states[start][word[0]][stack[0]][0]
                        stack.popleft()
                        word = word[1:]
                        print(f'δ({start}, {word if word else "ε"}, {"".join(stack) if stack else "ε"})')
                else:
                    print(Fore.RED + 'Ошибка. Нет такого перехода. Слово не принадлежит ДМПА.\n')
                    return
            except IndexError or KeyError:
                print(Fore.RED + 'Ошибка. Нет такого перехода. Слово не принадлежит ДМПА.\n')
                return
        else:
            print(Fore.RED + 'Ошибка. Нет такого перехода. Слово не принадлежит ДМПА.\n')
            return
    if start in ends and not len(word):
        print(Fore.GREEN + 'Слово принадлежит данному ДМПА.\n')
    elif start not in ends:
        print(Fore.RED + 'Ошибка. '
                         'Слово кончилось и стэк пустой, '
                         'но конечное состояние не принадлежит множеству конечных состояний.\n')
    else:
        print(Fore.RED + 'Ошибка! Стек пуст, автомат в заключительном состоянии, но цепочка не кончилась!\n')
    return


def main() -> int:
    print('Задан Детерминированный Автомат с Магазинной Памятью вида:')
    print(f'P = ({list(states)}, {alphabet}, {stack_al}, δ, {start}, {list(stack)}, {ends})')

    while True:
        word = input('Введите цепочку для проверки или "quit" для выхода: ')
        if word == 'quit':
            return 0
        print(Fore.GREEN + 'Начинаю проверку...')
        check_word(word if word else 'e')


if __name__ == '__main__':
    exit(main())
