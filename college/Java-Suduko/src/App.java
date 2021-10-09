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
            System.out.print("EDITING MODE\nYou may:\n(R)eturn to main menu\n(C)heck board for errors\n(S)elect a block to edit\n");
            switch(input.nextLine().toLowerCase()){
                case"r":case"return":return;
                case"c":case"check":checkBoard();break;
                case"s":case"select":edit();break;
                default:System.out.println("Oops! That's not an option!");
            }
        }
        
    }

    static void solveBoard(){

    }

    static void edit(){

    }

    static void checkBoard(){

    }
}
