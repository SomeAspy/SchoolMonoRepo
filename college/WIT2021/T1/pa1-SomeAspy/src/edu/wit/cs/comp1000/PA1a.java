package edu.wit.cs.comp1000;
import java.util.Scanner;
/**
 * ideally this does a thing like adding inches or something
 * @author Aiden  
 */
public class PA1a {

	/**
	 * asks for inputs and magically uses inefficient code to turn it into another number
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		System.out.print("Enter number of yards: ");
		int yards=input.nextInt();
		System.out.print("Enter number of feet: ");
		int feet=input.nextInt();
		System.out.print("Enter number of inches: ");
		int inches=input.nextInt();
		System.out.println("Total number of inches: "+Integer.toString((((yards*3)+feet)*12)+inches));
		input.close();
	}

}
