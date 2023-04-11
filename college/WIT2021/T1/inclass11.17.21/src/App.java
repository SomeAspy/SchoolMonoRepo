import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;
public class App{
    public static void main(String[]args)throws Exception{
        PrintWriter fOut=new PrintWriter(new File("uwu.txt"));
        for(int i=1;i<=100;i++){fOut.println(i);}
        fOut.close();
        Scanner read=new Scanner(new File("uwu.txt"));
        while(read.hasNextLine()){System.out.println(read.nextLine());}
        read.close();
    }
}
