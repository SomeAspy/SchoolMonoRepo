package edu.wit.cs.comp1000;
import java.util.Scanner;
public class LA1a {

	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		System.out.print("Enter five numbers: ");
		double n1=input.nextDouble();
		double n2=input.nextDouble();
		double n3=input.nextDouble();
		double n4=input.nextDouble();
		double n5=input.nextDouble();
		input.close();
		System.out.println("Sum: "+String.format("%.2f",n1+n2+n3+n4+n5));
		double mean=(n1+n2+n3+n4+n5)/5;
		System.out.println("Mean: "+String.format("%.2f",mean));
		System.out.println("Population Standard Deviation: "+String.format("%.2f",Math.sqrt((Math.pow((n1-mean),2)+Math.pow((n2-mean),2)+Math.pow((n3-mean),2)+Math.pow((n4-mean),2)+Math.pow((n5-mean),2))/5)));
	}

}
