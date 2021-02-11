import hashlib
from math import ceil
from sys import byteorder

from Lab2.lab2 import *


voting_options = {"No": 0, "Yes": 1}


def inverse(n: int, p: int) -> int:
    inv = extended_euclidean_algorithm(n, p)[1]
    return inv


def my_sha(n: int) -> int:
    return int.from_bytes(hashlib.sha3_256(n.to_bytes(ceil(n.bit_length() / 8), byteorder=byteorder)).digest(),
                          byteorder=byteorder)


class Server:
    def __init__(self):
        print(f'Сервер1 начал работу')
        while p := random.getrandbits(1024):
            if is_prime(p):
                break
        while q := random.getrandbits(1024):
            if is_prime(q):
                break
        assert p != q
        self.N = p * q
        phi = (p - 1) * (q - 1)
        self.d = get_coprime(phi)
        self.c = extended_euclidean_algorithm(self.d, phi)[1]
        while self.c < 0:
            self.c += phi
        self.voted = set()
        print(f'Сервер1 завершил работу')


def vote(name: str, choice: str) -> None:
    print(f'\n#{name} голосует#')
    rnd = random.getrandbits(512)
    v = voting_options[choice]
    n = rnd << 512 | v
    r = get_coprime(server.N)
    h = my_sha(n)
    _h = h * pow_mod(r, server.d, server.N) % server.N
    if name in server.voted:
        return print(f'Голос от избирателя {name} уже есть.')
    else:
        server.voted.add(name)
        _s = pow_mod(_h, server.c, server.N)
    s = _s * inverse(r, server.N) % server.N

    print(f'#Ответ сервера-голосования#')
    blanks = set()
    if my_sha(n) == pow_mod(s, server.d, server.N):
        print(f'Голос принят.')
        blanks.add((n, s))
    else:
        print(f'Голос отклонен')
        print(my_sha(n))
        print(pow_mod(s, server.d, server.N))


if __name__ == '__main__':
    server = Server()
    vote("Alice", "Yes")
    vote("Bob", "No")
    vote("Bob", "Yes")
    vote("Alice", "No")
