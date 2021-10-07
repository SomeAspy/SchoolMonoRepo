# Aiden B.
# 2/23/2021
# lab 1.04

# Part 1 or 2

part=input("run part 1 or 2?")

print("I am a genie. You have three wishes.")
w1=input("What would you like to wish for?\n")
w2=input("What would you like to wish for?\n")
w3=input("What would you like to wish for?\n")

if part=="1":
    print("Your wishes are "+w1+", "+w2+", and "+w3);
elif part=="2":
    print("Your wishes are "+w2+", "+w3+", and "+w1);
else:
    print("\nYou were given 2 options, and you chose neither. Great job.");