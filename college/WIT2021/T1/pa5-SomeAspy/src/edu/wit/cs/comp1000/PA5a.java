package edu.wit.cs.comp1000;
import java.util.Scanner;
import static java.lang.System.out;
public class PA5a {
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		out.printf("Input message: ");
		String[] message=((input.nextLine()).toLowerCase()).split("");
		input.close();
		for (String i:message){
			switch (i){
				case"d":d();break;
				case"e":e();break;
				case"h":h();break;
				case"l":l();break;
				case"o":o();break;
				case"r":r();break;
				case"w":w();break;
				case" ":case"":blank(); //Can't use default case here for whatever reason
			}
		}
	}
	public static void d(){
		out.printf("%n");
		out.printf("*******%n");
		out.printf("*     *%n");
		out.printf("*     *%n");
		out.printf(" *   * %n");
		out.printf("  ***  %n");
		out.printf("%n");
	}
	public static void e(){
		out.printf("%n");
		out.printf("*******%n");
		out.printf("*  *  *%n");
		out.printf("*  *  *%n");
		out.printf("*  *  *%n");
		out.printf("*  *  *%n");
		out.printf("%n");
	}
	public static void h(){
		out.printf("%n");
		out.printf("*******%n");
		out.printf("   *   %n");
		out.printf("   *   %n");
		out.printf("   *   %n");
		out.printf("*******%n");
		out.printf("%n");
	}
	public static void l(){
		out.printf("%n");
		out.printf("*******%n");
		out.printf("*      %n");
		out.printf("*      %n");
		out.printf("*      %n");
		out.printf("*      %n");
		out.printf("%n");
	}
	public static void o(){
		out.printf("%n");
		out.printf("*******%n");
		out.printf("*     *%n");
		out.printf("*     *%n");
		out.printf("*     *%n");
		out.printf("*******%n");
		out.printf("%n");
	}
	public static void r(){
		out.printf("%n");
		out.printf("*******%n");
		out.printf("   *  *%n");
		out.printf("  **  *%n");
		out.printf(" * ****%n");
		out.printf("*      %n");
		out.printf("%n");
	}
	public static void w(){
		out.printf("%n");
		out.printf("*******%n");
		out.printf("*      %n");
		out.printf("****   %n");
		out.printf("*      %n");
		out.printf("*******%n");
		out.printf("%n");
	}
	public static void blank(){
		out.printf("%n%n%n");
	}
}