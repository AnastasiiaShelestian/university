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
            return "Average salary in company: " + "{:.2f}".format(sum / count)
        else:
            return "Error! Records not found or there is an error in data."
    except FileNotFoundError:
        return "Error! File not found."

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
            return f"Employee with highest salary {result}"
        else:
            return "Error! Records not found or there is an error in data."
    except FileNotFoundError:
        return "Error! File not found."

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
            return f"Employee with lowest salary: {result}"
        else:
            return "Error! Records not found or there is an error in data."
    except FileNotFoundError:
        return "Error! File not found."
    
def average_salary_by_department():
    departments = set()
    data = []
    result = []
    
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
                    result.append("Average salary by department " + dep + " : " + "{:.2f}".format(sum / count))
            return result
        else:
            return "Error! Records not found or there is an error in data."
    except FileNotFoundError:
        return "Error! File not found."