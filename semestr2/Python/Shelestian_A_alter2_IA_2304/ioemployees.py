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
        if not re.match("^[a-zA-Zа-яА-Я]{2,15}( [a-zA-Zа-яА-Я]{2,15}){0,5}$", department):
            print("Ошибка! Название отдела должно содержать буквы и пробелы.")
            continue
        
        try:
            salary = float(input("Введите зарплату сотрудника: "))
            if not 1000.00 <= salary <= 77000.00:
                print("Ошибка! Зарплата должна быть от 1000.00 до 77000.00.")
                continue
        except ValueError:
            print("Ошибка! Введите вещественное число для зарплаты сотрудника.")
            continue
        
        with open("data.txt", "a") as file:
            file.write(f"{surname}\t{name}\t{department}\t{salary}\n")
        
        break

def view_data():
    try:
        with open("data.txt", "r") as file:
            for line in file:
                surname, name, department, salary = line.strip().split("\t")
                print(f"Сотрудник: {surname} {name}, отдел: {department}, зарплата: {salary}")
        
    except FileNotFoundError:
        print("Ошибка! Файл с данными не найден.")