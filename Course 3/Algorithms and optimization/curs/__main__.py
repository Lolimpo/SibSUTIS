import math
from fractions import Fraction

task = [list(map(Fraction, line.split())) for line in
        open(r"C:\Users\Lolimpo\PycharmProjects\aivmo\curs\input.txt")]  # Input file read


def column(matrix, i):
    """Get column from matrix"""
    return [row[i] for row in matrix]


def print_table(table, n, m):
    """Print Simplex Table of current state"""
    print(f"{1:11}|", end='')
    for i in range(m - 1):
        print(f"{'X' + str(i + 1):>8}|", end='')
    print('\n====================================================================================')
    for i in range(n):
        if i < n - 2:
            print(f"X{basis[i] + 1}|", end='')
        elif i == n - 2:
            print(f"M |", end='')
        else:
            print(f"Z |", end='')
        for j in range(m):
            print(f"{str(table[i][j]):>8}|", end='')
        print()
    print("====================================================================================")


def estimates_in_tables(table, basis, Z, M, n, m):
    """Count and place Z and M"""
    for i in range(m):
        sumZ = 0
        sumM = 0
        col = column(table, i)
        for el in range(len(col) - 2):
            sumZ += col[el] * Z[basis[el]]
            sumM += col[el] * M[basis[el]]
        if i > 0:
            sumZ -= Z[i - 1]
            sumM -= M[i - 1]
        table[n - 2][i] = sumM
        table[n - 1][i] = sumZ


def is_optimal(table, n, m, task_type):
    """ Check if plan is optimal """
    for j in range(1, m):
        if table[n - 2][j] * task_type < 0:
            return False
        if table[n - 2][j] == 0 and table[n - 1][j] * task_type < 0:
            return False
    return True


if __name__ == '__main__':
    iter = 0
    tn = len(task)
    tm = len(task[0])

    num_var = tm - 2  # Number of X's
    num_lim = tn - 1  # Number of limits

    task_type = task[0][tm - 1]  # Define task type - Maximize or Minimize

    for j in range(tm - 2):
        if j > 0:
            print(" + ", end='')
        print(f"{task[0][j]}X{j + 1}", end='')
    print(" -> ", end='')
    if task[0][tm - 1] == 1:
        print("max")
    else:
        print("min")
    for i in range(1, tn):
        print("{ ", end='')
        for j in range(tm - 2):
            if j > 0:
                print(" + ", end='')
            print(f"{task[i][j]}X{j + 1}", end='')
        if task[i][tm - 2] == -1:
            print(" <= ", end='')
        elif task[i][tm - 2] == 1:
            print(" >= ", end='')
        elif task[i][tm - 2] == 0:
            print(" = ", end='')
        print(f"{task[i][tm - 1]}")

    add_var = 0
    fake_var = 0

    for i in range(1, tn):
        if task[i][tm - 2] == 1:
            add_var += 2
            fake_var += 1
        if task[i][tm - 2] == 0:
            add_var += 1
            fake_var += 1
        if task[i][tm - 2] == -1:
            add_var += 1

    n = num_lim + 2  # simplex rows
    m = tm + add_var - 1  # simplex cols
    table = [[Fraction(0) for x in range(m)] for y in range(n)]  # simplex table

    for i in range(tn - 1):
        table[i][0] = task[i + 1][tm - 1]
    for i in range(tn):
        for j in range(tm - 2):
            table[i - 1][j + 1] = task[i][j]

    Z = [Fraction(0) for x in range(m - 1)]  # X coefficients
    M = [Fraction(0) for x in range(m - 1)]  # MX coefficients

    for i in range(num_var):
        Z[i] = task[0][i]

    fake = [Fraction(0) for x in range(fake_var)]  # count how many M numbers are needed
    k = 0
    j = tm - 1
    for i in range(1, n - 1):
        if task[i][tm - 2] == 1:
            table[i - 1][j] = Fraction(-1)
            j += 1
            fake[k] = j
            k += 1
            table[i - 1][j] = Fraction(1)
            j += 1
            M[j - 2] = -1 * task_type
        if task[i][tm - 2] == 0:
            M[j - 1] = -1 * task_type
            fake[k] = j
            k += 1
            table[i - 1][j] = Fraction(1)
            j += 1
        if task[i][tm - 2] == -1:
            table[i - 1][j] = Fraction(1)
            j += 1

    basis = [Fraction(0) for x in range(num_lim)]  # list of basis
    k = 0
    for j in range(m):
        summ = 0
        quan = 0
        for i in range(n - 2):
            summ += table[i][j]
            if table[i][j] != 0:
                quan += 1
        if summ == 1 and quan == 1:
            basis[k] = j - 1
            k += 1

    estimates_in_tables(table, basis, Z, M, n, m)
    print(f"Iter: {iter}")
    print_table(table, n, m)

    while not is_optimal(table, n, m, task_type):  # while not optimal plan
        in_base = 1
        for i in range(2, m):
            if table[n - 2][i] * task_type < table[n - 2][in_base] * task_type:
                in_base = i
            if table[n - 2][i] == table[n - 2][in_base] \
                    and table[n - 1][i] * task_type < table[n - 1][in_base] * task_type:
                in_base = i

        CO = [Fraction(0) for x in range(n - 2)]  #
        for i in range(n - 2):
            if table[i][in_base] <= 0:
                CO[i] = -math.inf
                continue
            CO[i] = table[i][0] / table[i][in_base]

        out_base = -1
        for i in range(n - 2):
            if CO[i] >= 0:
                if out_base == -1:
                    out_base = i
                    continue
                if CO[i] < CO[out_base]:
                    out_base = i
                    continue
                if CO[i] == CO[out_base]:
                    pass
        if out_base == -1:
            break

        r = table[out_base][in_base]  # supporting element

        print(f"For basis: X{in_base}")
        print(f"CO:", end='')
        for i in range(n - 2):
            print(CO[i], end=' ')
        print(f"\nmin = {CO[out_base]}")
        print(f"In row of basis: X{basis[out_base] + 1}")
        print(f"Supporting element: {r}")

        m_ = [[0 for x in range(m)] for y in range(n - 2)]
        for i in range(n - 2):
            for j in range(m):
                m_[i][j] = table[i][j]
        for i in range(n - 2):
            for j in range(m):
                if i == out_base:
                    table[i][j] = m_[i][j] / r
                else:
                    table[i][j] = m_[i][j] - m_[i][in_base] * m_[out_base][j] / r
        basis[out_base] = in_base - 1
        estimates_in_tables(table, basis, Z, M, n, m)
        iter += 1
        print(f"Iter: {iter}")
        print_table(table, n, m)

    if not is_optimal(table, n, m, task_type):
        print("Unlimited area. No answer!")
        exit(0)

    for i in range(n - 2):
        for j in range(fake_var):
            if basis[i] + 1 == fake[j] and table[i][0] != 0:
                print("There're still M element(s) - no answer!")
                print(f"X{basis[i] + 1} = {table[i][0]}")
                exit(0)

    print("\nFound Optimal solution!")
    print("++++++++++++++++++++++++++++++++++++Final result++++++++++++++++++++++++++++++++++++")
    Zres = 0
    for i in range(n - 2):
        if basis[i] >= num_var:
            print(" ! ", end='')
        print(f"X{basis[i] + 1} = {table[i][0]}")
        Zres += basis[i] * -task[0][i]
    print(f"Z = {Zres}")
    print("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")
