from random import randint

"""Decor"""
decor = "=" + "-" * 20 + "="

INF = 9999999  # кількість вершин у графі
array_size = 5  # створити двовимірний масив розміром 5x5
# for adjacency matrix to represent graph
matrix = []

print(decor)
how_start = input("""Введіть яким чином хочете заповнити двохвимірний масив(Матрицю):
0 - Вручну\n1 - Автоматично\n2 - Автоматично з відомими даними\n=""")
print(decor)
if int(how_start) == 0:
    print("Заповни двохвимірний масив(Матрицю)")
    for i in range(array_size):
        buffer_array = []
        for j in range(array_size):
            buffer_array.append(int(input(f"Рядок{i + 1}: Елемент {j + 1}= ")))
        matrix.append(buffer_array)

elif int(how_start) == 1:
    for i in range(array_size):
        buffer_array = []
        for j in range(array_size):
            buffer_array.append(randint(0, 50))
        matrix.append(buffer_array)

elif int(how_start) == 2:
    matrix = [[0, 9, 75, 0, 0],
              [9, 0, 95, 19, 42],
              [75, 95, 0, 51, 66],
              [0, 19, 51, 0, 31],
              [0, 42, 66, 31, 0]]


else:
    print("Введено дані котрі не подялгають умові!")

# створити масив для відстеження вибраної вершини
# вибране стане істинним, інакше стане хибним
selected = [0, 0, 0, 0, 0]
# встановити кількість ребер на 0
no_edge = 0
# кількість egde у мінімальному охоплюючому дереві буде завжди менше ніж (array_size - 1), де array_size - кількість вершин у графіку
# виберіть 0-ту вершину та зробіть її істинною
selected[0] = True
print("Вершини : Вага")
print(decor)
while (no_edge < array_size - 1):
    # Для кожної вершини множини S знайдіть усі суміжні вершини
    # обчисліть відстань від вершини, вибраної на кроці 1.
    # якщо вершина вже є в наборі S, інакше відкинути її
    # виберіть іншу вершину, найближчу до вибраної вершини на кроці 1.
    minimum = INF
    x = 0
    y = 0
    for i in range(array_size):
        if selected[i]:
            for j in range(array_size):
                if (not selected[j]) and matrix[i][j]:
                    # не в обраному і є край
                    if minimum > matrix[i][j]:
                        minimum = matrix[i][j]
                        x = i
                        y = j

    print(f"{x} ----- {y} : {matrix[x][y]}")
    selected[y] = True
    no_edge += 1
