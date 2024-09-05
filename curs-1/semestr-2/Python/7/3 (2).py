import math

def calculate_fall_time(height):
    g = 9.8
    fall_time = math.sqrt((2 * height) / g)
    return fall_time

height = 0
running = True
while running:
    height = input("Введите высоту в метрах: ")
    if not height.replace('.', '', 1).isdecimal() or float(height) <= 0:
        print("Высота должна быть положительным числом.")
        continue
    else:
        running = False

fall_time = calculate_fall_time(float(height))
print(f"Время падения объекта с высоты {height} м: {fall_time:.2f} секунд")
