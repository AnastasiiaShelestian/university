#задание 1.3
name = input("Введите ваше имя : ")
print("Привет, " + name)

#задание 1.4, 1.5
int1 = 1
print("Число 7 принадлежит ",type(int1))
float1 = 1.5
print("Число 1.5 принадлежит",type(float1))
string = "Казнить нельзя помиловать"
print("Это однострочное предложение принадлежит",type(string))
longstr = """Казнить
нельзя
помиловать"""
print("Это многострочное предложение принадлежит",type(longstr))

#задание 1.6
string1 = "строка, длину которой нужно определить :с" #41
print(len(string1))

#задание 1.7
print(string1.upper())

#задание 1.8
print(string[8:13])

#задание 9
txt = "More results from text..."
substr = txt[4:12]
print(substr)
print(substr.strip())
#в 30 строке выведется _results
#в 31 строке лишние пробелы уберутся из-за метода strip

#задание 10
txt = "More results from text..."
print(txt.split("e"))
#метод split в этом случае разбивает строку на подстроки

#задание 11
age = 36
txt = f"My name is Mary, and I am {age}"
print(txt)
#на месте фигурных скобок выведется число - возраст



