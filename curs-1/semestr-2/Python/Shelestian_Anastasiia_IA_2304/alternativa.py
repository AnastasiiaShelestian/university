import function

dictionaryAuthor = {}

while True:
    print("----------------------Меню:----------------------")
    print("1. Добавить нового автора.")
    print("2. Добавить книгу к существующему автору.")
    print("3. Просмотреть список авторов и их книг.")
    print("4. Вывести сколько книг у каждого автора.")
    print("5. Удалить автора и все его книги из словаря.")
    print("6. Выход.")
    print("--------------------------------------------------")

    number = input("Выберите номер операции: ")

    while not number.isdigit():
        print("Неверный ввод. Введите только цифры.")
        number = input("Выберите операцию: ")

    number = int(number)

    if number == 1:
        function.enterAuthor(dictionaryAuthor)
    elif number == 2:
        function.enterBook(dictionaryAuthor)
    elif number == 3:
        function.searchBook(dictionaryAuthor)
    elif number == 4:
        function.amountBooks(dictionaryAuthor)
    elif number == 5:
        function.deleteData(dictionaryAuthor)
    elif number == 6:
        print("Выход из программы.")
        break
    else:
        print("Ошибка. Необходимо ввести только допустимые параметры от 1 до 6")
