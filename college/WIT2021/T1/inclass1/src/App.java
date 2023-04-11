import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("give 3 inputs");
        Scanner input=new Scanner(System.in); 
        int out=0;
        int num1=input.nextInt();
        int num2=input.nextInt();
        int num3=input.nextInt();
        input.close(); 
        out=num1+num2+num3;
        out=out/3;
        System.out.println(out);

    }
}
