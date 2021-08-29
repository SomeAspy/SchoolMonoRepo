#   Aiden B.
#   Lab2.05
#   3/9/2021
#
#   info:
#   underline in unicode \u0332

#   BOARD
#   A1|A2|A3
#   B1|B2|B3
#   C1|C2|C3

# Import the RegEx library
import re

# Blank out variables and define them
a1=a2=a3=b1=b2=b3=c1=c2=c3=" "

# apparently you cannot string lists together like above.
Xclaimed=[""]
Oclaimed=[""]

# Build and display the board
def PrntBoard(LastSet=True,BoardFormat=""):
    board="\n "+a1+"|"+a2+"|"+a3+"\n "+b1+"|"+b2+"|"+b3+"\ne "+c1+"|"+c2+"|"+c3
    # Add underline to all characters until we hit "e"
    for i in board:
        if i=="e":
            LastSet=False
        elif LastSet:
            BoardFormat+=i+"\u0332"
        elif LastSet==False:
            BoardFormat+=i
    print(BoardFormat)

# Change position given to symbol given
def Place(pos, symbol):
    # Reference variables outside the function
    global a1,a2,a3,b1,b2,b3,c1,c2,c3
    if pos=="a1":
        a1=symbol
    elif pos=="a2":
        a2=symbol
    elif pos=="a3":
        a3=symbol
    elif pos=="b1":
        b1=symbol
    elif pos=="b2":
        b2=symbol
    elif pos=="b3":
        b3=symbol
    elif pos=="c1":
        c1=symbol
    elif pos=="c2":
        c2=symbol
    elif pos=="c3":
        c3=symbol

# Check if the space given is claimed
def IsOpen(space):
    if space in Xclaimed or space in Oclaimed:
        return False
    else:
        return True

# Player's Turn
def PTurn(symbol):
    toCheck=input("Please choose an area to claim\f").lower()
    # check if input matches RegEx
    if bool(re.match(r"[a-c][1-3]", toCheck)):
        if IsOpen(toCheck):
            global SelectedSpace
            SelectedSpace=toCheck
            Place(SelectedSpace, symbol)
            # Add the given space to the list of claimed spaces depending on which symbol it is
            if symbol=="X":
                Xclaimed.append(SelectedSpace)
            elif symbol=="O":
                Oclaimed.append(SelectedSpace)
            PrntBoard()
        else:
            print("That space seems to be occupied! Please input an open space!")
            # Retry
            PTurn(symbol)
    else:
        print("That isn't a valid space, please double check your input!")
        PTurn(symbol)

# Check for player win conditions
def XWinCheck():
    if "a1"in Xclaimed and"b1"in Xclaimed and"c1"in Xclaimed:
        return True
    elif "a2"in Xclaimed and"b2"in Xclaimed and"c2"in Xclaimed:
        return True
    elif "a3"in Xclaimed and"b3"in Xclaimed and"c3"in Xclaimed:
        return True
    elif "a1"in Xclaimed and"a2"in Xclaimed and"a3"in Xclaimed:
        return True
    elif "b1"in Xclaimed and"b2"in Xclaimed and"b3"in Xclaimed:
        return True
    elif "c1"in Xclaimed and"c2"in Xclaimed and"c3"in Xclaimed:
        return True
    elif "a1"in Xclaimed and"b2"in Xclaimed and"c3"in Xclaimed:
        return True
    elif "a3"in Xclaimed and"b2"in Xclaimed and"c1"in Xclaimed:
        return True
    else:
        return False

# Check for Computer win conditions
def OWinCheck():
    if "a1"in Oclaimed and"b1"in Oclaimed and"c1"in Oclaimed:
        return True
    elif "a2"in Oclaimed and"b2"in Oclaimed and"c2"in Oclaimed:
        return True
    elif "a3"in Oclaimed and"b3"in Oclaimed and"c3"in Oclaimed:
        return True
    elif "a1"in Oclaimed and"a2"in Oclaimed and"a3"in Oclaimed:
        return True
    elif "b1"in Oclaimed and"b2"in Oclaimed and"b3"in Oclaimed:
        return True
    elif "c1"in Oclaimed and"c2"in Oclaimed and"c3"in Oclaimed:
        return True
    elif "a1"in Oclaimed and"b2"in Oclaimed and"c3"in Oclaimed:
        return True
    elif "a3"in Oclaimed and"b2"in Oclaimed and"c1"in Oclaimed:
        return True
    else:
        return False

# End the game and display winner
def WinCheck():
    if OWinCheck():
        print("O Wins!")
        # End the script
        quit()
    elif XWinCheck():
        print("X Wins!")
        quit()
    else:
        pass

# Loop claiming and check for win.
def GameLoop():
    PTurn("X")
    WinCheck()
    PTurn("O")
    # CTurn()
    WinCheck()
    GameLoop()

# Run the game
print("How To Play:\nSpots on the board are named A1-C3, with A being the top row and C being the bottom.")
PrntBoard()
GameLoop()
