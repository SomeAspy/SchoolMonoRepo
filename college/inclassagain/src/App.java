import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner input=new Scanner(System.in);
        double input_value;
        System.out.print("Please enter a number: ");
        input_value=input.nextDouble();
        if(input_value>100){
            System.out.println("That is greater than 100.");
        }else{
            System.out.println("That is less than or equal to 100.");
        }
        System.out.println("Thank you!");
        input.close();
    }
}
