package edu.wit.cs.comp1000.tests;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.security.Permission;

import edu.wit.cs.comp1000.PA3b;
import junit.framework.TestCase;

public class PA3bTestCase extends TestCase {
	
	@SuppressWarnings("serial")
	private static class ExitException extends SecurityException {}
	
	private static class NoExitSecurityManager extends SecurityManager 
    {
        @Override
        public void checkPermission(Permission perm) {}
        
        @Override
        public void checkPermission(Permission perm, Object context) {}
        
        @Override
        public void checkExit(int status) { super.checkExit(status); throw new ExitException(); }
    }
	
	@Override
    protected void setUp() throws Exception 
    {
        super.setUp();
        System.setSecurityManager(new NoExitSecurityManager());
    }
	
	@Override
    protected void tearDown() throws Exception 
    {
        System.setSecurityManager(null);
        super.tearDown();
    }
	
	private static enum Sign {
		Aries, Taurus, Gemini, Cancer, Leo, Virgo, Libra,
		Scorpio, Sagittarius, Capricorn, Aquarius, Pisces,
	};
	
	private static final String RESULT = "You are ";
	private static final String E_MONTH = "Month must be between 1 and 12!";
	private static final String E_DAY = "Day must be between 1 and 31!";
	
	private void _test(String[] values, String result, boolean complex) {
		final String input = String.join(" ", values);
		
		final String output = TestSuite.stringOutput(new String[] {
			"Enter your birth month (1-12): ",
			"Enter your birth day (1-31): ",
			"%s" }, new Object[] { result });
		
		final ByteArrayOutputStream outContent = new ByteArrayOutputStream();
		System.setIn(new ByteArrayInputStream(input.getBytes()));
		System.setOut(new PrintStream(outContent));
		
		try {
			PA3b.main(new String[] { "foo" });
		} catch (ExitException e) {}
		
		if (complex) {
			String[] lines = outContent.toString().trim().split("\\r?\\n");
			if (lines.length<1) {
				assertEquals(String.format("%s%nHoroscope", output), outContent.toString());
			} else {
				assertEquals(output, lines[0]);
				assertTrue("Expecting a horoscope!", lines.length>1);
				
				String horoscope = "";
				for (int i=1; i<lines.length; i++) {
					horoscope += String.format("%s", lines[i]);
				}
				assertTrue("Expecting a horoscope!", horoscope.trim().length()>0);
			}
		} else {
			assertEquals(output+String.format("%n"), outContent.toString());
		}
		
		System.setIn(null);
		System.setOut(null);
	}
	
	private void _testResult(String[] values, Sign s, String a_an) {
		_test(values, RESULT + a_an + " " + s.name() + "!", true);
	}
	
	public void testAries() {
		_testResult(new String[] {"3", "21"}, Sign.Aries, "an");
		_testResult(new String[] {"3", "22"}, Sign.Aries, "an");
		_testResult(new String[] {"3", "30"}, Sign.Aries, "an");
		_testResult(new String[] {"4", "1"}, Sign.Aries, "an");
		_testResult(new String[] {"4", "18"}, Sign.Aries, "an");
		_testResult(new String[] {"4", "19"}, Sign.Aries, "an");
	}
	
	public void testTaurus() {
		_testResult(new String[] {"4", "20"}, Sign.Taurus, "a");
		_testResult(new String[] {"4", "21"}, Sign.Taurus, "a");
		_testResult(new String[] {"4", "30"}, Sign.Taurus, "a");
		_testResult(new String[] {"5", "1"}, Sign.Taurus, "a");
		_testResult(new String[] {"5", "19"}, Sign.Taurus, "a");
		_testResult(new String[] {"5", "20"}, Sign.Taurus, "a");
	}
	
	public void testGemini() {
		_testResult(new String[] {"5", "21"}, Sign.Gemini, "a");
		_testResult(new String[] {"5", "22"}, Sign.Gemini, "a");
		_testResult(new String[] {"5", "30"}, Sign.Gemini, "a");
		_testResult(new String[] {"6", "1"}, Sign.Gemini, "a");
		_testResult(new String[] {"6", "20"}, Sign.Gemini, "a");
		_testResult(new String[] {"6", "21"}, Sign.Gemini, "a");
	}
	
	public void testCancer() {
		_testResult(new String[] {"6", "22"}, Sign.Cancer, "a");
		_testResult(new String[] {"6", "23"}, Sign.Cancer, "a");
		_testResult(new String[] {"6", "30"}, Sign.Cancer, "a");
		_testResult(new String[] {"7", "1"}, Sign.Cancer, "a");
		_testResult(new String[] {"7", "21"}, Sign.Cancer, "a");
		_testResult(new String[] {"7", "22"}, Sign.Cancer, "a");
	}
	
	public void testLeo() {
		_testResult(new String[] {"7", "23"}, Sign.Leo, "a");
		_testResult(new String[] {"7", "24"}, Sign.Leo, "a");
		_testResult(new String[] {"7", "30"}, Sign.Leo, "a");
		_testResult(new String[] {"8", "1"}, Sign.Leo, "a");
		_testResult(new String[] {"8", "21"}, Sign.Leo, "a");
		_testResult(new String[] {"8", "22"}, Sign.Leo, "a");
	}
	
	public void testVirgo() {
		_testResult(new String[] {"8", "23"}, Sign.Virgo, "a");
		_testResult(new String[] {"8", "24"}, Sign.Virgo, "a");
		_testResult(new String[] {"8", "30"}, Sign.Virgo, "a");
		_testResult(new String[] {"9", "1"}, Sign.Virgo, "a");
		_testResult(new String[] {"9", "21"}, Sign.Virgo, "a");
		_testResult(new String[] {"9", "22"}, Sign.Virgo, "a");
	}
	
	public void testLibra() {
		_testResult(new String[] {"9", "23"}, Sign.Libra, "a");
		_testResult(new String[] {"9", "24"}, Sign.Libra, "a");
		_testResult(new String[] {"9", "30"}, Sign.Libra, "a");
		_testResult(new String[] {"10", "1"}, Sign.Libra, "a");
		_testResult(new String[] {"10", "21"}, Sign.Libra, "a");
		_testResult(new String[] {"10", "22"}, Sign.Libra, "a");
	}
	
	public void testScorpio() {
		_testResult(new String[] {"10", "23"}, Sign.Scorpio, "a");
		_testResult(new String[] {"10", "24"}, Sign.Scorpio, "a");
		_testResult(new String[] {"10", "30"}, Sign.Scorpio, "a");
		_testResult(new String[] {"11", "1"}, Sign.Scorpio, "a");
		_testResult(new String[] {"11", "20"}, Sign.Scorpio, "a");
		_testResult(new String[] {"11", "21"}, Sign.Scorpio, "a");
	}
	
	public void testSagittarius() {
		_testResult(new String[] {"11", "22"}, Sign.Sagittarius, "a");
		_testResult(new String[] {"11", "23"}, Sign.Sagittarius, "a");
		_testResult(new String[] {"11", "30"}, Sign.Sagittarius, "a");
		_testResult(new String[] {"12", "1"}, Sign.Sagittarius, "a");
		_testResult(new String[] {"12", "20"}, Sign.Sagittarius, "a");
		_testResult(new String[] {"12", "21"}, Sign.Sagittarius, "a");
	}
	
	public void testCapricorn() {
		_testResult(new String[] {"12", "22"}, Sign.Capricorn, "a");
		_testResult(new String[] {"12", "23"}, Sign.Capricorn, "a");
		_testResult(new String[] {"12", "30"}, Sign.Capricorn, "a");
		_testResult(new String[] {"1", "1"}, Sign.Capricorn, "a");
		_testResult(new String[] {"1", "18"}, Sign.Capricorn, "a");
		_testResult(new String[] {"1", "19"}, Sign.Capricorn, "a");
	}
	
	public void testAquarius() {
		_testResult(new String[] {"1", "20"}, Sign.Aquarius, "an");
		_testResult(new String[] {"1", "21"}, Sign.Aquarius, "an");
		_testResult(new String[] {"1", "30"}, Sign.Aquarius, "an");
		_testResult(new String[] {"2", "1"}, Sign.Aquarius, "an");
		_testResult(new String[] {"2", "17"}, Sign.Aquarius, "an");
		_testResult(new String[] {"2", "18"}, Sign.Aquarius, "an");
	}
	
	public void testPisces() {
		_testResult(new String[] {"2", "19"}, Sign.Pisces, "a");
		_testResult(new String[] {"2", "20"}, Sign.Pisces, "a");
		_testResult(new String[] {"2", "28"}, Sign.Pisces, "a");
		_testResult(new String[] {"3", "1"}, Sign.Pisces, "a");
		_testResult(new String[] {"3", "19"}, Sign.Pisces, "a");
		_testResult(new String[] {"3", "20"}, Sign.Pisces, "a");
	}
	
	public void testMonth() {
		_test(new String[] {"13", "1"}, E_MONTH, false);
		_test(new String[] {"100", "1"}, E_MONTH, false);
	}
	
	public void testDay() {
		_test(new String[] {"1", "32"}, E_DAY, false);
		_test(new String[] {"1", "100"}, E_DAY, false);
	}

}
