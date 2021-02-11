import hashlib

from Lab2.lab2 import *


def elgamal_sign(m: bytearray) -> bool:
    g = 0
    while True:
        q = get_prime(0, 10 ** 9)
        p = 2 * q + 1
        if is_prime(p) and is_prime(q):
            break

    while pow_mod(g, q, p) != 1:
        g = random.randint(1, p - 1)

    x = random.randint(1, p)
    y = pow_mod(g, x, p)

    h = hashlib.md5(m).hexdigest()
    print(f'Elgamal md5 hash: {h}')

    k = random.randint(1, p - 1)
    while extended_euclidean_algorithm(p - 1, k)[0] != 1:
        k = random.randint(1, p)
    r = pow_mod(g, k, p)

    u = [(int(i, 16) - x * r) % (p - 1) for i in h]
    s = [(extended_euclidean_algorithm(k, p - 1)[1] * i) % (p - 1) for i in u]
    res = ''.join(str(pow_mod(y, r, p) * pow_mod(r, i, p) % p) for i in s)

    h_b = ''.join(str(pow_mod(g, int(i, 16), p)) for i in h)

    with open(r'signs\elgamal_sign.txt', 'w') as f:
        f.write(h_b)
        f.write('\n' + res)

    return res == h_b


def rsa_sign(m: bytearray) -> bool:
    p = get_prime(0, 10 ** 9)
    q = get_prime(0, 10 ** 9)

    n = p * q

    phi = (p - 1) * (q - 1)

    d = get_coprime(phi)
    c = extended_euclidean_algorithm(d, phi)[1]
    if c < 0:
        c += phi

    h = hashlib.md5(m).hexdigest()
    print(f'RSA md5 hash: {h}')
    s = [pow_mod(int(i, 16), c, n) for i in h]
    e = ''.join(str(pow_mod(i, d, n)) for i in s)

    h_b = ''.join(str(int(i, 16)) for i in h)

    with open(r'signs\rsa_sign.txt', 'w') as f:
        f.write(h_b)
        f.write('\n' + e)

    return e == h_b


def gost_sign(m: bytearray) -> bool:
    q = random.getrandbits(256)
    b = random.getrandbits(20)
    while not is_prime(q * b + 1):
        b = random.getrandbits(20)
        p = q * b + 1

    g = random.randint(1, p - 1)
    a = pow_mod(g, b, p)
    while a < 2:
        g = random.randint(1, p - 1)
        a = pow_mod(g, b, p)

    x = random.randint(0, q)
    y = pow_mod(a, x, p)

    h = hashlib.md5(m).hexdigest()
    print(f'GOST md5 hash: {h}')
    h = int(h, 16)

    k = random.randint(0, q)
    r = pow_mod(a, k, p) % q
    s = (k * h + x * r) % q
    while s == 0:
        k = random.randint(0, q)
        r = pow_mod(a, k, p) % q
        s = (k * h + x * r) % q

    temp = extended_euclidean_algorithm(h, q)[1]
    if temp < 1:
        temp += q

    u1 = (s * temp) % q
    u2 = (-r * temp) % q
    v = ((pow_mod(a, u1, p) * pow_mod(y, u2, p)) % p) % q

    with open(r'signs\GOST_sign.txt', 'w') as f:
        f.write(str(v))
        f.write('\n' + str(r))

    return v == r
