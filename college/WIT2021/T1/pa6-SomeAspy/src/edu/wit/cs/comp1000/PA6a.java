package edu.wit.cs.comp1000;
import static java.lang.System.out;
// TODO: document this class
public class PA6a {
	
	/**
	 * Error to output if year is not positive
	 */
	static final String E_YEAR = "The year must be positive!";
	
	/**
	 * Error to output if the day is not between 0 and 6
	 */
	static final String E_DAY = "The day of January 1st must be between 0 and 6!";
	
	/**
	 * Determines if an input is a leap year
	 * 
	 * @param year year in question
	 * @return true if a leap year
	 */
	public static boolean isLeapYear(int year) {
		if(year%4!=0){
			return false;
		}else if(year%100!=0){
			return true;
		}else if(year%400!=0){
			return false;
		}else{
			return true;
		}
	}
	
	/**
	 * Outputs a month to the console
	 * 
	 * @param month title
	 * @param startDay 0=Sunday ... 6=Saturday
	 * @param numDays number of days in the month
	 * @return day of the week after the last day of the month
	 */
	public static int printMonth(String month, int startDay, int numDays) {
		out.println(month);
		String firstLineSpacing="";
		switch(startDay){ //I know this method of doing it is shit. Leave me alone.
			case 0:firstLineSpacing=" 1";break;
			case 1:firstLineSpacing="    1";break;
			case 2:firstLineSpacing="       1";break;
			case 3:firstLineSpacing="          1";break;
			case 4:firstLineSpacing="             1";break;
			case 5:firstLineSpacing="                1";break;
			case 6:firstLineSpacing="                   1";break;
		}
		out.println(firstLineSpacing+"1");
		return 0;
		
	}

	/**
	 * Program execution point:
	 * input year, day of the week (0-6) of january 1
	 * output calendar for that year
	 * 
	 * @param args command-line arguments (ignored)
	 */
	public static void main(String[] args) {
		// TODO: write your code here
	}

}
