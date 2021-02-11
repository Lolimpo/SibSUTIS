from lab2 import *


# ♠ ♣ ♥ ♦ S - пики, C - трефы, H - червы, D - бубны


def gen_deck() -> dict:
    suits = ['S', 'C', 'H', 'D']
    faces = ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A']

    cards = []
    for suit in suits:
        for face in faces:
            cards.append(str(suit + face))
    return {i: cards[i - 2] for i in range(2, 54)}


def main() -> int:
    while True:
        try:
            n = int(input("Enter number of players: "))
            if not 0 < n < 24:
                raise Exception('Wrong players num.')
            break
        except Exception as e:
            print(e)

    origin_deck = gen_deck()
    deck_keys = list(origin_deck.keys())
    random.shuffle(deck_keys)
    deck = {key: origin_deck[key] for key in deck_keys}

    while True:
        q = get_prime(0, 10 ** 9)
        p = 2 * q + 1
        if is_prime(p) and is_prime(q):
            break

    C = list()
    D = list()
    deck_keys = list(deck.keys())
    for _ in range(n):
        c = get_coprime(p - 1)
        d = extended_euclidean_algorithm(c, p - 1)[1]
        if d < 0:
            d += (p - 1)
        deck_keys = [pow_mod(i, c, p) for i in deck_keys]
        random.shuffle(deck_keys)
        print(deck_keys)
        C.append(c)
        D.append(d)

    hands = list()
    for i in range(n):
        hands.append([])
        for j in range(2):
            card = deck_keys[j]
            deck_keys.remove(card)
            hands[i].append(card)
    print(hands)

    table = deck_keys[:5]
    print(table)

    for i in range(n):
        table = [pow_mod(table[j], D[i], p) for j in range(len(table))]
    table = {key: deck[key] for key in table}
    print(f'Cards on the table: {list(table.values())}')

    for i in range(n):
        for j in range(n):
            if i != j:
                v = 0
                while v < len(hands[0]):
                    hands[i][v] = pow_mod(hands[i][v], D[j], p)
                    v += 1
        v = 0
        while v < len(hands[0]):
            hands[i][v] = pow_mod(hands[i][v], D[i], p)
            v += 1
    hands = [{key: deck[key] for key in hand} for hand in hands]
    for i in range(n):
        print(f'Player {i + 1} has cards: {list(hands[i].values())}')

    return 0


if __name__ == '__main__':
    exit(main())
