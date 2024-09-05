import re

def input_data():
    while True:
        surname = input("Введите фамилию сотрудника: ").upper()
        if not re.match("^[a-zA-Zа-яА-Я]{2,20}(?:-[a-zA-Zа-яА-Я]{2,20}){0,3}$", surname):
            print("Ошибка! Фамилия должна содержать только буквы и дефис, длиной от 2 до 20 символов.")
            continue
        
        name = input("Введите имя сотрудника: ").upper()
        if not re.match("^[a-zA-Zа-яА-Я]{2,20}(?:-[a-zA-Zа-яА-Я]{2,20}){0,3}$", name):
            print("Ошибка! Имя должно содержать только буквы и дефис, длиной от 2 до 20 символов.")
            continue
        
        department = input("Введите отдел сотрудника: ").upper()
        if not re.match("^[a-zA-Z0-9а-яА-Я]{2,15}( [a-zA-Z0-9а-яА-Я]{2,15}){0,5}$", department):
            print("Ошибка! Название отдела должно содержать буквы, цифры и пробелы.")
            continue
        
        try:
            children = int(input("Введите количество детей младше 18 лет: "))
            if not 0 <= children <= 19:
                print("Ошибка! Количество детей должно быть от 0 до 19.")
                continue
        except ValueError:
            print("Ошибка! Введите целое число для количества детей.")
            continue
        
        with open("data.txt", "a") as file:
            file.write(f"{surname}\t{name}\t{department}\t{children}\n")
        
        break

def view_data():
    total_children = 0
    try:
        with open("data.txt", "r") as file:
            for line in file:
                surname, name, department, children = line.strip().split("\t")
                print(f"Сотрудник: {surname} {name}, отдел: {department}, количество детей: {children}")
                total_children += int(children)
        
        print(f"Общее количество детей в компании: {total_children}")
    except FileNotFoundError:
        print("Ошибка! Файл с данными не найден.")

def childless_employees():
    childless = []
    try:
        with open("data.txt", "r") as file:
            for line in file:
                surname, name, _, children = line.strip().split("\t")
                if int(children) == 0:
                    childless.append(f"{surname} {name}")
        
        if childless:
            print("Список сотрудников без детей:")
            for employee in childless:
                print(employee)
        else:
            print("В компании нет сотрудников без детей.")
    except FileNotFoundError:
        print("Ошибка! Файл с данными не найден.")

def main():
    while True:
        print("\nМеню:")
        print("1. Ввод данных в файл")
        print("2. Просмотр данных о детях сотрудников")
        print("3. Поиск и вывод списка бездетных сотрудников")
        print("4. Выход из программы")
        
        choice = input("Выберите опцию (1-4): ")
        
        if choice == "1":
            input_data()
        elif choice == "2":
            view_data()
        elif choice == "3":
            childless_employees()
        elif choice == "4":
            print("Программа завершена.")
            break
        else:
            print("Ошибка! Введите число от 1 до 4 для выбора опции.")

if __name__ == "__main__":
    main()
