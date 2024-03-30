greet_user = lambda name : print('Hello My Dear, ', name)
user_name = input("What is your name? ")
greet_user(user_name)


list = [(1,3),(3,6),(22,8),(5,4),(2,18),(30,30),(9,7)]
sorted_list = sorted(list, key = lambda x: x[1])
print(sorted_list)

list = [(1,3),(3,6),(22,8),(5,4),(2,18),(30,30),(9,7)]
sorted_list = sorted(list, key = lambda x: x[0])
print(sorted_list) 