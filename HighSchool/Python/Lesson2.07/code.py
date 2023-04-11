# Aiden B.
# Lesson 2.07
# 3/23/2021

# Unicode underline \u0332

import re #import regex lib

plan=[""] # Create empty list
plan.pop()
actions=[""]

# def undo():pass

def modify():
    cache=input("What would you like to add or remove from the list?\f")
    global plan
    if cache in plan:
        if input("It seems "+cache+" is already in the list. would you like to remove it? Y\u0332es/N\u0332o or enter any character to cancel.\f").lower()[0]=="y":plan.remove(cache)
        else:pass
    else:plan.append(cache)


def InputAction():
    global plan # external vars
    action=input("C\u0332lear, V\u0332iew, Q\u0332uit, M\u0332odify\f").lower() # take input and make it lowercase
    if bool(re.match(r"modify|c(?:lear)?|undo|quit|view|[mquv]",action)):action=action[0] # check if the input matches regex, and then remove all but the first character
    else:
        print("Invalid Selection.")
        InputAction() # retry
    if action=="c":
        if input("Are you sure you want to clear the list? Y\u0332es/N\u0332o or enter any character to cancel.\f").lower()[0]=="y":plan=[""];plan.pop() # double check.
        InputAction()
    elif action=="v":[print(str(plan.index(i)+1)+". "+i) for i in plan];InputAction() # This is probably a terrible way of listing the items and adding numbers.
    elif action=="q":
        if input("Are you sure you want to quit? This will also clear your list! Y\u0332es/N\u0332o or enter any character to cancel.\f").lower()[0]=="y":quit()
        else:InputAction()
    elif action=="m":
        modify()
        InputAction()
    # elif action=="u":
    #    undo()
    #    InputAction

InputAction()