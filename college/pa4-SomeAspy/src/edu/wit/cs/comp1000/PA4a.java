package edu.wit.cs.comp1000;
import java.util.Scanner;
/**
 * @author Aiden Baker
 */
public class PA4a {
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		System.out.print("Enter the current price of the item: $");//NOSONAR
		double value=input.nextDouble(); //if we use floats and not doubles, this no work.
		System.out.print("Enter the number of years: ");//NOSONAR
		int years=input.nextInt();
		System.out.print("Enter the inflation rate as a percentage: ");//NOSONAR
		double rate=input.nextDouble();
		input.close();
		if(value<0){ //catch stupidity
			System.out.println("The current price must be at least 0!");//NOSONAR
			System.exit(1);
		}
		if(years<0){
			System.out.println("The number of years must be at least 0!");//NOSONAR
			System.exit(1);
		}
		if(rate<0){
			System.out.println("The inflation rate must be at least 0!");//NOSONAR
			System.exit(1);
		}
		rate/=100; //convert to decimal
		for(int i=0;i!=years;i++){//for amount of years do
			value*=(1+rate); //this math
		}
		String s="s";// s
		if(years==1){
			s="";// s bad
		}
		System.out.println("After "+years+" year"+s+", the price will be $"+String.format("%.2f",value));//NOSONAR
		
	}

}
