package edu.wit.cs.comp1000.tests;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.security.Permission;

import edu.wit.cs.comp1000.PA5a;
import junit.framework.TestCase;

public class PA5aTestCase extends TestCase {
	
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
	
	private static String _letter(String[] tmp) {
		return String.format("%n" + String.join("%n", tmp) + "%n%n");
	}
	
	private final static String L_BLANK = _letter(new String[] {
		"",
	});
	
	private final static String L_D = _letter(new String[] {
		"*******",
		"*     *",
		"*     *",
		" *   * ",
		"  ***  "
	});
	
	private final static String L_E = _letter(new String[] {
		"*******",
		"*  *  *",
		"*  *  *",
		"*  *  *",
		"*  *  *"
	});
	
	private final static String L_H = _letter(new String[] {
		"*******",
		"   *   ",
		"   *   ",
		"   *   ",
		"*******"
	});
	
	private final static String L_L = _letter(new String[] {
		"*******",
		"*      ",
		"*      ",
		"*      ",
		"*      "
	});
	
	private final static String L_O = _letter(new String[] {
		"*******",
		"*     *",
		"*     *",
		"*     *",
		"*******"
	});
	
	private final static String L_R = _letter(new String[] {
		"*******",
		"   *  *",
		"  **  *",
		" * ****",
		"*      "
	});
	
	private final static String L_W = _letter(new String[] {
		"*******",
		"*      ",
		"****   ",
		"*      ",
		"*******"
	});
	
	private void _test(String[] values, String result) {
		final String input = String.join(" ", values);
		
		final String output = TestSuite.stringOutput(new String[] {
			"Input message: ",
			"%s" }, new Object[] { result });
		
		final ByteArrayOutputStream outContent = new ByteArrayOutputStream();
		
		System.setIn(new ByteArrayInputStream(input.getBytes()));
		System.setOut(new PrintStream(outContent));
		
		try {
			PA5a.main(new String[] { "foo" });
		} catch (ExitException e) {}
		assertEquals(output, outContent.toString());
		
		System.setIn(null);
		System.setOut(null);
	}
	
	public void testEmpty() {
		_test(new String[] {"a"}, "");
		_test(new String[] {"b"}, "");
		_test(new String[] {"c"}, "");
//		_test(new String[] {"d"}, "");
//		_test(new String[] {"e"}, "");
		_test(new String[] {"f"}, "");
		_test(new String[] {"g"}, "");
//		_test(new String[] {"h"}, "");
		_test(new String[] {"i"}, "");
		_test(new String[] {"j"}, "");
		_test(new String[] {"k"}, "");
//		_test(new String[] {"l"}, "");
		_test(new String[] {"m"}, "");
		_test(new String[] {"n"}, "");
//		_test(new String[] {"o"}, "");
		_test(new String[] {"p"}, "");
		_test(new String[] {"q"}, "");
//		_test(new String[] {"r"}, "");
		_test(new String[] {"s"}, "");
		_test(new String[] {"t"}, "");
		_test(new String[] {"u"}, "");
		_test(new String[] {"v"}, "");
//		_test(new String[] {"w"}, "");
		_test(new String[] {"x"}, "");
		_test(new String[] {"y"}, "");
		_test(new String[] {"z"}, "");
		_test(new String[] {"!"}, "");
		_test(new String[] {"."}, "");
		_test(new String[] {"?"}, "");
		_test(new String[] {"abcfgijkmnpqstuvxyz!.?"}, "");
	}
	
	public void testBlank() {
		_test(new String[] {" "}, L_BLANK);
		_test(new String[] {"  "}, L_BLANK + L_BLANK);
	}
	
	public void testLetterLower() {
		_test(new String[] {"d"}, L_D);
		_test(new String[] {"dd"}, L_D + L_D);
		
		_test(new String[] {"e"}, L_E);
		_test(new String[] {"ee"}, L_E + L_E);
		
		_test(new String[] {"h"}, L_H);
		_test(new String[] {"hh"}, L_H + L_H);
		
		_test(new String[] {"l"}, L_L);
		_test(new String[] {"ll"}, L_L + L_L);
		
		_test(new String[] {"o"}, L_O);
		_test(new String[] {"oo"}, L_O + L_O);
		
		_test(new String[] {"r"}, L_R);
		_test(new String[] {"rr"}, L_R + L_R);
		
		_test(new String[] {"w"}, L_W);
		_test(new String[] {"ww"}, L_W + L_W);
	}
	
	public void testHelloWorld() {
		_test(new String[] {"Hello World!"}, L_H + L_E + L_L + L_L + L_O + L_BLANK + L_W + L_O + L_R + L_L + L_D);
	}
	
}
