def nand(a, b):
    return not (a and b)

def nor(a, b):
    return not (a or b)

def truth_table():
  
    print(" --------------------------------------------------------------------------------------------------------------") 
    print(" | x | y | z | x|y | y|z | (x|y)⊕(y|z) | y↓z | ¬(y↓z) | x∨¬(y↓z) | ((x|y)⊕(y|z))→(x∨¬(y↓z)) |") 
    print(" --------------------------------------------------------------------------------------------------------------") 

  
    all_zero = True
    all_one = True
    first_value = None
    last_value = None
    increasing = True
    previous_value = None

    for x in [False, True]: 
        for y in [False, True]: 
            for z in [False, True]: 
               
                x_or_y = x or y
                y_or_z = y or z
                x_or_y_xor_y_or_z = x_or_y != y_or_z
                y_nand_z = nand(y, z)
                not_y_nand_z = not y_nand_z
                x_or_not_y_nand_z = x or not_y_nand_z
                final_result = (x_or_y_xor_y_or_z <= x_or_not_y_nand_z)

                print(f" | {int(x)} | {int(y)} | {int(z)} |   {int(x_or_y)}   |   {int(y_or_z)}   |       {int(x_or_y_xor_y_or_z)}       |   {int(y_nand_z)}   |     {int(not_y_nand_z)}     |     {int(x_or_not_y_nand_z)}     |                {int(final_result)}               |")
                
              
                if final_result != 0:
                    all_zero = False
                if final_result != 1:
                    all_one = False
                if first_value is None:
                    first_value = final_result
                last_value = final_result
                if previous_value is not None and final_result < previous_value:
                    increasing = False
                previous_value = final_result

    print(" --------------------------------------------------------------------------------------------------------------")


    print("-----------------------------------------------------------------")

    if all_zero:
        print("Переменные x, y и z фиктивные")
    elif all_one:
        print("Переменные x, y и z фиктивные")
    else:
        print("Переменные x, y и z существенные")

    print("-----------------------------------------------------------------")

    if first_value == 0:
        print("Функция принадлежит классу T0")
    elif first_value == 1:
        print("Функция не принадлежит классу T0")
        
    if last_value == 0:
        print("Функция не принадлежит классу T1")
    elif last_value == 1:
        print("Функция принадлежит классу T1")

    if increasing:
        print("Функция принадлежит классу M")
    else:
        print("Функция не принадлежит классу M")

truth_table()
