decor = "=" + "-" * 20 + "="


class Node:  # Структура даних вузла
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

    def __str__(self):
        return "<Node: (%s, %s), next: %s>" % (self.key, self.value, self.next != None)

    def __repr__(self):
        return str(self)


class HashTable:  # Хеш-таблиця з окремим ланцюжком
    """Створення таблиці"""

    def __init__(self):
        self.capacity = 50  # Ємність для внутрішнього масиву
        self.size = 0
        self.buckets = [None] * self.capacity

    def hash(self, key):  # Створює хеш для заданого ключа
        hashsum = 0
        for idx, c in enumerate(key):  # Для кожного символу в ключі
            hashsum += (idx + len(key)) ** ord(c)
            hashsum = hashsum % self.capacity
        return hashsum

    def hash_insert(self, key, value):  # Вставте пару ключ-значення в хеш-таблицю Output: void
        self.size += 1
        index = self.hash(key)
        node = self.buckets[index]  # Перейти до вузла, що відповідає хешу
        if node is None:  # Якщо вузол пустий Створити вузол, додати його, повернути
            self.buckets[index] = Node(key, value)
            print(self.buckets)

            return
        prev = node
        while node is not None:
            prev = node
            node = node.next
        prev.next = Node(key, value)  # Додайте новий вузол у кінець списку з указаним ключем/значенням

    """
    Знайдіть значення даних на основі ключа
    Вхід: ключ - рядок
    Вивід: значення зберігається під "ключем" або "Немає", якщо не знайдено
    """

    def hash_search(self, key):  # Пошук
        index = self.hash(key)
        node = self.buckets[index]

        while node is not None and node.key != key:
            node = node.next
        if node is None:
            return None
        else:
            return node.value


    """
    Видалити вузол, збережений у ключі
    Вхід: ключ - рядок
    Вихід: видалено значення даних або Немає, якщо не знайдено
    """

    def hash_delete(self, key):
        index = self.hash(key)
        node = self.buckets[index]
        prev = None
        while node is not None and node.key != key:
            prev = node
            node = node.next
        if node is None:
            return None
        else:
            self.size -= 1
            result = node.value
            if prev is None:
                self.buckets[index] = node.next
            else:
                prev.next = prev.next.next
            return result  # Повернути видалений результат

    def show_table(self):
        array_inside = []

        for i in range(len(self.buckets)):
            print(i, end=" ")
            for j in self.buckets[i]:
                print('-->', end=" ")
                print(j, end='')
            print()
        print(decor)


ht = HashTable()  # Створіть нову хеш-таблицю

ht.hash_insert("phoneDirectory", ["555-555-5555", "444-444-4444"])
ht.hash_insert("phoneDirectory1", ["555-555-5555", "4434-444-4444"])
ht.hash_insert("phoneDirectory2", ["555-555-5555", "444-66676-4444"])
ht.hash_insert("phoneDirectory3", ["555-555-5555", "444-4343-4444"])
ht.hash_insert("phoneDirectory4", ["555-555-5555", "4434-444-4444"])
ht.hash_insert("phoneDirectory5", ["555-555-5555", "444-66676-4444"])
ht.hash_insert("phoneDirectory6", ["555-555-5555", "444-4343-4444"])

print(ht.hash_search("phoneDirectory"))
print(ht.hash_search("phoneDirectory5"))
