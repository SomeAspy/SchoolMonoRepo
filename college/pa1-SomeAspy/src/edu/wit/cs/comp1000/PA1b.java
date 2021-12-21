package edu.wit.cs.comp1000;

import java.util.Scanner;

/**
 * Does the opposite of PA1a
 * @author Aiden Baker
 */
public class PA1b {

	/**
	 * does math for now?
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		System.out.print("Enter number of inches: ");
		int inches=input.nextInt();
		int yards=inches/36;
		inches=inches%36;
		int feet=inches/12;
		inches=inches%12;
		System.out.println("Yards: "+Integer.toString(yards));
		System.out.println("Feet: "+Integer.toString(feet));
		System.out.println("Inches: "+Integer.toString(inches));
		input.close();
	}

}
