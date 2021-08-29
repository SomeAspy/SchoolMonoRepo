# Aiden B.
# 4/8/2021
# Lab3.03 REWRITE

# Import shuffle
from random import shuffle
# Declare Vars
CPUDeck=[]
PlayerDeck=[2,3,4,5,6,7,8,9,10,11,12,14]
PlayerName=input("What is your name?\f")
WarCache=[]
ClaimString=""
# Setup Decks with appropriate cards + Joker
for x in range(2):PlayerDeck.extend(PlayerDeck) # Duplicate the deck and add it to itself twice to get 52 cards
for x in range(2):PlayerDeck.append(15) # Add the Joker to the deck twice
shuffle(PlayerDeck)
while not len(CPUDeck)==27:CPUDeck.append(PlayerDeck.pop()) # remove one card off the end and put it on the CPU deck until the CPU has 27 cards
def Card(Value): # Converts cards to their Value if applicable
    if Value<=10:return(Value)
    elif Value==11:return("Jack")
    elif Value==12:return("Queen")
    elif Value==13:return("King")
    elif Value==14:return("Ace")
    elif Value==15:return("Joker")
def WarCheck(CPU=False):
    if len(WarCache)!=0:
        if CPU:
            print("The computer won the war! They got:")
            for x in WarCache:print(Card(x))
            CPUDeck.extend(WarCache)
        else:
            print("{} won the war! They got:".format(PlayerName))
            for x in WarCache:print(Card(x))
            PlayerDeck.extend(WarCache)
        WarCache.clear()
while len(CPUDeck)>0 and len(PlayerDeck)>0:
    if CPUDeck[0]>PlayerDeck[0]: # CPU gain
        print("{} plays {} while the computer plays {}. The computer takes the cards!".format(PlayerName,Card(PlayerDeck[0]),Card(CPUDeck[0])))
        CPUDeck.append((PlayerDeck.pop(0)))
        CPUDeck.append((CPUDeck.pop(0)))
        WarCheck(True)
    elif PlayerDeck[0]>CPUDeck[0]: # Player gain
        print("{} plays {} while the computer plays {}. {} takes the cards!".format(PlayerName,Card(PlayerDeck[0]),Card(CPUDeck[0]),PlayerName))
        PlayerDeck.append((CPUDeck.pop(0)))
        PlayerDeck.append((PlayerDeck.pop(0)))
        WarCheck()
    else:
        print("Both players play {}! This is war!".format(Card(PlayerDeck[0])))
        for x in range(3):
            WarCache.append((PlayerDeck.pop(0)))
            WarCache.append((CPUDeck.pop(0)))
if len(CPUDeck)==0:print("{} wins!".format(PlayerName))
else:print("The computer wins!")