import random
from math import sqrt, ceil


def is_prime(n):
    if n < 2:
        return False
    return all(n % i for i in range(2, int(sqrt(n)) + 1))


def pow_mod(base, exp, module):
    result = 1
    base %= module

    if not base:
        return 0

    while exp > 0:
        if exp & 1 == 1:
            result = (result * base) % module
        exp >>= 1
        base = (base ** 2) % module

    return result


def extended_euclidean_algorithm(a, b):
    u = [a, 1, 0]
    v = [b, 0, 1]
    while v[0] != 0:
        q = u[0] // v[0]
        t = [u[0] % v[0], u[1] - q * v[1], u[2] - q * v[2]]
        u, v = v, t
    return u


def diffie_hellman_algorithm():
    q, p, g, Xa, Xb = 0, 0, 0, 0, 0

    print("Generated:")
    while not (is_prime(p) and is_prime(q)):
        q = random.randint(0, 10 ** 9)
        p = 2 * q + 1
    print(f"q = {q}\np = {p}")

    while pow_mod(g, q, p) != 1:
        g = random.randint(1, p - 1)
    print(f"g = {g}\n")

    while not (is_prime(Xa) and is_prime(Xb)):
        Xa = random.randint(1, p)
        Xb = random.randint(1, p)
    print(f"Secret keys:\nXa = {Xa}\nXb = {Xb}\n")

    Ya = pow_mod(g, Xa, p)
    Yb = pow_mod(g, Xb, p)
    print(f"Open Keys:\nYa = {Ya}\nYb = {Yb}")

    Zab = pow_mod(Yb, Xa, p)
    Zba = pow_mod(Ya, Xb, p)
    print(f"Zab = {Zab}\nZba = {Zba}\n")
    return Zab, Zba


def giant_baby_step(a, p, y):
    k = m = ceil(sqrt(p + 1))

    baby = {pow_mod(a, j, p) * y % p: j for j in range(m)}
    giant = [pow_mod(a, (m * i), p) for i in range(1, k + 1)]

    for i, el in enumerate(giant, 1):
        if (j := baby.get(el)) is not None:
            return i * m - j
    return None


if __name__ == "__main__":
    print(f"ModPow:\n3 ^ 100 mod 7 = {pow_mod(3, 100, 7)}\n")

    eea_result = extended_euclidean_algorithm(69, 42)
    print(
        f"Extended Euclidean Algorithm:\n"
        f"GCD(69, 42) = {eea_result[0]}\nx = {eea_result[1]}\ny = {eea_result[2]}\n"
    )

    Bob, Alice = diffie_hellman_algorithm()
    print(
        "Diffie-Hellman:\n" "Zab == Zba - everything is ok!\n"
        if Bob == Alice
        else "Zab != Zba - something went wrong! :c\n"
    )

    print(f"Giant/Baby step:\n6^x mod 17 = 15\nx = {giant_baby_step(6, 17, 15)}\n")
