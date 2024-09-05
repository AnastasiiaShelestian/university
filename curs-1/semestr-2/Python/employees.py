import re

import re
from datetime import datetime, date

class Employee:
    def __init__(self, name, phone, bday, email, position):
        self.__name = name  # приватные переменные
        self.__phone = phone
        self.__bday = bday
        self.__email = email
        self.__position = position

    def calculate_age(self):
        birth_date = datetime.strptime(self.__bday, '%d.%m.%Y')
        today = date.today()
        age = today.year - birth_date.year - ((today.month, today.day) < (birth_date.month, birth_date.day))
        return age

    def _calculate_salary(self):
        pass  # защищенный и пустой метод

    # Версия с декораторами
    @property
    def name(self):
        return self.__name

    @name.setter
    def name(self, value):
        if re.match(r'^[a-zA-Zа-яА-Я]{2,20}(?:-[a-zA-Zа-яА-Я]{2,20}){0,3}$', value):
            self.__name = value
        else:
            raise ValueError("Имя должно содержать только буквы")

    # Версия с использованием property()
    def get_name(self):
        return self.__name

    def set_name(self, value):
        if re.match(r'^[a-zA-Zа-яА-Я]{2,20}(?:-[a-zA-Zа-яА-Я]{2,20}){0,3}$', value):
            self.__name = value
        else:
            raise ValueError("Имя должно содержать только буквы")

    name = property(get_name, set_name)

    @property
    def phone(self):
        return self.__phone

    @phone.setter
    def phone(self, value):
        if re.match(r'^\+373\d{8}$', value):
            self.__phone = value
        else:
            raise ValueError("Неверный формат номера телефона")

    @property
    def bday(self):
        return self.__bday

    @bday.setter
    def bday(self, value):
        if re.match(r'^(0[1-9]|[12][0-9]|3[01])\.(0[1-9]|1[0-2])\.(19[6-9]\d|200[0-7])$', value):
            self.__bday = value
        else:
            raise ValueError("Неверный формат дня рождения")

    @property
    def email(self):
        return self.__email

    @email.setter
    def email(self, value):
        if re.match(r'^[A-z0-9._-]{2,20}@[A-z]{4,7}\.[A-z]{2,4}$', value):
            self.__email = value
        else:
            raise ValueError("Неверный формат электронной почты")

    @property
    def position(self):
        return self.__position

    @position.setter
    def position(self, value):
        if re.match(r'^[a-zA-Zа-яА-Я]{2,20}(?:-[a-zA-Zа-яА-Я]{2,20}){0,3}$', value):
            self.__position = value
        else:
            raise ValueError("Должность должна содержать только буквы и иметь название в диапазоне от 2 до 20 символов")


class HourlyEmployee(Employee):
    def __init__(self, name, phone, bday, email, position, hours, hourlyPay):
        super().__init__(name, phone, bday, email, position) # вызывает метод из родительского класса(в данном случае конструктор)
        self.__hours = hours
        self.__hourlyPay = hourlyPay

    def _calculateSalary(self):
        return self.__hours * self.__hourlyPay

    @property
    def hours(self):
        return self.__hours

    @hours.setter
    def hours(self, value):
        if isinstance(value, (int, float)):
            self.__hours = value
        else:
            raise ValueError("Укажите часы только цыфрами")

    @property
    def hourlyPay(self):
        return self.__hourlyPay

    @hourlyPay.setter
    def hourlyPay(self, value):
        if isinstance(value, (int, float)):
            self.__hourlyPay = value
        else:
            raise ValueError("Почасовая оплата должна быть числом")

class SalaryEmployee(Employee):
    def __init__(self, name, phone, bday, email, position, salary):
        super().__init__(name, phone, bday, email, position)
        self.salary = salary

    def _calculateSalary(self):
        return self.__salary

    @property
    def salary(self):
        return self.__salary

    @salary.setter
    def salary(self, value):
        if isinstance(value, (int, float)):
            self.__salary = value
        else:
            raise ValueError("Оплата должна быть числом")
