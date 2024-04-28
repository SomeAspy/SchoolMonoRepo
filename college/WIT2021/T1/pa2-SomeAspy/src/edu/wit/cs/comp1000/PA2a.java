package edu.wit.cs.comp1000;
import java.text.DecimalFormat;
import java.util.Scanner;


/**
 * @author Aiden  
 * 
 */
public class PA2a {
	public static double output,output2;
	/**
	 * Does a lot of complicated stuff like math, and... uh, math.
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		System.out.print("Enter a b c: ");
		Float a,b,c;
		a=input.nextFloat();
		b=input.nextFloat();
		c=input.nextFloat();
		input.close();
		if(0>Math.pow(b,2)-4*a*c){
			System.out.println("Roots: imaginary");
			System.exit(0);
		}else if(0==Math.pow(b,2)-4*a*c){
			output=-b/(2*a);
			System.out.println("Root: "+new DecimalFormat("#0.00").format(output));
		}else{
			output=1.00*(-b+(Math.sqrt(Math.pow(b,2)-(4*a*c))))/(2*a);
			output2=1.00*(-b-(Math.sqrt(Math.pow(b,2)-(4*a*c))))/(2*a);
			System.out.println("Roots: "+new DecimalFormat("#0.00").format(output2)+", "+new DecimalFormat("#0.00").format(output));
		}
			
	}

}
