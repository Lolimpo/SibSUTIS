cost = []
demand = []
supply = []
file = [list(map(int, line.split())) for line in open(r"C:\Users\Lolimpo\PycharmProjects\aivmo\lab3\input.txt")]
for line in range(len(file)):
    if line < len(file) - 2:
        cost.append(file[line])
    elif line < len(file) - 1:
        demand = file[line]
    else:
        supply = file[line]

r = len(supply)
c = len(demand)
total_requirement = 0
total_availability = 0


def column(matrix, col):
    return [row[col] for row in matrix if row[col]]


def second_min(numbers):
    m1, m2 = float('inf'), float('inf')
    for x in numbers:
        if x <= m1:
            m1, m2 = x, m1
        elif x < m2:
            m2 = x
    return m2


def print_table(matrix):
    for col in range(c):
        print(f"\tB{col + 1}", end='')
    print(f"\tAval.")
    for row in range(r):
        print(f"A{row + 1}", end='\t')
        for col in range(c):
            print(f"{matrix[row][col]}", end='\t')
        print(f"{supply[row]}")
    print("Req.", end='')
    for col in range(c):
        print(f"{demand[col]}", end='\t')
    print('\n')


if __name__ == '__main__':
    z_result = 0

    print(f"Init cost matrix:")
    print_table(cost)

    for i in range(0, len(demand)):
        total_requirement += demand[i]

    for i in range(0, len(supply)):
        total_availability += supply[i]

    if total_requirement < total_availability:
        print("Open task, need to add 1 more artificial demander\n")
        for i in range(r):
            cost[i].append(0)
        demand.append(total_availability - total_requirement)
        c += 1
        print(f"Updated cost matrix:")
        print_table(cost)
    elif total_requirement > total_availability:
        print("Open task, need to add 1 more artificial supplier\n")
        temp = [0] * c
        cost.append(temp)
        supply.append(total_requirement - total_availability)
        r += 1
        print(f"Updated cost matrix:")
        print_table(cost)
    else:
        print("Close task, no need in artificial supplier/demander")

    allocate = [[0 for x in range(c)] for y in range(r)]

    # for k in range(r + c - 1):
    while sum(demand) or sum(supply) > 0:
        row = [float('-inf')] * r
        col = [float('-inf')] * c

        for i in range(r):
            if supply[i] > 0:
                min1 = min(cost[i])
                min2 = second_min(cost[i])
                row[i] = min2 - min1
        for i in range(c):
            col_temp = []
            if demand[i] > 0:
                for j in range(r):
                    if supply[j] > 0:
                        if cost[j][i] > 0:
                            col_temp.append(cost[j][i])
                            min1 = min(col_temp)
                            min2 = second_min(col_temp)
                            col[i] = min2 - min1

        print("Calculated value of diff in first min and second min element in every row ", row)
        print("Calculated value of diff in first min and second element in a col", col)

        if max(col) > max(row):
            temp = 1000
            indexes = [0, 0]
            maximal = max(col)
            all_maximal = [i for i, v in enumerate(col) if v == maximal]
            # print(f"col {all_maximal}")
            for i in all_maximal:
                for j in range(r):
                    if temp > cost[j][i] > 0 and supply[j] > 0:
                        indexes = [j, i]
                        temp = cost[j][i]
        else:
            temp = 1000
            indexes = [0, 0]
            maximal = max(row)
            all_maximal = [i for i, v in enumerate(row) if v == maximal]
            # print(f"row{all_maximal}")
            for i in all_maximal:
                for j in range(c):
                    if temp > cost[i][j] and demand[j] > 0:
                        indexes = [i, j]
                        temp = cost[i][j]
        print(f"Choosing element: {indexes}")

        if supply[indexes[0]] > demand[indexes[1]]:
            allocate[indexes[0]][indexes[1]] = demand[indexes[1]]
            supply[indexes[0]] -= demand[indexes[1]]
            demand[indexes[1]] = 0
        else:
            allocate[indexes[0]][indexes[1]] = supply[indexes[0]]
            demand[indexes[1]] -= supply[indexes[0]]
            supply[indexes[0]] = 0
        print_table(allocate)

    print("Final matrix:")
    print_table(allocate)
    print(f"Need to be occupied: {r} + {c} - 1 = {r + c - 1}")
    occupied = 0
    print("Z = ", end='')
    for i in range(r):
        for j in range(c):
            if allocate[i][j]:
                z_result += allocate[i][j] * cost[i][j]
                print(f"{allocate[i][j]}*{cost[i][j]} + ", end='')
                occupied += 1
    print(f" = {z_result}")
