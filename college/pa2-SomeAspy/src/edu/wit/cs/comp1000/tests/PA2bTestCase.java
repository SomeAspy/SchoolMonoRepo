package edu.wit.cs.comp1000.tests;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.security.Permission;

import edu.wit.cs.comp1000.PA2b;
import junit.framework.TestCase;

public class PA2bTestCase extends TestCase {
	
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
	
	private void _test(String[] values, String count_pos, String count_nonpos, String sum_pos, String sum_nonpos, String sum, String avg_pos, String avg_nonpos, String avg, String num_pos, String num_nonpos) {
		final String input = String.join(" ", values);
		
		final String output = TestSuite.stringOutput(new String[] {
			"Enter five whole numbers: " +
			"The sum of the " + count_pos + " positive " + num_pos + ": " + sum_pos + "%n" +
			"The sum of the " + count_nonpos + " non-positive " + num_nonpos + ": " + sum_nonpos + "%n" +
			"The sum of the 5 numbers: " + sum + "%n" +
			"The average of the " + count_pos + " positive " + num_pos + ": " + avg_pos + "%n" +
			"The average of the " + count_nonpos + " non-positive " + num_nonpos + ": " + avg_nonpos + "%n" +
			"The average of the 5 numbers: " + avg + "%n" }, new Object[] {});
		
		final ByteArrayOutputStream outContent = new ByteArrayOutputStream();
		
		System.setIn(new ByteArrayInputStream(input.getBytes()));
		System.setOut(new PrintStream(outContent));
		
		try {
			PA2b.main(new String[] { "foo" });
		} catch (ExitException e) {}
		assertEquals(output, outContent.toString());
		
		System.setIn(null);
		System.setOut(null);
	}
	
	public void testZero() {
		_test(new String[] {"0", "0", "0", "0", "0"}, "0", "5", "0", "0", "0", "0.00", "0.00", "0.00", "numbers", "numbers");
	}
	
	public void testPosWhole() {
		_test(new String[] {"1", "2", "3", "4", "5"}, "5", "0", "15", "0", "15", "3.00", "0.00", "3.00", "numbers", "numbers");
	}
	
	public void testPosDec() {
		_test(new String[] {"1", "2", "3", "4", "6"}, "5", "0", "16", "0", "16", "3.20", "0.00", "3.20", "numbers", "numbers");
	}
	
	public void testNegWhole() {
		_test(new String[] {"-1", "-2", "-3", "-4", "-5"}, "0", "5", "0", "-15", "-15", "0.00", "-3.00", "-3.00", "numbers", "numbers");
	}
	
	public void testNegDec() {
		_test(new String[] {"-1", "-2", "-3", "-4", "-6"}, "0", "5", "0", "-16", "-16", "0.00", "-3.20", "-3.20", "numbers", "numbers");
	}
	
	public void testMixSingle() {
		_test(new String[] {"5", "0", "0", "0", "0"}, "1", "4", "5", "0", "5", "5.00", "0.00", "1.00", "number", "numbers");
		_test(new String[] {"-4", "1", "1", "1", "1"}, "4", "1", "4", "-4", "0", "1.00", "-4.00", "0.00", "numbers", "number");
	}
	
	public void testMixRound() {
		_test(new String[] {"1", "1", "5", "0", "-1"}, "3", "2", "7", "-1", "6", "2.33", "-0.50", "1.20", "numbers", "numbers");
		_test(new String[] {"1", "2", "5", "0", "-3"}, "3", "2", "8", "-3", "5", "2.67", "-1.50", "1.00", "numbers", "numbers");
	}

}




