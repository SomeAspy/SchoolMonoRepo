package edu.wit.cs.comp1000.tests;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.security.Permission;

import edu.wit.cs.comp1000.PA3a;
import junit.framework.TestCase;

public class PA3aTestCase extends TestCase {
	
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
	
	private final static String E_POS = "Side lengths must all be positive";
	private final static String E_ALONG = "Side a is too long";
	private final static String E_BLONG = "Side b is too long";
	private final static String E_CLONG = "Side c is too long";
	private final static String RESULT = "The area is ";
	
	private void _test(String[] values, String result) {
		final String input = String.join(" ", values);
		
		final String output = TestSuite.stringOutput(new String[] {
			"Enter the length of side a: ",
			"Enter the length of side b: ",
			"Enter the length of side c: ",
			"%s%n" }, new Object[] { result });
		
		final ByteArrayOutputStream outContent = new ByteArrayOutputStream();
		
		System.setIn(new ByteArrayInputStream(input.getBytes()));
		System.setOut(new PrintStream(outContent));
		
		try {
			PA3a.main(new String[] { "foo" });
		} catch (ExitException e) {}
		assertEquals(output, outContent.toString());
		
		System.setIn(null);
		System.setOut(null);
	}
	
	private void _testResult(String[] values, String outcome) {
		_test(values, RESULT + outcome);
	}
	
	public void testMath() {
		_testResult(new String[] {"3", "4", "5"}, "6.00");
		_testResult(new String[] {"5.5", "5.5", "10"}, "11.46");
		_testResult(new String[] {"1.1", "2.6", "2.9"}, "1.43");
	}
	
	public void testLength() {
		_test(new String[] {"3", "4", "8"}, E_CLONG);
		_test(new String[] {"8", "4", "3"}, E_ALONG);
		_test(new String[] {"3", "8", "4"}, E_BLONG);
	}
	
	public void testNeg() {
		_test(new String[] { "-3", "4", "5" }, E_POS);
		_test(new String[] { "3", "-4", "5" }, E_POS);
		_test(new String[] { "3", "4", "-5" }, E_POS);
		_test(new String[] { "-3", "-4", "5" }, E_POS);
		_test(new String[] { "3", "-4", "-5" }, E_POS);
		_test(new String[] { "-3", "4", "-5" }, E_POS);
		_test(new String[] { "-3", "-4", "-5" }, E_POS);
	}

}
