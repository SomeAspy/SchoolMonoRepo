type = input("enter int for integer output, or flt for float output.\n")
if type=="int":
    try:    
        print("\n"+str(int(int(input("Number\n"))/2)))
    except:
        print("\nYou broke it.")
elif type=="flt":
    try:
        print("\n"+str(float(int(input("Number\n"))/2)))
    except:
        print("\nYou broke it.")
else:
    print("\nYou Had 2 options.")
