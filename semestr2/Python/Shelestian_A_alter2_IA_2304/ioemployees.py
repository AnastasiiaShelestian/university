import re
import dearpygui.dearpygui as dpg

def input_data():
    surname = dpg.get_value("surname")
    name = dpg.get_value("name")
    department = dpg.get_value("department")
    salary = dpg.get_value("salary")

    try:
        if not re.match("^[a-zA-Zа-яА-Я]{2,20}(?:-[a-zA-Zа-яА-Я]{2,20}){0,3}$", surname):
            raise ValueError("Error! Surname must contain only letters and -, length from 2 to 20 characters.")
        
        if not re.match("^[a-zA-Zа-яА-Я]{2,20}(?:-[a-zA-Zа-яА-Я]{2,20}){0,3}$", name):
            raise ValueError("Error! Name must contain only letters and -, length from 2 to 20 characters.")
        
        if not re.match("^[a-zA-Zа-яА-Я]{2,15}( [a-zA-Zа-яА-Я]{2,15}){0,5}$", department):
            raise ValueError("Error! Department name should only contain letters and spaces.")
        
        try:
            salaryProcessed = float(salary)
        except ValueError:
            raise ValueError("Error! Salary must be a number!")
        if not 1000.00 <= salaryProcessed <= 77000.00:
            raise ValueError("Error! Salary must be from 1000.00 to 77000.00.")

    except ValueError as e:
        dpg.set_value("error", e)
        return
        
    with open("data.txt", "a") as file:
        file.write(f"{surname}\t{name}\t{department}\t{salary}\n")
    dpg.set_value("error", "")
    dpg.set_value("surname", "")
    dpg.set_value("name", "")
    dpg.set_value("department", "")
    dpg.set_value("salary", "")
        

def view_data():
    data = []
    try:
        with open("data.txt", "r") as file:
            for line in file:
                surname, name, department, salary = line.strip().split("\t")
                data.append(f"Employee: {surname} {name}, department: {department}, salary: {salary}")
            return data
    except FileNotFoundError:
        return "Error! File not found."