def enterAuthor(dictionaryAuthors):
    author = input("Введите имя автора: ")
    author = author.title()
    if author not in dictionaryAuthors:
        dictionaryAuthors[author] = []
        print(author, "добавлен в словарь.")
    else:
        print(author, "уже есть в словаре.")


def enterBook(dictionaryAuthors):
    author = input("Введите имя автора: ")
    author = author.title()
    book = input("Введите название книги: ")
    book = book.title()
    if author in dictionaryAuthors:
        dictionaryAuthors[author].append(book)
        print("Книга", book, "добавлена автору." )
    elif author in dictionaryAuthors:
        print(author, "уже есть в словаре.")
    else:
        print(author, "не найден в словаре.")

def searchBook(dictionaryAuthors):
    if not dictionaryAuthors:
        print("Словарь пуст.")
    else:
        for author, books in dictionaryAuthors.items():
            print("Автор:", author)
            print("Книги:", ", ".join(books))

def amountBooks(dictionaryAuthors):
    if dictionaryAuthors:
        for author, books in dictionaryAuthors.items():
            print("У", author, len(books), "книг.")
    else:
        print("В словаре пусто.")

def deleteData(dictionaryAuthors):
    author = input("Введите имя автора: ")
    author = author.title()
    if author in dictionaryAuthors:
        del dictionaryAuthors[author]
        print(author, "удалён из словаря.")
    else:
        print("Автора никогда не было в словаре")