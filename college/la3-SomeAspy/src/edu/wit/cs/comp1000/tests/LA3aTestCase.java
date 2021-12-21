package edu.wit.cs.comp1000.tests;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.security.Permission;

import edu.wit.cs.comp1000.LA3a;
import junit.framework.TestCase;

public class LA3aTestCase extends TestCase {
	
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
	
	private final static String E_OP = "Invalid operation!";
	
	private void _test(String[] values, String result) {
		final String input = String.join(" ", values);
		
		final String output = TestSuite.stringOutput(new String[] {
			"Enter three numbers: ",
			"Enter operation: ",
			"%s%n" }, new Object[] {result});
		
		final ByteArrayOutputStream outContent = new ByteArrayOutputStream();
		
		System.setIn(new ByteArrayInputStream(input.getBytes()));
		System.setOut(new PrintStream(outContent));
		
		try {
			LA3a.main(new String[] { "foo" });
		} catch (ExitException e) {}
		assertEquals(output, outContent.toString());
		
		System.setIn(null);
		System.setOut(null);
	}
	
	public void testOp() {
		_test(new String[] {"-1", "0", "1", "avg"}, E_OP);
		_test(new String[] {"-1", "0", "1", "sum"}, E_OP);
		
		_test(new String[] {"-1", "0", "1", "L1"}, E_OP);
		_test(new String[] {"-1", "0", "1", "L2"}, E_OP);
		_test(new String[] {"-1", "0", "1", "MIN"}, E_OP);
		_test(new String[] {"-1", "0", "1", "Min"}, E_OP);
	}
	
	private void _testResult(String[] values, String op, String a, String b, String c, String ans) {
		_test(values, op + "(" + a + ", " + b + ", " + c + ") = " + ans);
	}
	
	public void testMin() {
		_testResult(new String[] {"-1", "0", "1", "min"}, "min", "-1.00", "0.00", "1.00", "-1.00");
		_testResult(new String[] {"0", "-1", "1", "min"}, "min", "0.00", "-1.00", "1.00", "-1.00");
		_testResult(new String[] {"1", "0", "-1", "min"}, "min", "1.00", "0.00", "-1.00", "-1.00");
		
		_testResult(new String[] {"-1", "-1", "-1", "min"}, "min", "-1.00", "-1.00", "-1.00", "-1.00");
		_testResult(new String[] {"0", "0", "0", "min"}, "min", "0.00", "0.00", "0.00", "0.00");
		_testResult(new String[] {"1", "1", "1", "min"}, "min", "1.00", "1.00", "1.00", "1.00");
		
		_testResult(new String[] {"3.14159", "2.718", "6.022", "min"}, "min", "3.14", "2.72", "6.02", "2.72");
		_testResult(new String[] {"-3.14159", "2.718", "6.022", "min"}, "min", "-3.14", "2.72", "6.02", "-3.14");
		_testResult(new String[] {"3.14159", "-2.718", "6.022", "min"}, "min", "3.14", "-2.72", "6.02", "-2.72");
		_testResult(new String[] {"3.14159", "2.718", "-6.022", "min"}, "min", "3.14", "2.72", "-6.02", "-6.02");
	}
	
	public void testL1() {
		_testResult(new String[] {"1", "0", "-1", "l1"}, "l1", "1.00", "0.00", "-1.00", "2.00");
		_testResult(new String[] {"-1", "0", "1", "l1"}, "l1", "-1.00", "0.00", "1.00", "2.00");
		_testResult(new String[] {"1", "0", "1", "l1"}, "l1", "1.00", "0.00", "1.00", "2.00");
		_testResult(new String[] {"-1", "0", "-1", "l1"}, "l1", "-1.00", "0.00", "-1.00", "2.00");
		
		_testResult(new String[] {"3.14159", "2.718", "6.022", "l1"}, "l1", "3.14", "2.72", "6.02", "11.88");
		_testResult(new String[] {"-3.14159", "2.718", "6.022", "l1"}, "l1", "-3.14", "2.72", "6.02", "11.88");
		_testResult(new String[] {"3.14159", "-2.718", "6.022", "l1"}, "l1", "3.14", "-2.72", "6.02", "11.88");
		_testResult(new String[] {"3.14159", "2.718", "-6.022", "l1"}, "l1", "3.14", "2.72", "-6.02", "11.88");
	}
	
	public void testL2() {
		_testResult(new String[] {"1", "0", "-1", "l2"}, "l2", "1.00", "0.00", "-1.00", "1.41");
		_testResult(new String[] {"-1", "0", "1", "l2"}, "l2", "-1.00", "0.00", "1.00", "1.41");
		_testResult(new String[] {"1", "0", "1", "l2"}, "l2", "1.00", "0.00", "1.00", "1.41");
		_testResult(new String[] {"-1", "0", "-1", "l2"}, "l2", "-1.00", "0.00", "-1.00", "1.41");
		
		_testResult(new String[] {"3.14159", "2.718", "6.022", "l2"}, "l2", "3.14", "2.72", "6.02", "7.32");
		_testResult(new String[] {"-3.14159", "2.718", "6.022", "l2"}, "l2", "-3.14", "2.72", "6.02", "7.32");
		_testResult(new String[] {"3.14159", "-2.718", "6.022", "l2"}, "l2", "3.14", "-2.72", "6.02", "7.32");
		_testResult(new String[] {"3.14159", "2.718", "-6.022", "l2"}, "l2", "3.14", "2.72", "-6.02", "7.32");
	}
	
}
