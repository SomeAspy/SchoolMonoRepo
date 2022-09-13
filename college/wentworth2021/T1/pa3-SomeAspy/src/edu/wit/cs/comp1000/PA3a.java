package edu.wit.cs.comp1000;
import java.util.Scanner;
import java.text.DecimalFormat;
/**
 * @author Aiden Baker
 * First time using a linter for this, time to die!
 * NOSONAR comments disable linting for the line
 */
public class PA3a {
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in); //set up input system
		System.out.print("Enter the length of side a: "); //NOSONAR 
		float a; //Sonar says best practice is to use seperate lines for readability. https://rules.sonarsource.com/java/tag/convention/RSPEC-1659
		float b; //declare floats we will be using
		float c;
		float semi;
		float area;
		a=input.nextFloat();
		System.out.print("Enter the length of side b: "); //NOSONAR
		b=input.nextFloat();
		System.out.print("Enter the length of side c: "); //NOSONAR
		c=input.nextFloat();
		input.close(); //release scanner
		if(a<0||b<0||c<0){ //if any vars are less than 0
			System.out.println("Side lengths must all be positive"); //NOSONAR
		}else if(a>(b+c)){ //There has to be a better way of doing this.
			System.out.println("Side a is too long"); //NOSONAR
		}else if(b>(a+c)){
			System.out.println("Side b is too long"); //NOSONAR
		}else if(c>(b+a)){
			System.out.println("Side c is too long"); //NOSONAR
		}else{
			semi=(a+b+c)/2;
			area=(float) Math.sqrt(semi*(semi-a)*(semi-b)*(semi-c));
			System.out.println("The area is "+new DecimalFormat("0.00").format(area)); //NOSONAR
		}
	}
}