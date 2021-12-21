package edu.wit.cs.comp1000.tests;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.security.Permission;

import edu.wit.cs.comp1000.LA2a;
import junit.framework.TestCase;

public class LA2aTestCase extends TestCase {
	
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
	
	private final static String E_SIDE_NUM = "A polygon must have at least 3 sides.";
	private final static String E_SIDE_LENGTH = "Side length must be positive.";
	
	private void _test(String[] values, String result) {
		final String input = String.join(" ", values);
		
		final String output = TestSuite.stringOutput(new String[] {
			"Enter number of sides: ",
			"Enter side length: ",
			"%s%n" }, new Object[] {result});
		
		final ByteArrayOutputStream outContent = new ByteArrayOutputStream();
		
		System.setIn(new ByteArrayInputStream(input.getBytes()));
		System.setOut(new PrintStream(outContent));
		
		try {
			LA2a.main(new String[] { "foo" });
		} catch (ExitException e) {}
		assertEquals(output, outContent.toString());
		
		System.setIn(null);
		System.setOut(null);
	}
	
	private void _testResult(String[] values, String area, String perimeter, String interior) {
		_test(values, String.format("Area: %s%nPerimeter: %s%nInterior Angle: %s degrees", area, perimeter, interior));
	}
	
	public void testNumSides() {
		_test(new String[] {"-1", "1"}, E_SIDE_NUM);
		_test(new String[] {"0", "1"}, E_SIDE_NUM);
		_test(new String[] {"1", "1"}, E_SIDE_NUM);
		_test(new String[] {"2", "1"}, E_SIDE_NUM);
	}
	
	public void testSideLength() {
		_test(new String[] {"3", "-1"}, E_SIDE_LENGTH);
		_test(new String[] {"3", "0"}, E_SIDE_LENGTH);
	}
	
	public void testInt() {
		_testResult(new String[] {"3", "1"}, "0.433", "3.000", "60.000");
		_testResult(new String[] {"5", "1"}, "1.720", "5.000", "108.000");
		_testResult(new String[] {"7", "1"}, "3.634", "7.000", "128.571");
		_testResult(new String[] {"8", "1"}, "4.828", "8.000", "135.000");
	}
	
	public void testDec() {
		_testResult(new String[] {"3", "3.4"}, "5.006", "10.200", "60.000");
		_testResult(new String[] {"5", "8.7"}, "130.223", "43.500", "108.000");
		_testResult(new String[] {"7", "3.14"}, "35.829", "21.980", "128.571");
		_testResult(new String[] {"8", "0.878"}, "3.722", "7.024", "135.000");
	}
	
}
