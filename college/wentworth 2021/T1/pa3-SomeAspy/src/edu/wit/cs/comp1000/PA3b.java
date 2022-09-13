package edu.wit.cs.comp1000;
import java.util.Scanner;
/**
 * @author Aiden Baker
 */
public class PA3b {
	public static void main(String[] args) {//NOSONAR (S3776)
		String sign; //final output
		String n=""; //n???????
		Scanner input=new Scanner(System.in);//create input
		System.out.print("Enter your birth month (1-12): ");//NOSONAR
		int month=input.nextInt();
		System.out.print("Enter your birth day (1-31): ");//NOSONAR
		int day=input.nextInt();
		input.close();//release input
		if(month<1||month>12){//catch stupidity
			System.out.println("Month must be between 1 and 12!");//NOSONAR
			System.exit(1);
		}
		if(day<1||day>31){
			System.out.println("Day must be between 1 and 31!");//NOSONAR
			System.exit(1);
		}
		switch(month){ //kill me now
			case 1:
				if(day>=20){
					sign="Aquarius";
					n="n";
				}else{
					sign="Capricorn";
				}
				break;
			case 2:
				if(day>=19){
					sign="Pisces";
				}else{
					sign="Aquarius";
					n="n";
				}
				break;
			case 3:
				if(day>=21){
					sign="Aries";
					n="n";
				}else{
					sign="Pisces";
				}
				break;
			case 4:
				if(day>=20){
					sign="Taurus";
				}else{
					sign="Aries";
					n="n";
				}
				break;
			case 5:
				if(day>=21){
					sign="Gemini";
				}else{
					sign="Taurus";
				}
				break;
			case 6:
				if(day>=22){
					sign="Cancer";
				}else{
					sign="Gemini";
				}
				break;
			case 7:
				if(day>=23){
					sign="Leo";
				}else{
					sign="Cancer";
				}
				break;
			case 8:
				if(day>=23){
					sign="Virgo";
				}else{
					sign="Leo";
				}
				break;
			case 9:
				if(day>=23){
					sign="Libra";
				}else{
					sign="Virgo";
				}
				break;
			case 10:
				if(day>=23){
					sign="Scorpio";
				}else{
					sign="Libra";
				}
				break;
			case 11:
				if(day>=22){
					sign="Sagittarius";
				}else{
					sign="Scorpio";
				}
				break;
			default:
				if(day>=22){
					sign="Capricorn";
				}else{
					sign="Sagittarius";
				} //FINALLY FUCKING DONE WITH THIS
		}
		System.out.println("You are a"+n+" "+sign+"!\nI'm not gonna give you a random line for each outcome.");//NOSONAR
	}
}