#Aiden B.
#3/9/2021
#Lab 2.03

from time import sleep
def crudeLoop():
    try:
        global x,y,z
        x=int(input("what is x?\n"))
        y=int(input("what is y?\n"))
        z=int(input("what is z?\n"))
    except:
        print("ideally, your triangle will be made up of numbers.\n...\nYou also don't have a choice.")
        crudeLoop()
crudeLoop()
if (x+y)>z and(x+z)>y and(y+z)>x:
    print("perimeter of the triangle is "+str(x+(y+z)));sleep(2)
    if x*x+y*y==z*z:
        print("This is a right triangle!");sleep(2)
    if x==y==z:
        print("This is an equilateral triangle");sleep(2)
    elif z==x or z==y or x==y:
        print("This is an isosceles triangle");sleep(2)
    else:
        print("This is a scalene triangle");sleep(2)
else:
    print("Sorry, those inputs don't make a triangle.")