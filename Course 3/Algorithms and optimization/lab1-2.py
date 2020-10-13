from fractions import Fraction
import matplotlib.pyplot as plt

def print_matrix(a):
    for row in a:
        if any(row):
            for elem in row:
                print(f"{Fraction(elem)}", end=' ')
            print()
    print()


def gauss_jordan(a):
    n = len(a)
    m = len(a[0])
    for i in range(n):
        for j in range(m):
            if a[i][j] != 0:
                for I in range(n):
                    for J in range(j + 1, m):
                        if i != I and j != J:
                            a[I][J] = (a[i][j] * a[I][J] - a[i][J] * a[I][j]) / a[i][j]
                    if i != I:
                        a[I][j] = 0
                w = a[i][j]
                for y in range(m):
                    a[i][y] = a[i][y] / w
                break
        print_matrix(a)


def print_answers(a):
    for row in a:
        for i, el in enumerate(row[: -1]):
            if el != 0:
                if el > 0:
                    print(f"+ {Fraction(el)}x{i + 1} ", end='')
                else:
                    print(f" {Fraction(el)}x{i + 1} ", end='')
        print(f"= {row[-1]}")


A = [list(map(Fraction, line.split())) for line in open("matrix.txt")]
print_matrix(A)
gauss_jordan(A)
print_answers(A)
