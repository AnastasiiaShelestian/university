from employees import Employee, HourlyEmployee, SalaryEmployee

try:
    name = input("Введите имя сотрудника: ")
    phone = input("Введите номер телефона: ")
    bday = input("Введите дату рождения (dd.mm.yyyy): ")
    email = input("Ведите электронную почту: ")
    position = input("Введите должность: ")
    salary = int(input("Введите зарплату: "))

    salary_emp1 = SalaryEmployee(name, phone, bday, email, position, salary)

    name = input("Введите имя сотрудника который работает почасово: ")
    phone = input("Введите номер сотрудника который работает почасово: ")
    bday = input("Введите дату рождения сотрудника который работает почасово (dd.mm.yyyy): ")
    email = input("Введите электронную почту сотрудника который работает почасово: ")
    position = input("Введите должность сотрудника который работает почасово: ")
    hours = int(input("Введите часы работы: "))
    hourlyPay = int(input("Введите зарплату сотрудника за отработанный час: "))

    hour_emp1 = HourlyEmployee(name, phone, bday, email, position, hours, hourlyPay)

    print("Зарплата сотрудника который работает почасово:", hour_emp1._calculateSalary())
    print("Зарплата сотрудника:", salary_emp1._calculateSalary())

except ValueError as e:
    print("Error:", e)
