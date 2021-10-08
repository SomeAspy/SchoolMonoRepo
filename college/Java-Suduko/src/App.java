import java.util.Scanner;
import java.util.ArrayList;

public class App {
    public static ArrayList<Integer> rowA,rowB,rowC,rowD,rowE,rowF,rowG,rowH,rowI;
    public static void main(String[] args) throws Exception {
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
        


        printBoard();
    }
    static void printBoard(){
        String board=rowA.toString()+rowB.toString()+rowC.toString()+rowD.toString()+rowE.toString()+rowF.toString()+rowG.toString()+rowH.toString()+rowI.toString();
        board=board.replace(", ","    ");
        board=board.replace("[","");
        board=board.replace("]","\n\n");
        System.out.print(board);//NOSONAR
    }
}
