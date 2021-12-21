package edu.wit.cs.comp1000.tests;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.security.Permission;

import edu.wit.cs.comp1000.PA4b;
import junit.framework.TestCase;

public class PA4bTestCase extends TestCase {
	
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
	
	private final static String E_INVALID = "Invalid guess, try again!%n";
	private final static String R_LOW = "Too low!%n";
	private final static String R_HIGH = "Too high!%n";
	private final static String R_WIN = "You win!%n";
	private final static String PROMPT = "Enter your guess (between 1 and 100): ";
	
	private void _test(String seed, String[] values, String[] result) {
		final String input = String.join(" ", values);
		
		final String output = TestSuite.stringOutput(result, new Object[] {});
		
		final ByteArrayOutputStream outContent = new ByteArrayOutputStream();
		
		System.setIn(new ByteArrayInputStream(input.getBytes()));
		System.setOut(new PrintStream(outContent));
		
		try {
			PA4b.main(new String[] { seed });
		} catch (ExitException e) {}
		assertEquals(output, outContent.toString());
		
		System.setIn(null);
		System.setOut(null);
	}
	
	private void _testQuick(String seed, String outcome) {
		_test(
			seed,
			new String[] { outcome },
			new String[] { PROMPT, R_WIN }
		);
	}
	
	public void testQuick() {
		_testQuick("1000", "22");
		_testQuick("4050", "12");
		_testQuick("3770", "57");
		_testQuick("2670", "50");
		_testQuick("3670", "86");
		_testQuick("1070", "5");
		_testQuick("2071", "94");
		_testQuick("3370", "44");
	}
	
	public void testInvalid() {
		_test(
			"1070",
			new String[] { "0", "5" },
			new String[] { PROMPT, E_INVALID, PROMPT, R_WIN }
		);
		
		_test(
			"1000",
			new String[] { "-1", "-2", "119", "22" },
			new String[] { PROMPT, E_INVALID, PROMPT, E_INVALID, PROMPT, E_INVALID, PROMPT, R_WIN }
		);
	}
	
	public void testGame() {
		_test(
			"1070",
			new String[] { "50", "0", "101", "25", "12", "6", "3", "4", "5" },
			new String[] { 
				PROMPT, R_HIGH,
				PROMPT, E_INVALID,
				PROMPT, E_INVALID,
				PROMPT, R_HIGH,
				PROMPT, R_HIGH,
				PROMPT, R_HIGH,
				PROMPT, R_LOW,
				PROMPT, R_LOW,
				PROMPT, R_WIN
			}
		);
	}

}
