from datetime import datetime
import re

# Класс Employee и производные классы HourlyEmployee и SalaryEmployee
class Employee:
    def __init__(self, name, birth_date, phone, email, specialty):
        self.name = name
        self.birth_date = birth_date
        self.phone = phone
        self.email = email
        self.specialty = specialty

    def calculateAge(self):
        birth_date = datetime.strptime(self.birth_date, "%d.%m.%Y")
        today = datetime.today()
        age = today.year - birth_date.year - (
            (today.month, today.day) < (birth_date.month, birth_date.day)
        )
        return age

    def _calculateSalary(self):
        pass

    def __str__(self):
        return f"{self.__class__.__name__} {self.name}, age {self.calculateAge()}"

    # Getters and setters with property and decorators
    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, value):
        self._name = value

    @property
    def birth_date(self):
        return self._birth_date

    @birth_date.setter
    def birth_date(self, value):
        self._birth_date = value

    @property
    def phone(self):
        return self._phone

    @phone.setter
    def phone(self, value):
        self._phone = value

    @property
    def email(self):
        return self._email

    @email.setter
    def email(self, value):
        self._email = value

    @property
    def specialty(self):
        return self._specialty

    @specialty.setter
    def specialty(self, value):
        self._specialty = value


class HourlyEmployee(Employee):
    def __init__(self, name, birth_date, phone, email, specialty, hourly_rate):
        super().__init__(name, birth_date, phone, email, specialty)
        self.hourly_rate = hourly_rate
        self.hours_worked = 0

    def _calculateSalary(self):
        return self.hourly_rate * self.hours_worked

    def __str__(self):
        return f"{super().__str__()}, hourly salary: {self._calculateSalary()}"


class SalaryEmployee(Employee):
    def __init__(self, name, birth_date, phone, email, specialty, monthly_salary):
        super().__init__(name, birth_date, phone, email, specialty)
        self.monthly_salary = monthly_salary

    def _calculateSalary(self):
        return self.monthly_salary

    def __str__(self):
        return f"{super().__str__()}, monthly salary: {self._calculateSalary()}"
