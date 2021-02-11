import json

from colorama import Fore, init
init(autoreset=True)


filename = input(Fore.BLUE + "Введите название файла с данными: ")
try:
    with open(filename, "r") as json_file:
        data = json.load(json_file)
except FileNotFoundError:
    print(Fore.RED + "Файл с данными не найден.")
    exit(-1)
states = data["states"]
alphabet = data["alphabet"]
start = data["start"]
ends = data["ends"]


def check_word(word: str, state=start) -> None:
    if word == "λ":
        print(f"({state}, {word})")
        print(f"Конечное состояние: {state}")
        if state in ends:
            print(Fore.GREEN + "Цепочка принадлежит заданному ДКА.\n")
        else:
            print(Fore.RED + "Ошибка. Конечное состояние не принадлежит множеству конечных состояний ДКА.\n")
        return

    print(f"({state}, {word})")
    if len(word) > 1:
        print(f"(δ({state},{word[0]}), {word[1:]})")
        try:
            state = states[state][word[0]]
        except KeyError:
            print(Fore.RED + "Ошибка. Отсутсвует переход для данного состояния.\n")
            return
        word = word[1:]
    else:
        print(f"(δ({state},{word[0]}), λ)")
        try:
            state = states[state][word[0]]
        except KeyError:
            print(Fore.RED + "Ошибка. Отсутсвует переход для данного состояния.\n")
            return
        word = "λ"
    check_word(word, state)


def main() -> int:
    print("Задан Детерменированный Конечный Автомат вида:")
    print(f"M({list(states.keys())}, {alphabet}, ẟ, {start}, {ends})")

    while True:
        word = input("Введите цепочку для проверки или 'quit' для выхода: ")
        if word == 'quit':
            return 0
        if all([c in alphabet for c in word]):
            print(Fore.GREEN + "Цепочка состоит только из символов алфавита, начинаю проверку...")
            check_word(word)
        else:
            print(Fore.RED + "\nОшибка. Слово состоит из символов, которых нет в алфавите.\n")


if __name__ == "__main__":
    exit(main())
