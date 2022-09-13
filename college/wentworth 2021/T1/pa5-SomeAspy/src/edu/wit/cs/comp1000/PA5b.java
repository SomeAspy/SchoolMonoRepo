package edu.wit.cs.comp1000;

import java.util.Scanner;
import java.util.ArrayList;
import static java.lang.System.out;
import java.text.DecimalFormat;

public class PA5b {
	public static double avg;
	public static void main(String[] args) {
		DecimalFormat df=new DecimalFormat("0.00");
		Scanner input=new Scanner(System.in);
		Boolean run=true;
		while(run){
			avg=0.00;
			Boolean reading=true;
			ArrayList<Double> numbers=new ArrayList<Double>();
			out.print("Enter a stream of non-negative numbers (negative when finished): ");
			while(reading){
				String inputCache=input.next();
				//System.out.println(inputCache);
				Double newInputCache=Double.valueOf(inputCache); //do some janky shit
				if(newInputCache>=0){
					numbers.add(newInputCache);
				}else{
					reading=false;
				}
			}
			if(numbers.size()!=0){
				double sum=0;
				for(double num:numbers){
					sum+=num;
				}
				avg=sum/numbers.size();
			}
			String fixedAvg=df.format(avg);
			out.printf("The average is: "+fixedAvg+"%n");

			out.print("Do you want to compute another average (y/n)? ");
			String loop=input.next().toLowerCase();
			if(loop.startsWith("n")){
				run=false;
				input.close();
				System.exit(0);
			}
		}
	}

}
