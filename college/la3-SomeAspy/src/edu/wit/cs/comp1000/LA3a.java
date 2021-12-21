package edu.wit.cs.comp1000;

import java.util.Scanner;

import static java.lang.Math.abs;

import java.text.DecimalFormat;

public class LA3a {
	public static double a,b,c,ans;
	public static String op;


	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		System.out.print("Enter three numbers: ");
		a=input.nextDouble();
		b=input.nextDouble();
		c=input.nextDouble();
		System.out.print("Enter operation: ");
		op=input.next();
		input.close();
		switch(op) {
			case"min":min();break;
			case"l1":l1();break;
			case"l2":l2();break;
			default:System.out.println("Invalid operation!");
		}

	}



	public static void printFinal(){
		DecimalFormat fix=new DecimalFormat("0.00");
		String aFix,bFix,cFix,ansFix;
		aFix=fix.format(a);
		bFix=fix.format(b);
		cFix=fix.format(c);
		ansFix=fix.format(ans);
		System.out.println(op+"("+aFix+", "+bFix+", "+cFix+") = "+ansFix);

	}

	public static void min(){
		if(a>b){ 
			if(b>c){
				ans=c;
			}else{
				ans=b;
			}
		}else if(a>c){
			ans=c;
		}else{
			ans=a;
		}
		printFinal();
	}
	
	public static void l1(){
		ans=abs(a)+abs(b)+abs(c);
		printFinal();
	}

	public static void l2(){
		ans=Math.sqrt((a*a)+(b*b)+(c*c));
		printFinal();
	}
}
