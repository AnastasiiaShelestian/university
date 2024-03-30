
import function

dictionaryAuthors = {}

while True:

    print("Меню :")
    print("1. Добавить нового автора.")
    print("2. Добавить книгу к существующему автору.")
    print("3. Просмотреть список авторов и их книг.")
    print("4. Вывести сколько книг у каждого автора.")
    print("5. Удалить автора и все его книги из словаря.")
    print("6. Выход.")

    choice = input("Выберите пункт меню: ")

    if not choice.isdigit():
        print("Неверный ввод. вводите только цифры")
        continue

    choice = int(choice)

    if choice == 1:
        author = input("Введите имя автора: ")
        author = author.title()
        function.enterAuthor(dictionaryAuthors, author)
    elif choice == 2:
        author = input("Введите имя автора: ")
        author = author.title()
        book = input("Введите название книги: ")
        book = book.title()
        function.enterBook(dictionaryAuthors, author, book)
    elif choice == 3:
        function.searchBook(dictionaryAuthors)
    elif choice == 4:
        function.amountBooks(dictionaryAuthors)
    elif choice == 5:
        author = input("Введите имя автора: ")
        author = author.title()
        function.deleteData(dictionaryAuthors, author)
    elif choice == 6:
        print("Выход...")
        break
    else:
        print("Ошибка. Необходимо ввести только допустимые параметры от 1 до 6")
