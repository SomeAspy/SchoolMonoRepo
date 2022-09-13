package edu.wit.cs.comp1000.tests;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.security.Permission;

import edu.wit.cs.comp1000.LA4a;
import junit.framework.TestCase;

public class LA4aTestCase extends TestCase {
	
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
	
	private static final String E_POSITIVE = "Inputs must both be positive.";
	
	private void _testGCD(int a, int b, int expected) {
		Integer result = null;
		try {
			result = LA4a.gcd(a, b);
		} catch (ExitException e) {}
		assertEquals((Object) expected, (Object) result);
	}
	
	public void testGCD() {
		_testGCD(1, 1, 1);
		
		_testGCD(1, 2, 1);
		_testGCD(2, 1, 1);
		_testGCD(2, 2, 2);
		
		_testGCD(2, 4, 2);
		_testGCD(4, 2, 2);
		_testGCD(4, 4, 4);
		
		_testGCD(6, 14, 2);
		_testGCD(14, 6, 2);

		_testGCD(210, 45, 15);
		_testGCD(45, 210, 15);	
	}
	
	private void _test(String[] values, String result) {
		final String input = String.join(" ", values);
		
		final String output = TestSuite.stringOutput(new String[] {
			"Enter a: ",
			"Enter b: ",
			"%s%n" }, new Object[] {result});
		
		final ByteArrayOutputStream outContent = new ByteArrayOutputStream();
		
		System.setIn(new ByteArrayInputStream(input.getBytes()));
		System.setOut(new PrintStream(outContent));
		
		try {
			LA4a.main(new String[] { "foo" });
		} catch (ExitException e) {}
		assertEquals(output, outContent.toString());
		
		System.setIn(null);
		System.setOut(null);
	}
	
	public void testNegative() {
		_test(new String[] { "-1", "2" }, E_POSITIVE);
		_test(new String[] { "2", "-1" }, E_POSITIVE);
		_test(new String[] { "-1", "-1" }, E_POSITIVE);
	}
	
	public void testZero() {
		_test(new String[] { "0", "2" }, E_POSITIVE);
		_test(new String[] { "2", "0" }, E_POSITIVE);
		_test(new String[] { "0", "0" }, E_POSITIVE);
	}
	
	private void _testResult(String a, String b, String c) {
		_test(new String[] { a, b }, "The GCD of " + a + " and " + b + " is " + c);
	}
	
	public void testProg() {
		_testResult("1", "1", "1");
		
		_testResult("1", "2", "1");
		_testResult("2", "1", "1");
		_testResult("2", "2", "2");
		
		_testResult("2", "4", "2");
		_testResult("4", "2", "2");
		_testResult("4", "4", "4");
		
		_testResult("6", "14", "2");
		_testResult("14", "6", "2");
		
		_testResult("210", "45", "15");
		_testResult("45", "210", "15");
	}

}
