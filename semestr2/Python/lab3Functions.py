# задание 3a - определить три функции : добавление товара в список, удаление товара и вывод всех элементов


def addProduct(products, name):
    products.append(name)
    print("Товар '", name, "' добавлен в список.")

def removeProduct(products, product):
    if product in products:
        products.remove(product)
        print("Товар '", product, "' удалён из списка.")
    else:
        print("Данного товара нет в списке.")

def deleteIndex(products, index):
    if index < len (products) and index > 0:
        del products[index - 1] 
        print("Товар с индексом", index, "удален из списка.")
    else:
        
        print("Ошибка: такого индекса нет в списке товаров.")

def printProduct(products):
    if products:
        print("Список товаров:", products)
    else:
        print("Список товаров пуст.")

def menu():
    products = []

    while True:
        print("\n\tМеню:")
        print("1. Добавить товар")
        print("2. Удалить товар по названию")
        print("3. Удалить товар по индексу")
        print("4. Вывести список товаров")
        print("5. Выход")
        choice = input("\nВведите номер пункта меню: ")

        if choice == "1":
            name = input("\nВведите название товара: ")
            addProduct(products, name)
        elif choice == "2":
            name = input("\nВведите название товара, который хотите удалить: ")
            removeProduct(products, name)
        elif choice == "3":
            try:
                index = int(input("\nВведите индекс товара, который хотите удалить: "))
                deleteIndex(products, index)
            except ValueError:
                print("Ошибка: введите целое число для индекса товара.")
        elif choice == "4":
            printProduct(products)
        elif choice == "5":
            break
        else:
            print("\nОшибка: выберите пункт меню от 1 до 5.")

menu()