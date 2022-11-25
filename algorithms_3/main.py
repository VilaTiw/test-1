from collections import defaultdict
import sys
from random import randint

decor = "=" + "-" * 20 + "="


class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.graph = []

    def set_make(self, u_inside, v_inside, w_inside):  # Добавити вершину
        self.graph.append([u_inside, v_inside, w_inside])

    def init_vertices(self):
        print(decor)
        how_start = input("Введіть яким чином хочете заповнити вершини:\n1 - Вручну\n0 - Автоматично\n=")
        print(decor)
        if int(how_start) == 0:
            self.set_make(2, 4, 4)
            self.set_make(3, 2, 3)
            self.set_make(3, 4, 3)
            self.set_make(0, 2, 4)
            self.set_make(1, 2, 2)
            self.set_make(4, 3, 3)
            self.set_make(5, 2, 2)
            self.set_make(5, 4, 3)
            self.set_make(1, 0, 4)
            self.set_make(2, 0, 4)
            self.set_make(2, 1, 2)
            self.set_make(2, 3, 3)
            self.set_make(4, 2, 4)
            self.set_make(0, 1, 4)
            self.set_make(2, 5, 2)
        elif int(how_start) == 1:
            print("Якщо хочеш зупинити процес введи в консоль STOP")
            num = 0
            x_inside = ""
            y_inside = ""
            weight_inside = ""
            while str(x_inside) != "STOP" and str(y_inside) != "STOP" and str(weight_inside) != "STOP":

                num += 1
                x_inside = input(f"x {num} = ")
                y_inside = input(f"y {num} = ")
                weight_inside = input(f"weight {num} = ")
                print(decor)

                if str(x_inside) != "STOP" and str(y_inside) != "STOP" and str(weight_inside) != "STOP":

                    self.set_make(int(x_inside), int(y_inside), int(weight_inside))

        else:
            print("Введено дані котрі не подялгають умові!")

    def set_find(self, parent_element, y_or_x_inside):  # Знайти
        if parent_element[y_or_x_inside] == y_or_x_inside:
            return y_or_x_inside
        return self.set_find(parent_element, parent_element[y_or_x_inside])

    def set_union(self, parent_element, rank, x_inside, y_inside):  # Обєднати
        y_root = self.set_find(parent_element, y_inside)
        x_root = self.set_find(parent_element, x_inside)
        if rank[x_root] < rank[y_root]:
            parent_element[x_root] = y_root
        elif rank[x_root] > rank[y_root]:
            parent_element[y_root] = x_root

        else:
            parent_element[y_root] = x_root
            rank[x_root] += 1

    def print_tree(self, parent_element):
        print("Edge \tWeight")
        for i in range(1, self.vertices):
            print(f"{parent_element[i]} - {i}     {self.graph[i][parent_element[i]]}")

    def kruskal_algo(self):  # Алгоритм Краскала (реалізація)
        result = []
        i = 0
        e = 0
        # print(self.graph)
        self.graph = sorted(self.graph, key=lambda item: item[2])
        # print(self.graph)
        parent_element = []

        for node in range(self.vertices):
            parent_element.append(node)
        # print(parent_element)
        while e < self.vertices - 1:
            u_inside, v_inside, w_inside = self.graph[i]
            i += 1
            x = self.set_find(parent_element, u_inside)
            y = self.set_find(parent_element, v_inside)

            if x != y:
                e = e + 1
                result.append([u_inside, v_inside, w_inside])

        min_cost = 0
        print("Ребра в побудованому каркасі")
        for u_inside, v_inside, weight in result:
            min_cost += weight
            print(f"{u_inside} -- {v_inside} == {weight}")
        print("Мінімальна сума ваг ребер", min_cost)


g = Graph(12)
g.init_vertices()
g.kruskal_algo()
