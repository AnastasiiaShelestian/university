

my_data = [(1, 3), (2, 9), (3, 11), (4, 13), (5, 17), (6, 1), (7, 47)]


print("Тип переменной:", type(my_data))


print("Количество элементов:", len(my_data))


print("Элементы с 3-й позиции до конца:", my_data[2:])


print("Все элементы:", end=" ")
for item in my_data:
    print(item, end=" ** ")


my_data.append((8, 3))
print("\nДобавлен новый элемент:", my_data)
