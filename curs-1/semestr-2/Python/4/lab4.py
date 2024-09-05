# Создать калькулятор «идеального веса», используя формулу Лоренса.

year = int(input("Введите ваш возраст в годах: "))
if year < 20 or year > 80:
    print("Ошибка: Возраст должен быть от 20 до 80 лет.")
    exit()

height = int(input("Введите ваш рост в см: "))
if height < 100 or height > 250:
    print("Ошибка: Рост должен быть от 100 до 250 см.")
    exit()

weight = int(input("Введите ваш вес в кг: "))
if weight < 50 or weight > 150:
    print("Ошибка: Вес должен быть от 50 до 150 кг.")
    exit()

gender = input("Введите ваш пол (М или Ж): ").strip().lower()
if gender not in ['м', 'ж', 'm', 'f']:
    print("Ошибка: Некорректный ввод пола. Введите 'М'/'Ж' или 'M'/'F'.")
    exit()

if gender in ['м', 'm']:
    perfect_weight = height - 100 - ((height - 150) / 4 + (year - 20) / 4)
elif gender in ['ж', 'f']:
    perfect_weight = height - 100 - ((height - 150) / 2.5 + (year - 20) / 6)

print("\nИдеальный вес =", int(perfect_weight), "кг.")

if weight > int(perfect_weight):
    print("Возможно стоит сбросить вес. Или нет=)")
elif weight == int(perfect_weight):
    print("У вас идеальный вес.")
else:
    print("Возможно стоит набрать вес. Или нет=).")
