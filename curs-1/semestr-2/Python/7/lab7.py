import datetime
import calendar
import math
import re

birth_date = ""
running = True
while running:
    birth_date = input("Введите дату рождения в формате YYYY-MM-DD: ")
    if re.match(r'^\d{4}-\d{2}-\d{2}$', birth_date):
        running = False
    else:
        print("Неправильный формат даты. Попробуйте снова.")

year_of_birth, month_of_birth, day_of_birth = map(int, birth_date.split('-'))
today = datetime.date.today()
age_in_days = (today - datetime.date(year_of_birth, month_of_birth, day_of_birth)).days
print(f"Ваш возраст в днях: {age_in_days} дней")


def get_weekday(year, month, day):
    try:
        day_of_week = calendar.weekday(year, month, day) # получаем номер дня недели
        weekdays = ["понедельник", "вторник", "среда", "четверг", "пятница", "суббота", "воскресенье"] # наименование 
        return weekdays[day_of_week]
    except ValueError:
        return None

running = True
while running:
    year = input("Введите год: ")
    if not year.isdecimal():
        print("Пожалуйста, введите валидное число!")
        continue
    month = input("Введите месяц: ")
    if not month.isdecimal() or int(month) < 1 or int(month) > 12:
        print("Пожалуйста, введите валидное число!")
        continue
    day = input("Введите день: ")
    if not day.isdecimal() or int(day) < 1 or int(day) > 31:
        print("Пожалуйста, введите валидное число!")
        continue
    weekday = get_weekday(int(year), int(month), int(day))
    if weekday is None:
        print("Неверная дата! Пожалуйста, введите корректную дату.")
        continue
    print(f"Это {weekday}")
    running = False



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

