import java.util.Scanner;
import java.util.ArrayList;
public class App {
    public static ArrayList<Integer> grades=new ArrayList<Integer>();
    public static float average;
    public static void main(String[] args) throws Exception {
        Scanner input=new Scanner(System.in);
        boolean done=false;
        while(done==false){ //I put = instead of ==
            System.out.print("Provide a score or press or press enter to finalize: ");
            String inputCache=input.nextLine();
            if(inputCache.isBlank()){
                if(grades.size()==0){
                    System.out.println("You must provide at least one score!");
                }else{
                    done=true;
                    input.close();
                }
            }else{
                try{
                    grades.add(Integer.parseInt(inputCache));
                }catch(Exception NumberFormatException){
                    System.out.println("The supplied input is not a number!");
                }
            }
        }
        for(int i:grades){
            average+=i;
        }
        average=average/grades.size();
        String output;
        //Scale based off Wikipedia's table. https://en.wikipedia.org/wiki/Academic_grading_in_the_United_States
        if(average>=97){
            output="A+";
        }else if(average>=93){
            output="A";
        }else if(average>=90){
            output="A-";
        }else if(average>=87){
            output="B+";
        }else if(average>=83){
            output="B";
        }else if(average>=80){
            output="B-";
        }else if(average>=77){
            output="C+";
        }else if(average>=73){
            output="C";
        }else if(average>=70){
            output="C-";
        }else if(average>=67){
            output="D+";
        }else if(average>=63){
            output="D";
        }else if(average>=60){
            output="D-";
        }else{
            output="F";
        }
        System.out.println(average+", "+output);
    }
}