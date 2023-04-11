package edu.wit.cs.comp1000;
import java.util.Scanner;
import java.util.ArrayList;
import java.text.DecimalFormat;


/**
 * @author Aiden Baker
 * 
 */
public class PA2b {
	/**
	 * I honestly lost track of what even happens in here
	 */
	public static float sumNeg,sumPos,numPos,numNeg,avgPos,avgNeg,avgAll; //These probably shouldnt be global, but it works. 
	public static String sPos="s",sNeg="s";
	public static void main(String[] args) {
		DecimalFormat correct=new DecimalFormat("#0.00");
		sumNeg=0;
		sumPos=0;
		numPos=0;
		numNeg=0; //if this is all done on one line it just wont work!!! WHY????
		avgPos=0;
		avgNeg=0;
		avgAll=0;
		String strAvgPos,strAvgNeg,strAvgAll; //OH BUT THIS ONE WILL
		sPos="s";
		sNeg="s";
		//fix whatever shitfuckery is going on by resetting each run?
		Scanner input=new Scanner(System.in);
		System.out.print("Enter five whole numbers: ");
		ArrayList<Integer> rawInput=new ArrayList<Integer>();
		for(int i=0;i<5; i++){
			rawInput.add(input.nextInt());
		}
		input.close();
		for(int i:rawInput){
			if(i>0){
				sumPos+=i;
				numPos++;
			}else{
				sumNeg+=i;
				numNeg++;
			}
		}
		try{
			avgPos=sumPos/numPos;
		}catch(ArithmeticException e){ //naturally, this will catch errors instead of doing it like a sane person and fixing the issue.
			e=null;
			System.gc(); //delete the error just to show it whose boss
			avgPos=0; // If dividing by 0, set 0
		}
		try{
			avgNeg=sumNeg/numNeg;
		}catch(ArithmeticException e){
			avgNeg=0; 
		}
		avgAll=(sumPos+sumNeg)/5;
		if(numPos==1){
			sPos="";
		}
		if(numNeg==1){
			sNeg="";
		}
		if(Float.isNaN(avgPos)){ //sometimes you just get NaN, so now we ignore my previous coding errors and do this.
			strAvgPos="0.00"; //fake 0.00 because it just wont do it correctly. this is probably bad practice.
		}else{
			strAvgPos=correct.format(avgPos); //make it a string. idk.
		}
		if(Float.isNaN(avgNeg)){
			strAvgNeg="0.00";
		}else{
			strAvgNeg=correct.format(avgNeg);
		}
		if(Float.isNaN(avgAll)){
			strAvgAll="0.00";
		}else{
			strAvgAll=correct.format(avgAll);
		}
		System.out.println("The sum of the "+Math.round(numPos)+" positive number"+sPos+": "+Math.round(sumPos)); //If I don't round inline then it just wont work. wtf?
		System.out.println("The sum of the "+Math.round(numNeg)+" non-positive number"+sNeg+": "+Math.round(sumNeg));
		System.out.println("The sum of the 5 numbers: "+Math.round(sumNeg+sumPos));
		System.out.println("The average of the "+Math.round(numPos)+" positive number"+sPos+": "+strAvgPos);
		System.out.println("The average of the "+Math.round(numNeg)+" non-positive number"+sNeg+": "+strAvgNeg);
		System.out.println("The average of the 5 numbers: "+strAvgAll);
	}
}