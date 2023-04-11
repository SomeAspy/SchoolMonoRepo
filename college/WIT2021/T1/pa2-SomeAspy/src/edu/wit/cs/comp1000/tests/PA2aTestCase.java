package edu.wit.cs.comp1000.tests;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.security.Permission;

import edu.wit.cs.comp1000.PA2a;
import junit.framework.TestCase;

public class PA2aTestCase extends TestCase {
	
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
	
	private void _test(String[] values, String roots, String answer) {
		final String input = String.join(" ", values);
		
		final String output = TestSuite.stringOutput(new String[] {
			"Enter a b c: " +
			roots + ": " + answer + "%n" }, new Object[] {});
		
		final ByteArrayOutputStream outContent = new ByteArrayOutputStream();
		
		System.setIn(new ByteArrayInputStream(input.getBytes()));
		System.setOut(new PrintStream(outContent));
		
		try {
			PA2a.main(new String[] { "foo" });
		} catch (ExitException e) {}
		assertEquals(output, outContent.toString());
		
		System.setIn(null);
		System.setOut(null);
	}
	
	public void testImagWhole() {
		_test(new String[] {"1", "1", "4"}, "Roots", "imaginary");
	}
	
	public void testImagDec() {
		_test(new String[] {"1.1", "1", "4.1"}, "Roots", "imaginary");
	}
	
	public void testSingle() {
		_test(new String[] {"1", "4", "4"}, "Root", "-2.00");
		_test(new String[] {"1", "-4", "4"}, "Root", "2.00");
	}
	
	public void testTwoWhole() {
		_test(new String[] {"1", "6", "5"}, "Roots", "-5.00, -1.00");
		_test(new String[] {"1", "-6", "5"}, "Roots", "1.00, 5.00");
	}
	
	public void testTwoDec() {
		_test(new String[] {"2", "-5.5", "2.5"}, "Roots", "0.57, 2.18");
		_test(new String[] {"2", "5.5", "2.5"}, "Roots", "-2.18, -0.57");
	}

}