import ioemployees
import analysedata

def main():
    while True:
        print("\nМеню:")
        print("1. Ввод данных в файл")
        print("2. Просмотр данных из файла")
        print("3. Вывод средней зарплаты в компании")
        print("4. Вывод сотрудника с самой большой зарплатой в компании")
        print("5. Вывод сотрудника с самой маленькой зарплатой в компании")
        print("6. Вывод средней зарплаты по департаменту")
        print("7. Выход из программы\n")
        
        choice = input("Выберите опцию (1-7): ")
        print("\n")
        
        if choice == "1":
            ioemployees.input_data()
        elif choice == "2":
            ioemployees.view_data()
        elif choice == "3":
            analysedata.average_salary()
        elif choice == "4":
            analysedata.biggest_salary()
        elif choice == "5":
            analysedata.smallest_salary()
        elif choice == "6":
            analysedata.average_salary_by_department()
        elif choice == "7":
            print("Программа завершена.")
            break
        else:
            print("Ошибка! Введите число от 1 до 7 для выбора опции.")

if __name__ == "__main__":
    main()
