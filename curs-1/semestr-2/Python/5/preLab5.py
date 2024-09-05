

import re

def check_phone_number(phone_number):
    pattern = r'^((\+|00)373)?\d{8}$'
    
    try:
        match = re.match(pattern, phone_number)
        if match:
            print("Номер телефона введен корректно.")
        else:
            print("Номер телефона введен некорректно.")
    except Exception as e:
        print("Произошла ошибка при проверке номера телефона:", e)

def main():
 
    phone_number = input("Введите номер телефона: ")

    check_phone_number(phone_number)

if __name__ == "__main__":
    main()