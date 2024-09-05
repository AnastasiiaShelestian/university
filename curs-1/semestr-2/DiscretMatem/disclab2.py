
 
print(" --------------------------------------------------------------------------------------------------") 
print(" | P | Q | R | ¬P | ¬R | (P->Q) | (Q->R) | (P->Q)->(Q->R) | (¬R->¬P) | ((P->Q)->(Q->R))->(¬R->¬P) |") 
print(" --------------------------------------------------------------------------------------------------") 

for P in [False, True]: 
    for Q in [False, True]: 
        for R in [False, True]: 
                

                not_R = not R
                not_P = not P

                P_implicatia_Q = not P or Q 

                Q_implicatia_R = not Q or R


                P_Q_implies_Q_R = not (P_implicatia_Q) or Q_implicatia_R

           
                not_R_implies_not_P = not not_R or not_P

          
                final_result =  not P_Q_implies_Q_R or not_R_implies_not_P

  
                print(f" | {int(P)} | {int(Q)} | {int(R)} |  {int(not P)} |  {int(not R)} |    {int(P_implicatia_Q)}   |   {int(Q_implicatia_R)}    |       {int(P_Q_implies_Q_R)}        |    {int(not_R_implies_not_P)}     |              {int(final_result)}             |")
print(" --------------------------------------------------------------------------------------------------")

