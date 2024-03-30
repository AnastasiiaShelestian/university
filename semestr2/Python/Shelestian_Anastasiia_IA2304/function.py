def enterAuthor(dictionaryAuthors, author):
    if author not in dictionaryAuthors:
        dictionaryAuthors[author] = []
        print("Автор '", author, "' добавлен(а) в словарь.")
    else:
        print("Данный автор уже есть в словаре.")


def enterBook(dictionaryAuthors, author, book):
    if author in dictionaryAuthors:
        dictionaryAuthors[author].append(book)
        print("Книга '", book, "' добавлена в словарь." )
    elif author in dictionaryAuthors:
        print("Автор '", author, "' есть в словаре.")
    else:
        print("Автор '", author, "' не найден(а) в словаре.")

def searchBook(dictionaryAuthors):
     if dictionaryAuthors:
        print("Список авторов и их книг :")
        
        for authorName, listBooks in dictionaryAuthors.items():
            print("Автор:", authorName)
            print("Книги:")
            for bookName in listBooks:
                print("-", bookName)
            
        else:
            print("В словаре пусто.")

def amountBooks(dictionaryAuthors):
    print()
    if dictionaryAuthors:
        for author, books in dictionaryAuthors.items():
            print("Количество книг у", author, ":", len(books))
    else:
        print("В словаре пусто.")

def deleteData(dictionaryAuthors, author):
    if author in dictionaryAuthors:
        del dictionaryAuthors[author]
        print("Автор '", author, "' был(а) удален(а) из словаря.")
    else:
        print("Автора никогла не было в словаре")
