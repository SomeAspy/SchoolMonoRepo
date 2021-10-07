import java.util.Scanner;
public class App {
    public static void main(String[] args) throws Exception {
        System.out.print("Please provide a number: ");
        Scanner input=new Scanner(System.in);
        if(input.nextInt()%2==0){
            System.out.println("The number provided is even");
        }else{
            System.out.println("The number provided is not even");
        }
        input.close();
    }
}
