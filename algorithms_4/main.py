from random import randint

decor = "=" + "-" * 20 + "="

name = ["Давид", "Далемил", "Далемир", "Далібор", "Дан", "Данило", "Данко", "Дантур", "Дар", "Дарій", "Дарибог",
        "Даромир", "Денис", "Демид", "Дем'ян", "Держикрай", "Держислав", "Дибач", "Дивозір", "Дій", "Дмитро",
        "Добрибій", "Добривод", "Добрик", "Добрило", "Добриня", "Добрисвіт", "Добровіст", "Доброгост", "Добродум",
        "Добролик", "Добролюб", "Добромир", "Добромисл", "Доброслав", "Доморад", "Домослав", "Дорогобуг", "Дорогомир",
        "Дорогомисл", "Дорогосил", "Дорогочин", "Дорофій", "Домінік", "Драган", "Драгомир"]


def show_table(hashtable):
    for i in range(len(hashtable)):
        print(i, end=" ")
        for j in hashtable[i]:
            print('-->', end=" ")
            print(j, end='')
        print()
    print(decor)


HashTable = [[] for _ in range(10)]


def hashing(key_value):
    return key_value % len(HashTable)


def chained_hash_insert(hashtable, key_value, value):
    hash_key = hashing(key_value)
    hashtable[hash_key].append(value)


def chained_hash_delete(hashtable, key_value):
    hash_key = hashing(key_value)
    hashtable[hash_key].pop()


def chained_hash_search(hashtable, value):
    for i in range(len(hashtable)):
        for j in hashtable[i]:
            if value == j:
                for k in hashtable[i]:
                    print('-->', end=" ")
                    print(k, end='')


def start():
    print(decor)
    how_start = input(
        "Введіть яким чином хочете заповнити вершини:\n0 - Вручну\n1 - Автоматично з відомими вхідними\n2 - Автоматично\n=")
    print(decor)
    if int(how_start) == 0:
        num = 0
        input_data_num = ""
        input_data_name = ""
        print("Якщо хочеш зупинити процес введи в консоль STOP")

        while str(input_data_num) != "STOP" and str(input_data_name) != "STOP":
            num += 1
            input_data_num = input(f"Введіть номер для особи №{num}: ")
            input_data_name = input(f"Введіть Імя особи №{num}: ")

            if str(input_data_num) != "STOP" and str(input_data_name) != "STOP":
                chained_hash_insert(HashTable, int(input_data_num), input_data_name)

        show_table(HashTable)

    elif int(how_start) == 1:

        chained_hash_insert(HashTable, 7, 'Добролюб')
        chained_hash_insert(HashTable, 25, 'Держислав')
        chained_hash_insert(HashTable, 20, 'Домослав')
        chained_hash_insert(HashTable, 9, 'Дар')
        chained_hash_insert(HashTable, 20, 'Далемил')

        chained_hash_search(HashTable, 'Punjab')

        show_table(HashTable)

    elif int(how_start) == 2:
        num = int(input("Введіть кількість елементів скільки потрібно згенерувати:"))
        for i in range(num):
            chained_hash_insert(HashTable, randint(0, 100), name[randint(0, len(name) - 1)])

        show_table(HashTable)

    else:

        print("Введено дані котрі не подялгають умові!")


start()
print(HashTable)

# delete(HashTable, 9)
# show_table(HashTable)
