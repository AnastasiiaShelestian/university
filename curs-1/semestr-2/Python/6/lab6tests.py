 
import re
from lab6 import Employee, HourlyEmployee, SalaryEmployee


def get_valid_input(prompt, pattern):
    while True:
        value = input(prompt)
        if re.match(pattern, value):
            return value
        print("Ошибка. Старайся лучше!")


def create_employee():
    name = get_valid_input("Имя: ", r"^[a-zA-Zа-яА-Я]{2,20}(?:-[a-zA-Zа-яА-Я]{2,20}){0,3}$")
    birth_date = get_valid_input("Дата рождения (dd.mm.yyyy): ", r"^[0-9]{2}\.[0-9]{2}\.[0-9]{4}$")
    phone = get_valid_input("Номер телефона (+373cccccccc): ", r"^\+373\d{8}$")
    email = get_valid_input("Email: ", r"^[a-zA-Z0-9_.-]{2,20}@[a-zA-Z]{4,7}\.[a-zA-Z]{2,4}$")
    specialty = get_valid_input("Профессия: ", r"^[a-zA-Zа-яА-Я]{2,20}(?:-[a-zA-Zа-яА-Я]{2,20}){0,3}$")
    return name, birth_date, phone, email, specialty


# Create a list of Employee objects
employees = []

for _ in range(2):
    print(" ")
    name, birth_date, phone, email, specialty = create_employee()
    employees.append(Employee(name, birth_date, phone, email, specialty))

for _ in range(2):
    print("Enter information for an Hourly Employee:")
    name, birth_date, phone, email, specialty = create_employee()
    hourly_rate = float(get_valid_input("Почасовая ставка: ", r"^\d+(\.\d{1,2})?$"))
    hours_worked = float(get_valid_input("Отработанные часы: ", r"^\d+(\.\d{1,2})?$"))
    hourly_employee = HourlyEmployee(name, birth_date, phone, email, specialty, hourly_rate)
    hourly_employee.hours_worked = hours_worked
    employees.append(hourly_employee)

for _ in range(2):
    print("Enter information for a Salary Employee:")
    name, birth_date, phone, email, specialty = create_employee()
    monthly_salary = float(get_valid_input("Месячная зарплата: ", r"^\d+(\.\d{1,2})?$"))
    salary_employee = SalaryEmployee(name, birth_date, phone, email, specialty, monthly_salary)
    employees.append(salary_employee)

# Display all employees and their calculated salaries
print("\n Информация о сотруднике:")
for emp in employees:
    print(emp)
