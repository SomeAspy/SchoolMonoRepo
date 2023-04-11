# Aiden B.
# Lab 3.02
# 4/5/2021
# this program is stupidly simple.
def ex1():
    def bday(name):print("Happy birthday, "+name+". I'm too lazy to insert the whole happy birthday song into this.")
    bday(input("Name?\f"))
def ex2():
    from random import choice # import choice function
    cards=["Ace","King","Queen","Jack","Joker",2,3,4,5,6,7,8,9,10]
    suits=[" of Hearts"," of Spades"," of Diamonds"," of Clubs"]
    SCard=str(choice(cards)) # make it a string and choose from cards
    SSuit=choice(suits)
    if SCard=="Joker":SSuit="" # Yeet the suit if the card is a joker
    AnMode=" " # put a space after a
    if SCard=="Ace"or SCard=="8":AnMode="n " # put an n after a
    print("You got a"+AnMode+SCard+SSuit) # combine it all
def select():
    selection=int(input("for Exercise 1 input 1. for exercise 2 then type 2.\f"))
    if selection==1:ex1()
    elif selection==2:ex2();ex2();ex2();ex2();ex2() # I don't feel like making a loop function right now.
    else: # prevent stupidity
        print("Haha, very funny. input a valid option.\n")
        select()
select()