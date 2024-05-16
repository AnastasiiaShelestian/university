# список (упорядоченная и изменяемая коллекция данных)

arr1 = ["Luna", "Foxy", "Roxy", 22, 55, 100]
print(arr1)

print("What is the class: ")
print(type(arr1))

print("0 and 4 index:")
print(arr1[0], arr1[4])

print("Slise: ")
print(arr1[1:4])
print(arr1[0:1])

print("change value: ")
arr1[3] = "replacement"
print(arr1)

print("Function: ")

print("Number of elements in list: ")
print(len(arr1))

arrry = [1,1,1,]
arr1.extend(arrry)
print(arr1)

print("Metods: ")

arr1.append(666)
print(arr1)

arr1.remove(666)
print(arr1)

print()
print("------------------------------")
print()

arr2 = ("яблоко", 5, "груша", 1, "ананас", 3,)
print(arr2)
print("What is the class: ")
print(type(arr2))

print(arr2[0], arr2[5])
print(arr2)

print(arr2[2:4])
print(tuple(arr2[0]))

print("number of elements: " ,len(arr2))

del(arr2)

print()
print("---------------------------------")
print()

arr3 = {2,8,6,6,4,1,1,3,5,7,7,7,"ana"}
print(arr3)

# при выводе все повторяющиеся значения элементов удаляются

arr3.add(33)
print(arr3)

arr3.remove(7)
print(arr3)

print("number of elements : ", len(arr3))

print()
print("_______________________________")
print()


dicttext = {'name':'"Anastasiia"', 'author':'Shelestuan'}
dictnum = {'day':30, 'month':3, 'year':1996}
print(tuple(dicttext))
print(tuple(dictnum))
print(dicttext["author"]),(dictnum["year"])

print(dictnum.keys())
print(dicttext.values())


dicttext.update({'hair':"blond", 'aducation': "Law"})
print(dicttext)

print("number of elements dictionary : ", len(dicttext), ",", len(dictnum))

print(sorted(dicttext))

# задание 1f - поменять тип данных в другой, как это сделать и для чего 
print(list(arr3))

# нужно использовать определенные функции-конструкторы(int, float, str, list, dict)

# чтобы работать с элементами, которые принадлежат разным типам данных изначально

fruit = ["apple", "orange", "banana", "pineapple", "kiwi", "pear", "peah" ]
price = [50, 20, 15.5, 40, 35, 60, 100]
print (fruit)
print (price)

store = "{} cost {}, {} cost {}, {} cost {}. ".format(fruit[0], price[0],fruit[1], price[1],fruit[2], price[2])
print(store)

# задание 2b - пользователь вводит свой возраст, поменять тип данных, вывести какой будет возраст пользователя через 5 лет

age = input("Введите ваш возраст : ")
agemain = int(age)
print("Через пять лет вам будет", agemain + 5)

# задание 2c - использовать операторы принадлежности in или not in в коде
answer = input("fruit or something else...? - ")

if 'fruit' in answer :
    print("right choice")

if 'fruit' not in answer :
    print("wrong choice")


