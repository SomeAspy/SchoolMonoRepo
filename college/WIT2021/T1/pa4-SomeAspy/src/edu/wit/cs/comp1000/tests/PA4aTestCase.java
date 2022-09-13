package edu.wit.cs.comp1000.tests;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.security.Permission;

import edu.wit.cs.comp1000.PA4a;
import junit.framework.TestCase;

public class PA4aTestCase extends TestCase {
	
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
	
	private final static String E_P_GEZ = "The current price must be at least 0!";
	private final static String E_Y_GEZ = "The number of years must be at least 0!";
	private final static String E_I_GEZ = "The inflation rate must be at least 0!";
	
	private void _test(String[] values, String result) {
		final String input = String.join(" ", values);
		
		final String output = TestSuite.stringOutput(new String[] {
			"Enter the current price of the item: $",
			"Enter the number of years: ",
			"Enter the inflation rate as a percentage: ",
			"%s%n" }, new Object[] { result });
		
		final ByteArrayOutputStream outContent = new ByteArrayOutputStream();
		
		System.setIn(new ByteArrayInputStream(input.getBytes()));
		System.setOut(new PrintStream(outContent));
		
		try {
			PA4a.main(new String[] { "foo" });
		} catch (ExitException e) {}
		assertEquals(output, outContent.toString());
		
		System.setIn(null);
		System.setOut(null);
	}
	
	private void _testResult(String[] values, String year, String s, String price) {
		_test(values, "After " + year + " year" + s + ", the price will be $" + price);
	}
	
	public void testMath() {
		_testResult(new String[] { "10", "1", "10" }, "1", "", "11.00");
		_testResult(new String[] { "10", "2", "10" }, "2", "s", "12.10");
		_testResult(new String[] { "10", "9", "10" }, "9", "s", "23.58");
		
		_testResult(new String[] { "10.5", "2", "10.5" }, "2", "s", "12.82");
		_testResult(new String[] { "10.5", "9", "10.5" }, "9", "s", "25.79");
		
		_testResult(new String[] { "239420", "30", "2.5" }, "30", "s", "502199.63");
	}
	
	public void testPriceNeg() {
		_test(new String[] { "-1", "2", "10" }, E_P_GEZ);
		_test(new String[] { "-10", "2", "10" }, E_P_GEZ);
	}
	
	public void testYearNeg() {
		_test(new String[] { "10.5", "-1", "10" }, E_Y_GEZ);
		_test(new String[] { "10.5", "-10", "10" }, E_Y_GEZ);
	}
	
	public void testIntNeg() {
		_test(new String[] { "10.5", "2", "-1" }, E_I_GEZ);
		_test(new String[] { "10.5", "2", "-10" }, E_I_GEZ);
	}
	
}
