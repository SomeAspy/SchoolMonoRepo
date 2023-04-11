package edu.wit.cs.comp1000;
import static java.lang.System.out;
import java.text.DecimalFormat;
import java.util.Scanner;

public class LA2a {

	public static void main(String[] args) {
		DecimalFormat df=new DecimalFormat("#.000");
		Scanner input=new Scanner(System.in);
		out.print("Enter number of sides: ");
		double n;
		double s;
		n=input.nextDouble();
		out.print("Enter side length: ");
		s=input.nextDouble();
		input.close();
		if(n<3){
			out.println("A polygon must have at least 3 sides.");
		}else if(s<=0){
			out.println("Side length must be positive.");
		}else{
			
			String area=df.format(((s*s)*n)/(4*((Math.tan(180/n)))));
			String perimeter=df.format(n*s);
			String interAngle=df.format(180-(360/n));
			out.println("Area: " + area);
			out.println("Perimeter: " + perimeter);
			out.println("Interior Angle: " + interAngle);
		}
	}
}
