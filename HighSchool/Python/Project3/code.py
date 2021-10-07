# Aiden B.
# 4/9/2021
# Oregon Trail
# Imports
from random import randrange, random, choice
from re import match
from datetime import datetime, timedelta
# Init Starting Vars
Health=5
Food=500
Day=0
DistanceLeft=2000
def DateStr():return (datetime(1848,3,1)+timedelta(Day)).strftime("%A, %B %d, %Y") # Format the date and add the days to it.
Name=input("Input a name:\f")
def Alive(): # Determine whether the player is still alive
    if DistanceLeft<=0:
        print("Congrats! {} made it to Oregon in {} days!".format(Name,Day))
        return False
    elif Health<=0:
        print("{} died on {}. Remember to keep an eye on your health!".format(Name,DateStr()))
        return False
    elif Food<=0:
        print("{} ran out of food and starved on {}. Remember to keep an eye on the amount of food you have!".format(Name,DateStr()))
        return False
    elif Day>305:
        print("{} did not make it to oregon in time".format(Name))
        return False
    else:return True
def update(action): # Operates the actions the player can take.
    global Food,Day,Health,DistanceLeft # Get external vars
    if action==1: # Travel
        Traveled=randrange(30,60) # choose a random number from the defined range
        TimeUsed=randrange(3,7)
        DistanceLeft-=Traveled # Determine distance left by subtracting the amount traveled
        Day+=TimeUsed # add days used
        Food-=TimeUsed*5 # take food that was used (days*5)
        print("{} traveled {} miles in {} days, consuming {}lbs of food".format(Name,Traveled,TimeUsed,TimeUsed*5)) # tell the user the action
    elif action==2: # Rest
        TimeUsed=randrange(2,5)
        if Health!=5: # if health is not 5
            Health+=1 # then add 1 to health
        Food-=TimeUsed*4 # resting takes less food for those sweet, sweet bonus points
        Day+=TimeUsed
        print("{} rested for {} days, consuming {}lbs of food and now has {:.0%} health.".format(Name,TimeUsed,TimeUsed*5,Health/5)) # show the health as a percentage
    elif action==3: # Hunt
        TimeUsed=randrange(2,5)
        Food+=100-(TimeUsed*5)
        print("{} spent {} days hunting and found 100lbs of food! However, they ate {}lbs in the time it took.".format(Name,TimeUsed,TimeUsed*5))
    if random()<=.07: # 7% chance
        Health-=1 # take 1 off health
        print("{} got {} and was hurt! Their health is now {:.0%}!".format(Name,choice(["measles","a snake bite","typhoids","cholera","dysentery"]),Health/5)) # pick a random disease
    if random()<=.04: # 4% chance
        while True:
            try:args=int(input("{} has come across a river! Should they...\n1. Cross it\n2. Go around\f".format(Name)))
            except ValueError:
                print("The input must be a number!")
                continue
            if bool(match(r"[1-2]",str(args))):
                if args==1: # Crossing
                    if randrange(0,1)==0: # Success
                        print("{} crossed the river safely in one day, consuming 5lbs of food.".format(Name))
                        Food-=5
                        Day+=1
                        break
                    else: # Fail
                        print("{} capsized! The aftermath:".format(Name))
                        FoodLost=randrange(0,50)
                        if FoodLost>=1: # if food lost is more than or equal to one then continue
                            plural="" # grammar
                            if FoodLost>1:plural="s" # if the food lost is more than one add an s
                            print("{} lost {}lb{} of food!".format(Name,FoodLost,plural))
                            Food-=FoodLost
                        TimeUsed=randrange(2,5)
                        Day+=TimeUsed
                        Food-=TimeUsed*5
                        print("{} Spent {} days cleaning up the mess and consumed {}lbs of food in the time it took.".format(Name,TimeUsed,TimeUsed*5))
                        Damage=randrange(0,1)
                        if Damage==1:
                            Health-=1
                            print("{} got hurt! Their health is now {:.0%}.".format(Name,Health/5))
                        break
                else: # Going around
                    TimeUsed=randrange(5-20)
                    print("{} makes it across the river in {} days, consuming {}lbs of food".format(Name,TimeUsed,TimeUsed*5))
                    Day+=TimeUsed
                    Food-=TimeUsed*5
                    break
            else:
                print("That isn't a valid option!")
                continue
def game(): # the game cycle
    while Alive(): # loop while alive returns true
        while True: # loop forever
            try:args=int(input("MENU\nType the number that corresponds with what you want to do.\n1. Travel\n2. Rest\n3. Hunt\n4. Status\n5. Help\n6. Quit\f")) #try to convert input to an int
            except ValueError: # if the input cannot be made into an int, its not an input we want, and will cause an error.
                print("The input must be a number!")
                continue # go back to the start of the loop
            if bool(match(r"[1-6]",str(args))):break # if the input matches regex, then exit the loop
            else: # if the input doesn't cause an error, but we don't want it, go to the start of loop
                print("That is not a valid option!")
                continue
        if bool(match(r"[1-3]",str(args))):update(args) # if our input matches an action, pass it to the updater
        elif args==4:print("{}'s Stats:\nHealth: {:.0%}\nRemaining Food: {}lbs\nDistance Traveled: {}mi\nDate: {}".format(Name,Health/5,Food,DistanceLeft,DateStr()))
        elif args==5:print("Welcome to Oregon Trail!\nTo play, you need to make it to oregon.\nYou can use travel to make your way torwards Oregon.\nYou can rest to regain health.\nHunting will get you food\nStatus shows your stats.")
        elif args==6:
            while True:
                if input("Are you sure you want to exit?\nYou will lose all progress!\nYes/No\f").lower()=="yes": # check if input matches yes
                    print("{} committed suicide on {} leaving behind {}lbs of food. They only had {}mi left to go...".format(Name,DateStr(),Food,DistanceLeft)) # tie up loose ends
                    exit("The user ended the game.") # Quit the game with a message
                else:
                    print("Canceled.")
                    break
game() # Execute