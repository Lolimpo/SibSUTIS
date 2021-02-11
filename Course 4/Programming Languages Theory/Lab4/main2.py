#!/usr/bin/env python3

import re
import collections

from colorama import Fore, init
init(autoreset=True)

Transfer = collections.namedtuple('Transfer', ['newstate', 'newstack'])
automate = collections.defaultdict(lambda: collections.defaultdict(dict))
with open('automate.txt') as f:
    start_stack = list(f.readline().split()[-1])
    start = f.readline().split()[-1]
    end = frozenset(f.readline().split()[2:])
    for line in f:
        match = re.fullmatch(r'\s*\(\s*(\w+)\s*,\s*(\w+)\s*,\s*(\w+)\s*\)\s*=\s*\(\s*(\w+)\s*,\s*(\w+)\s*\)\s*', line)
        state, char, stackchar, newstate, newstack = match.groups()
        newstack = list(reversed(newstack)) if newstack != '_' else []
        automate[state][stackchar][char] = Transfer(newstate, newstack)


def print_step(state, seq, stack):
    print(f'δ({state},{seq if seq else "ε"},{"".join(reversed(stack)) if stack else "ε"})')


def check_word(seq) -> None:
    if (state := start) not in automate:
        print(Fore.RED + 'Ошибка! Начальное состояние не правильное.\n')
        return
    stack = start_stack.copy()
    i = 0
    while stack:
        char = seq[i] if i < len(seq) else '_'
        print_step(state, seq[i:], stack)
        top_stack = stack.pop()
        if (transition1 := automate.get(state)) is None:
            print(Fore.RED + f'Ошибка! Состояние отсутствует в таблице, переход невозможен. Слово не принадлежит ДМПА.')
            return
        if (transition2 := transition1.get(top_stack)) is None:
            print(Fore.RED + f'Ошибка! Нет такого перехода. Слово не принадлежит ДМПА.\n')
            return
        if (transition3 := transition2.get(char)) is None:
            if (transition3 := transition2.get('_')) is None:
                print(Fore.RED + f'Ошибка! Нет такого перехода. Слово не принадлежит ДМПА.\n')
                return
            else:
                i -= 1
        state = transition3.newstate
        stack.extend(transition3.newstack)
        i += 1
    print_step(state, seq[i:], stack)
    if state in end and i >= len(seq):
        print(Fore.GREEN + 'Автомат допускает цепочку\n', seq)
    elif state not in end:
        print(Fore.RED + 'Стек пуст, но автомат не пришёл в заключительное состояние!\n')
    else:
        print(Fore.RED + 'Стек пуст, автомат в заключительном состоянии, но цепочка не кончилась!\n')


if __name__ == '__main__':
    while True:
        word = input('Введите цепочку для проверки или "quit" для выхода: ')
        if word == 'quit':
            exit(0)
        print(Fore.GREEN + 'Начинаю проверку...')
        check_word(word)
