# задание 3a - определить три функции : добавление товара в список, удаление товара и вывод всех элементов

def addProduct (products, name):
  products.append(name)
  print("Товар '", name, "' добавлен в список.")

def removeProduct (products, product):
  if product in products:
      products.remove(product)
      print("Товар '", product, "' удалён из списка.")
  else:
      print("Данного товара нет в списке.")

def deleteIndex(products, index):
  index = int(input("Введите индекс: ")) 
  products.pop(index)

def printProduct (products):
  print("Список товаров :", products)



def menu():
  products = []

# задание 3b - создать меню из 4 опций
  
  while True :
    print("\n\tМеню :")
    print("1. Добавить товар")
    print("2. Удалить товар по названию")
    print("3. Удалить товар по индексу")
    print("4. Вывести список товаров")
    print("5. Выход")
    choice = input("\nВведите номер пункта меню: ")


# задание 3c - создать цикл, в котором пользователь вводит пункт меню и программа выводит определенную функцию
    
    if choice == "1"  :
      name = input("\nВведите название товара: ")
      addProduct(products, name)
    elif choice == "2" :
      index = input("\nВведите название товара, который хотите удалить по названию: ")
      removeProduct(products, index)
    elif choice == "3" :
      index = int(input("\nВведите название товара, который хотите удалить по номеру товара в списке1: ")) - 1 
      deleteIndex(products, index)
    elif choice == "4" :
      printProduct(products)
    elif choice == "5" :
      break
    else :
      print("\nОшибка. Повторите попытку.")
