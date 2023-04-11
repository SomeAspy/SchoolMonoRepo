import java.util.Arrays;
import java.util.Scanner;

public class App {
    public static int[][] board={
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
    };
    public static Scanner input=new Scanner(System.in);
    public static void main(String[] args) throws Exception {
        printBoard();
        System.out.println("Welcome to Aiden's Sudoku solver!");
        while(true){
            System.out.print("You may:\n(Q)uit\n(E)dit the board\n(P)rint the board\n(S)olve the board\n");
            switch(input.nextLine().toLowerCase()){
                case"q":case"quit":
                    System.out.println("Are you sure you want to quit? You will lose everything!\n(Y)es\n(N)o");
                    switch(input.nextLine().toLowerCase()){
                        case"y":case"yes":input.close();System.exit(1);
                        default:System.out.println("Canceled.");
                    }
                    break;
                case"e":case"edit":editMenu();break;
                case"p":case"print":printBoard();break;
                case"s":case"solve":solveBoard();break;
                default:System.out.println("Oops! That's not an option!");
            }
        }
    }


    static void printBoard(){
        System.out.println("  A   B   C   D   E   F   G   H   I\n  "+(Arrays.deepToString(board)).replace(", ", "   ").replace("[", "").replace("] ", "\n\n").replace("]]", "").replace("0", "X"));
    }

    static void editMenu(){
        System.out.println("Entering editing mode...");
        while(true){
            System.out.println("EDITING MODE\nYou may:\n(R)eturn to main menu\n(C)heck board for errors\n(S)elect a block to edit");
            switch(input.nextLine().toLowerCase()){
                case"r":case"return":return;
                case"c":case"check":
                    if(boardOK()){
                        System.out.println("Board is solvable!");
                    }else{
                        System.out.println("Board is not solvable!");
                    }
                break;
                case"s":case"select":edit();break;
                default:System.out.println("Oops! That's not an option!");
            }
        }

    }

    static void solveBoard(){
        if(boardOK()){

        }else{
            System.out.println("This board isn't solvable!");
        }
    }

    static void edit(){
        boolean editing=true;
        while(editing){
            System.out.println("Select a column (A-I) or (R)eturn...");
            int column; //Actual column
            switch(input.nextLine().toLowerCase()){
                case"r":case"return":return;
                case"a":column=0;break;
                case"b":column=1;break;
                case"c":column=2;break;
                case"d":column=3;break;
                case"e":column=4;break;
                case"f":column=5;break;
                case"g":column=6;break;
                case"h":column=7;break;
                case"i":column=8;break;
                default:System.out.println("That is not a valid column!");column=9;
            }
            if(column==9){
                continue;
            }
            int row=-1;
            boolean badRow=true;
                while(badRow){
                System.out.println("Select a row (1-9) or 0 to cancel...");
                row=input.nextInt();
                if(row==0){
                    return;
                }
                if(row>9||row<1){
                    System.out.println("That's not a valid row!");
                    continue;
                }else{
                    row-=1; //since java counts from 0
                    badRow=false;
                }
            }
            System.out.println("Editing "+column+row+".");
            while(true){
                System.out.println("Choose a number to write to the block or press 0 to cancel...");
                int fill=input.nextInt();
                if(fill==0){
                    return;
                }
                if(fill>9||fill<1){
                    System.out.println("That is not a valid number for this board!");
                    continue;
                }else{
                    board[row][column]=fill;
                    printBoard();
                    return;
                }
            }
        }
    }

    static boolean boardOK(){
        boolean OK=true;
        for(int[]row:board){//loop through rows
            for(int num:row){
                int counter;
                for(counter=0;counter<9;counter++){
                    for(int x:row){
                        if(x==num){//row check
                            OK=false;
                        }
                    }
                    if(num==row[counter]){//column check
                        OK=false;
                    }
                }
            }
        }
        return OK;
    }
}
