def average_salary():
    sum = 0
    count = 0
    
    try:
        with open("data.txt", "r") as file:
            for line in file:
                _, _, _, salary = line.strip().split("\t")
                sum += float(salary)
                count += 1 
        
        if sum:
            print("Средняя зарплата по компании: ", "{:.2f}".format(sum / count))
        else:
            print("Записи не найдены или в данных допущена ошибка.")
    except FileNotFoundError:
        print("Ошибка! Файл с данными не найден.")

def biggest_salary():
    max = 0

    try:
        with open("data.txt", "r") as file:
            for line in file:
                surname, name, department, salary = line.strip().split("\t")
                if float(salary) > float(max):
                    result = (f"{surname} {name} {department} {salary}")
                    max = salary

        if result:
            print("Сотрудник с самой высокой зарплатой:")
            print(result)
        else:
            print("Записи не найдены или в данных допущена ошибка.")
    except FileNotFoundError:
        print("Ошибка! Файл с данными не найден.")

def smallest_salary():
    min = 78000

    try:
        with open("data.txt", "r") as file:
            for line in file:
                surname, name, department, salary = line.strip().split("\t")
                if float(salary) < float(min):
                    result = (f"{surname} {name} {department} {salary}")
                    min = salary

        if result:
            print("Сотрудник с самой низкой зарплатой:")
            print(result)
        else:
            print("Записи не найдены или в данных допущена ошибка.")
    except FileNotFoundError:
        print("Ошибка! Файл с данными не найден.")

def average_salary_by_department():
    departments = set()
    data = []
    
    try:
        with open("data.txt", "r") as file:
            for line in file:
                _, _, department, salary = line.strip().split("\t")
                departments.add(department)
                data.append({"salary": salary, "department": department})
            
        
        if departments:
            for dep in departments:
                count = 0
                sum = 0
                for element in data:
                    if element["department"] == dep:
                        sum += float(element["salary"])
                        count += 1
                if sum:
                    print("Средняя зарплата по департаменту ", dep, " : ", "{:.2f}".format(sum / count))
        else:
            print("Записи не найдены или в данных допущена ошибка.")
    except FileNotFoundError:
        print("Ошибка! Файл с данными не найден.")