from python import python


manager1 = python("Project 1", 10000)
manager2 = python("Project 2", 20000)


print("Менеджер 1:")
print("Название проекта:", manager1.project_name)
print("Бюджет:", manager1.budget)

print("\nМенеджер 2:")
print("Название проекта:", manager2.project_name)
print("Бюджет:", manager2.budget)


manager1.project_name = "Updated Project 1"
manager1.budget = 15000

manager2.project_name = "Updated Project 2"
manager2.budget = -5000  


print("\nОбновленные значения:")
print("Менеджер 1:")
print("Название проекта:", manager1.project_name)
print("Бюджет:", manager1.budget)

print("\nМенеджер 2:")
print("Название проекта:", manager2.project_name)
print("Бюджет:", manager2.budget)