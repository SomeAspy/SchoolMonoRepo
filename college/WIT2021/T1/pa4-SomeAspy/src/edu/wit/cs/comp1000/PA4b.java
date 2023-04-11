package edu.wit.cs.comp1000;
import java.util.Scanner;
import java.util.Random;
public class PA4b {

	public static void main(String[] args) {
		Long seed;
		if(args.length!=1){
			seed=null; //change this to make the program actually do something.
		}else{
			seed=Long.valueOf(args[0]); //"""""random"""""
		}
		Random random;
		random=new Random(seed);
		int target=(Math.abs(random.nextInt())%100)+1;//NOSONAR target is the answer
		Scanner input=new Scanner(System.in);
		boolean inProgress=true;
		while(inProgress){
			System.out.print("Enter your guess (between 1 and 100): ");//NOSONAR
			int guess=input.nextInt();
			if(0>=guess||guess>100){
				System.out.println("Invalid guess, try again!");//NOSONAR
			}else if(guess==target){
				input.close();//kill input resources
				inProgress=false;//end the loop
				System.out.println("You win!");//NOSONAR
			}else if(guess>target){
				System.out.println("Too high!");//NOSONAR
			}else{
				System.out.println("Too low!");//NOSONAR
			}
		}
	}
}