from main import extended_euclidean_algorithm, giant_baby_step, pow_mod, diffie_hellman_algorithm
import random

if __name__ == '__main__':
    base = random.randint(0, 10 ** 9)
    exp = random.randint(0, 10 ** 9)
    module = random.randint(0, 10 ** 9)
    print(f"ModPow:\n{base} ^ {exp} mod {module} = {pow_mod(base, exp, module)}\n")

    a = random.randint(0, 10**9)
    b = random.randint(0, 10**9)
    eea_result = extended_euclidean_algorithm(a, b)
    print(
        f"Extended Euclidean Algorithm:\n"
        f"GCD({a}, {b}) = {eea_result[0]}\nx = {eea_result[1]}\ny = {eea_result[2]}\n"
    )

    Bob, Alice = diffie_hellman_algorithm()
    print(
        "Diffie-Hellman:\n" "Zab == Zba - everything is ok!\n"
        if Bob == Alice
        else "Zab != Zba - something went wrong! :c\n"
    )

    print("Giant/Baby step:\n")
    while True:
        a = random.randint(0, 10**9)
        p = random.randint(0, 10**9)
        y = random.randint(0, 10**9)
        x = giant_baby_step(a, p, y)
        print(f"{a}^x mod {p} = {y}\nx = {x}\n")
        if x:
            break
