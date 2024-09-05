def truth_table():

    print(" --------------------------------------------------------------------------------------------------") 
    print(" | P | Q | R | ¬P | ¬R | (P->Q) | (Q->R) | (P->Q)->(Q->R) | (¬R->¬P) | ((P->Q)->(Q->R))->(¬R->¬P) |") 
    print(" --------------------------------------------------------------------------------------------------") 

all_zero = True
all_one = True
first_value = None
last_value = None
increasing = True
previous_value = None

for P in [False, True]: 
    for Q in [False, True]: 
        for R in [False, True]: 
            not_R = not R
            not_P = not P
            P_implicatia_Q = not P or Q 
            Q_implicatia_R = not Q or R
            P_Q_implies_Q_R = not P_implicatia_Q or Q_implicatia_R
            not_R_implies_not_P = not not_R or not_P
            final_result = not P_Q_implies_Q_R or not_R_implies_not_P
            
            print(f" | {int(P)} | {int(Q)} | {int(R)} |  {int(not P)} |  {int(not R)} |    {int(P_implicatia_Q)}   |   {int(Q_implicatia_R)}    |       {int(P_Q_implies_Q_R)}        |    {int(not_R_implies_not_P)}     |              {int(final_result)}             |")
            
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

print(" --------------------------------------------------------------------------------------------------")

print("-----------------------------------------------------------------")

if all_zero:
    print("Переменные P, Q и R фиктивные")
elif all_one:
    print("Переменные P, Q и R фиктивные")
else:
    print("Переменные P, Q и R существенные")

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
