from typing import List, Tuple

from Lab3.lab3 import *


def read_graph(filename: str) -> Tuple[dict, List[str], int]:
    """
    Функция получает на вход название файла, в котором лежит граф и возвращает считанный из него
    список ребер в dict, список цветов в list, и количество вершин int.
    """
    vertex_array = {'from': [], 'to': []}
    with open(filename, 'r') as f:
        vertex_num, edge_num = [int(x) for x in next(f).split()]
        for i, line in enumerate(f):
            if i == edge_num:
                colors = [x for x in line.split()]
                break
            fr, to = [int(x) for x in line.split()]
            vertex_array['from'].append(fr)
            vertex_array['to'].append(to)
    return vertex_array, colors, vertex_num


def main() -> int:
    """
    Основная функция программы.
    """
    graph, colors, vertex_num = read_graph('graph1.txt')
    print(f'Граф содержит {vertex_num} вершин и {len(graph["from"])} ребер:')
    for i in range(len(graph["from"])):
        print(f'{graph["from"][i]} {graph["to"][i]}')
    print(f'Раскраска: {colors}')

    # Alice
    color_name = ['R', 'G', 'B']
    color_name_shuffle = color_name.copy()
    while color_name_shuffle == color_name:
        random.shuffle(color_name_shuffle)
    colors_shuffle = ['' for _ in range(len(colors))]
    for i in range(vertex_num):
        if colors[i] == 'R':
            colors_shuffle[i] = color_name_shuffle[0]
        elif colors[i] == 'G':
            colors_shuffle[i] = color_name_shuffle[1]
        elif colors[i] == 'B':
            colors_shuffle[i] = color_name_shuffle[2]
    print(f'Перекрашеный граф Алисой: {colors_shuffle}')

    r = list()
    for i in colors_shuffle:
        if i == 'R':
            r.append(random.getrandbits(32) >> 2 << 2)
        elif i == 'G':
            r.append((random.getrandbits(32) >> 2 << 2) | 1)
        elif i == 'B':
            r.append((random.getrandbits(32) >> 2 << 2) | 2)
    print(f'r = {r}')

    p = [get_prime(0, 10 ** 9) for _ in range(vertex_num)]
    q = [get_prime(0, 10 ** 9) for _ in range(vertex_num)]
    n = [p[i] * q[i] for i in range(vertex_num)]
    phi = [(p[i] - 1) * (q[i] - 1) for i in range(vertex_num)]
    d = [get_coprime(phi[i]) for i in range(vertex_num)]
    c = [extended_euclidean_algorithm(d[i], phi[i])[1] for i in range(vertex_num)]
    for i in range(vertex_num):
        while c[i] < 0:
            c[i] += phi[i]

    Z = [pow_mod(r[i], d[i], n[i]) for i in range(vertex_num)]

    for i in range(len(graph['from'])):
        _Z1 = pow(Z[graph['from'][i] - 1], c[graph['from'][i] - 1], n[graph['from'][i] - 1])
        _Z2 = pow(Z[graph['to'][i] - 1], c[graph['to'][i] - 1], n[graph['to'][i] - 1])
        print(f'Для ребра {i + 1} два младших бита различны.'
              if bin(_Z1)[-2:] != bin(_Z2)[-2:]
              else f'Алиса обманула Боба! Два последних бита совпадают у ребра {i + 1} с вершинами:\n{_Z1:b} | {_Z2:b}')
    return 0


if __name__ == '__main__':
    exit(main())
