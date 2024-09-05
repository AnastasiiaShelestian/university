
class Person:

    def __init__(self, name, surname, id):
        self.name = name
        self.surname = surname
        self.id = id
    def toString(self):
        return 'Name: {}. Surname: {}. Id: {}.'.format(self.name, self.surname, self.id)

class Order:
    def __init__(self, name_payer, surname_payer, id_payer, name_recipient, surname_recipient, id_recipient, id, sum):
        self.payer = Person(name_payer, surname_payer, id_payer)
        self.recipient = Person(name_recipient, surname_recipient, id_recipient)
        self.id = id
        self.sum = sum

    def toString(self):
        return 'Id order: {}. Sum order: {}. \nPayer: {} \nRecipient: {}'.format(self.id, self.sum, self.payer.toString(), self.recipient.toString())

def safeIntInput(message, errorMessage):
    flag = False
    number = 0
    while(not flag):
        number = input(message + "\n")
        try:
            number = int(number)
            flag = True
        except ValueError:
            print("\n" + errorMessage + "\n")
            flag = False
    return number

def inputData():
    payer_name = input("Enter name payer \n")
    payer_surname = input("Enter surname payer \n")
    payer_id = safeIntInput("Enter ID payer", "Payer ID must be only number! Try again")
    
    recipient_name = input("Enter name recipient \n")
    recipient_surname = input("Enter surname recipient \n")
    recipient_id = safeIntInput("Enter ID recipient", "Recipient ID must be only number! Try again")
    

    sum = safeIntInput("Enter sum", "Sum must be only number! Try again")
    id = safeIntInput("Enter order id", "ID must be only number! Try again")

    return Order(payer_name, payer_surname, payer_id, recipient_name, recipient_surname, recipient_id, id, sum)

def newArray(size):
    newArray = []
    for i in range(size):
        print("\nEnter data for order", format(i + 1))
        newArray.append(inputData())
    sortedArr = sorted(newArray, key=lambda order: order.payer.surname)   
    
    with open("Order.txt", "a") as file:
        for element in sortedArr:
            file.write(element.toString())
    
    return sortedArr
      
def getTotalSum(arr, id):
    sum = 0
    flag = False
    for order in arr: 
        if id == order.payer.id:
            sum += order.sum
            flag = True
    if flag: 
        print("Total sum for payer id", format(id), "is", format(sum))
    else:
        print("No payer with id", format(id), "found")
    
  
arr = newArray(2)
id = safeIntInput("Enter the id of a person to calculate the order sum \n", "Error! Id must be a number!")

getTotalSum(arr, id)