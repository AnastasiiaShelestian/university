import calendar

def get_weekday(year, month, day):
    day_of_week = calendar.weekday(year, month, day)
    weekdays = ["понедельник", "вторник", "среда", "четверг", "пятница", "суббота", "воскресенье"]
    return weekdays[day_of_week]

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
    print(f"Это {weekday}")
    running = False
