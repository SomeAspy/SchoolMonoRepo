#Aiden B.
#Lab2.04
#3/9/2021

prizes=["nothing","death","idk","money","get well soon card","grenade","a dead end job","something","used gum","help me im being forced to come up with prizes oh god they are coming please help ahhhhhhhhhhhhhh"]
def crudeLoop():
    try:
        global door
        door=int(input("Pick a number 1-10\n"))
        if door>10 or 1>door:
            print("ONE THROUGH TEN\n")
            crudeLoop()
        elif door<=10 and door>=1:
            print("you win: "+prizes[door-1])
    except:
        print("it has to be a NUMBER\n")
        crudeLoop()
crudeLoop()