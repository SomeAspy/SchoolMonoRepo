import java.util.Scanner;
import java.util.ArrayList;

public class App {
    public static ArrayList<Integer> rowA,rowB,rowC,rowD,rowE,rowF,rowG,rowH,rowI;
    public static void main(String[] args) throws Exception {
        setup();
        printBoard();
        System.out.println("Welcome to Aiden's Sudoku solver!");
        while(true){
            System.out.print("You may:\n(Q)uit, (E)dit board, (P)rint board, or (S)olve\n");
            Scanner input=new Scanner(System.in);
            String menu=input.nextLine().toLowerCase();
            switch(menu){
                case "q":case "quit":input.close();System.exit(1);break;
                case "e":case "edit":editBoard();break;
                case "p":case "print":printBoard();break;
                case "s":case "solve":solveBoard();break;
                default:System.out.println("Oops! That's not an option!");
            }
        }
    }
    
    static void setup(){
        //create values
        ArrayList<Integer>template=new ArrayList<>();
        for(int i=0; i<9; i++){
            template.add(0);
        }
        rowA=new ArrayList<>(template);
        rowB=new ArrayList<>(template);
        rowC=new ArrayList<>(template);
        rowD=new ArrayList<>(template);
        rowE=new ArrayList<>(template);
        rowF=new ArrayList<>(template);
        rowG=new ArrayList<>(template);
        rowH=new ArrayList<>(template);
        rowI=new ArrayList<>(template);
    }
    
    static void printBoard(){
        String board=rowA.toString()+rowB.toString()+rowC.toString()+rowD.toString()+rowE.toString()+rowF.toString()+rowG.toString()+rowH.toString()+rowI.toString();
        board=board.replace(", ","    ");
        board=board.replace("[","");
        board=board.replace("]","\n\n");
        System.out.print(board);
    }
    
    static void editBoard(){
        String editRow;
        int editindex;
        
    }

    static void solveBoard(){

    }
}
