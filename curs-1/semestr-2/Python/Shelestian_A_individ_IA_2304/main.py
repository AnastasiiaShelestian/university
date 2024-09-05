import ioemployees
import analysedata
import dearpygui.dearpygui as dpg

def main(): 
    dpg.create_context()
    dpg.create_viewport(title='Alternative Anastasia', width=1200, height=900)
    dpg.setup_dearpygui()

    with dpg.font_registry():
        default_font = dpg.add_font("Roboto-Regular.ttf", 20)

    with dpg.window(label="Employee Management", width=1200, height=720):
        global text
        global employee_list

        def show_employees():
            data = ioemployees.view_data()
            list = "\n".join(data) 
            dpg.set_value(employee_list, list)

        def show_lowest_salary(): 
            data = analysedata.smallest_salary()
            dpg.set_value(text, data)
        
        def show_highest_salary(): 
            data = analysedata.biggest_salary()
            dpg.set_value(text, data)

        def show_average_salary(): 
            data = analysedata.average_salary()
            dpg.set_value(text, data)
        
        def show_average_per_department(): 
            data = analysedata.average_salary_by_department()
            list = "\n".join(data)
            dpg.set_value(text, list)
        
        dpg.bind_font(default_font)
        dpg.add_text("Employees list:")
        employee_list = dpg.add_text("")
        show_employees()
        dpg.add_text("\n")
        dpg.add_button(label="Update List", callback=show_employees, width=400, height=30)
        dpg.add_text("\n")
        dpg.add_button(label="Show Highest Salary", callback=show_highest_salary, width=400, height=30)
        dpg.add_button(label="Show Lowest Salary", callback=show_lowest_salary, width=400, height=30)
        dpg.add_button(label="Show Average Salary", callback=show_average_salary, width=400, height=30)
        dpg.add_button(label="Show Average Salary per Department", callback=show_average_per_department, width=400, height=30)
        dpg.add_text("\n")
        text = dpg.add_text("")
        dpg.add_text("\n")

        dpg.add_text("Add Employee:")
        dpg.add_input_text(label="Surname", tag="surname", width=400)
        dpg.add_input_text(label="Name", tag="name", width=400)
        dpg.add_input_text(label="Department", tag="department", width=400)
        dpg.add_input_text(label="Salary", tag="salary", width=400)
        dpg.add_button(label="Submit", callback=ioemployees.input_data, width=400, height=30)
        dpg.add_text("", tag="error")

    dpg.show_viewport()
    dpg.start_dearpygui()
    dpg.destroy_context()

if __name__ == "__main__":
    main()
