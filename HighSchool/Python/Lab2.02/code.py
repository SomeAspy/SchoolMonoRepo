# Aiden B.
# Lab 2.02
# 3/3/2021

pick=input("Which Program would you like to run?\n1. Can I be president?\n2. Can I ride the rollercoaster?\n3. ?????\n4. Examples\n")
if pick==1:
    try:
        print("You meet the requirements to run for president!" if int(input("Your Age\n"))>=35 and int(input("Years of residency in the US\n"))>=14 and input("Are you a natural born citizen? t/f\n")=="t" else "You do not meet the requirements to run for president...")
    except:
        print("One or more inputs was invalid!")
elif pick==2:
    pass
elif pick==4:
    a=100;b="science";c=True
    print("Example 1 prediction: true")
    print(a>75 and b=="science")
    print("Example 2 prediction: false")
    print(a>75 and b!="science")
    print("Example 3 prediction: true")
    print(a>75 or b!="science")
    print("Example 4 prediction: false")
    print(not c and a>75 and b=="science")
else:
    import rickroll