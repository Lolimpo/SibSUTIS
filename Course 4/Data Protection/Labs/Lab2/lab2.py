import json
from math import gcd

from Lab1.lab1 import *

keys = {}


def get_coprime(num: int) -> int:
    res = random.getrandbits(1024)
    while gcd(num, res) != 1:
        res = random.getrandbits(1024)
    return res


def shamir_encode(m: bytearray) -> list:
    keys['shamir'] = []
    res = list()

    p = get_prime(0, 10 ** 9)

    Ca = get_coprime(p - 1)
    Da = extended_euclidean_algorithm(p - 1, Ca)[2]
    if Da < 0:
        Da += (p - 1)

    Cb = get_coprime(p - 1)
    Db = extended_euclidean_algorithm(p - 1, Cb)[2]
    if Db < 0:
        Db += (p - 1)

    for part in m:
        x1 = pow_mod(part, Ca, p)
        x2 = pow_mod(x1, Cb, p)
        x3 = pow_mod(x2, Da, p)
        res.append(x3)

    keys['shamir'].append({'p': p, 'Ca': Ca, 'Da': Da, 'Cb': Cb, 'Db': Db})
    return res


def shamir_decode(x3: list) -> list:
    res = list()
    with open('keys.json') as keys_file:
        data = json.load(keys_file)
        for key in data['shamir']:
            p = key['p']
            Db = key['Db']

    for part in x3:
        x4 = pow_mod(part, Db, p)
        res.append(x4)
    return res


def elgamal_encode(m: bytearray) -> list:
    keys['Elgamal'] = []
    res = list()

    g = 0
    while True:
        q = get_prime(0, 10 ** 9)
        p = 2 * q + 1
        if is_prime(p) and is_prime(q):
            break

    while pow_mod(g, q, p) != 1:
        g = random.randint(1, p - 1)
    print(f'Q = {q}')
    print(f'P = {p}')
    print(f'g = {g}')
    x = random.randint(1, p)
    y = pow_mod(g, x, p)

    k = random.randint(1, p - 1)

    a = pow_mod(g, k, p)
    for m_part in m:
        b = m_part * pow_mod(y, k, p)
        res.append(b)

    keys['Elgamal'].append({'g': g, 'p': p, 'x': x, 'y': y, 'k': k, 'a': a})
    return res


def elgamal_decode(b: list) -> list:
    res = list()
    with open('keys.json') as keys_file:
        data = json.load(keys_file)
        for key in data['Elgamal']:
            p = key['p']
            x = key['x']
            a = key['a']

    for el in b:
        res.append(el * pow_mod(a, p - 1 - x, p) % p)
    return res


def vernam_encode(m: bytearray) -> list:
    keys['vernam'] = []

    codes = [random.randint(0, 255) for _ in range(len(m))]

    keys['vernam'].append(codes)
    return [m[i] ^ codes[i] for i in range(len(m))]


def vernam_decode(m: list) -> list:
    with open('keys.json') as keys_file:
        data = json.load(keys_file)
        codes = data['vernam'][0]

    return [m[i] ^ codes[i] for i in range(len(m))]


def rsa_encode(m: bytearray) -> list:
    keys['rsa'] = []
    res = list()

    p = get_prime(0, 10 ** 9)
    q = get_prime(0, 10 ** 9)

    n = p * q

    phi = (p - 1) * (q - 1)

    d = get_coprime(phi)
    c = extended_euclidean_algorithm(d, phi)[1]
    if c < 0:
        c += phi

    for m_part in m:
        e = pow_mod(m_part, d, n)
        res.append(e)
    keys['rsa'].append({'p': p, 'q': q, 'n': n, 'phi': phi, 'd': d, 'c': c})
    return res


def rsa_decode(e: list) -> list:
    res = list()
    with open('keys.json') as keys_file:
        data = json.load(keys_file)
        for key in data['rsa']:
            n = key['n']
            c = key['c']

    for el in e:
        res.append(pow_mod(el, c, n))
    return res
