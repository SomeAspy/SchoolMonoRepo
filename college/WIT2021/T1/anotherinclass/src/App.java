import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner input=new Scanner(System.in);
        int x=15;
        if(x>0){
            System.out.println("x is positive");
        }else{
            System.out.println("x is non positive");
        }
        System.out.println("Thank you, and good night.");
        input.close();
    }
}
