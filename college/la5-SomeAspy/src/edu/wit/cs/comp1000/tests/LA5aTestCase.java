package edu.wit.cs.comp1000.tests;

import static org.junit.Assert.assertArrayEquals;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.security.Permission;

import edu.wit.cs.comp1000.LA5a;
import junit.framework.TestCase;

public class LA5aTestCase extends TestCase {
	
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
	
	private void _testGCD(int a, int b, int expected) {
		Integer result = null;
		try {
			result = LA5a.gcd(a, b);
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
	
	private void _testSimplify(int n, int d, int eN, int eD) {
		int[] result = null;
		try {
			result = LA5a.simplifyFraction(new int[] {n, d});
		} catch (ExitException e) {}
		assertArrayEquals(new int[] {eN, eD}, result);
	}
	
	public void testSimplify() {
		_testSimplify(0, 1, 0, 1);
		_testSimplify(0, 2, 0, 1);
		_testSimplify(0, 7, 0, 1);
		
		_testSimplify(0, -1, 0, 1);
		_testSimplify(0, -2, 0, 1);
		_testSimplify(0, -7, 0, 1);
		
		_testSimplify(1, 2, 1, 2);
		_testSimplify(2, 4, 1, 2);
		_testSimplify(3, 6, 1, 2);
		
		_testSimplify(-1, -2, 1, 2);
		_testSimplify(-1, 2, -1, 2);
		_testSimplify(1, -2, -1, 2);
		
		_testSimplify(17, 289, 1, 17);
		
		_testSimplify(4, 2, 2, 1);
		_testSimplify(-4, -2, 2, 1);
		_testSimplify(-4, 2, -2, 1);
		_testSimplify(4, -2, -2, 1);
	}
	
	private void _testAdd(int num1, int den1, int num2, int den2, int eNum, int eDen) {
		int[] result = null;
		try {
			result = LA5a.addFractions(new int[] {num1, den1}, new int[] {num2, den2});
		} catch (ExitException e) {}
		assertArrayEquals(new int[] {eNum, eDen}, result);
	}
	
	public void testAdd() {
		_testAdd(0, 1, 0, 1, 0, 1);
		_testAdd(0, 2, 0, 3, 0, 1);
		
		_testAdd(0, 7, 1, 3, 1, 3);
		_testAdd(1, 3, 0, 7, 1, 3);
		_testAdd(2, 4, 0, 7, 1, 2);
		
		_testAdd(0, 7, -2, 4, -1, 2);
		_testAdd(0, 7, 2, -4, -1, 2);
		_testAdd(-2, 4, 0, 7, -1, 2);
		_testAdd(2, -4, 0, 7, -1, 2);
		
		_testAdd(1, 2, 1, 2, 1, 1);
		_testAdd(1, 2, 2, 4, 1, 1);
		_testAdd(2, 4, 1, 2, 1, 1);
		_testAdd(3, 6, 4, 8, 1, 1);
		
		_testAdd(1, 3, 1, 3, 2, 3);
		_testAdd(1, 7, 1, 7, 2, 7);
		_testAdd(1, 7, 2, 7, 3, 7);
		_testAdd(2, 7, 1, 7, 3, 7);
		_testAdd(2, 7, 4, 7, 6, 7);
		_testAdd(4, 7, 2, 7, 6, 7);
		
		_testAdd(7, 4, 2, 7, 57, 28);
		_testAdd(4, 7, 7, 2, 57, 14);
		_testAdd(7, 4, 7, 2, 21, 4);
		_testAdd(8, 4, 7, 2, 11, 2);
	}
	
	private void _testSubtract(int num1, int den1, int num2, int den2, int eNum, int eDen) {
		int[] result = null;
		try {
			result = LA5a.subtractFractions(new int[] {num1, den1}, new int[] {num2, den2});
		} catch (ExitException e) {}
		assertArrayEquals(new int[] {eNum, eDen}, result);
	}
	
	public void testSubtract() {
		_testSubtract(0, 1, 0, 1, 0, 1);
		_testSubtract(0, 2, 0, 3, 0, 1);
		
		_testSubtract(0, 7, 1, 3, -1, 3);
		_testSubtract(0, 7, 2, 10, -1, 5);
		_testSubtract(1, 3, 0, 7, 1, 3);
		_testSubtract(2, 4, 0, 7, 1, 2);
		
		_testSubtract(1, 3, 2, 6, 0, 1);
		_testSubtract(2, 4, 2, 4, 0, 1);
		
		_testSubtract(0, 4, 1, 4, -1, 4);
		_testSubtract(1, 4, 1, 4, 0, 1);
		_testSubtract(1, 2, 1, 4, 1, 4);
		_testSubtract(3, 4, 1, 4, 1, 2);
		_testSubtract(1, 1, 1, 4, 3, 4);
		_testSubtract(5, 4, 1, 4, 1, 1);
		_testSubtract(3, 2, 1, 4, 5, 4);
		_testSubtract(7, 4, 1, 4, 3, 2);
		_testSubtract(2, 1, 1, 4, 7, 4);
		
		_testSubtract(0, 4, -1, 4, 1, 4);
		_testSubtract(1, 4, -1, 4, 1, 2);
		_testSubtract(1, 2, -1, 4, 3, 4);
		_testSubtract(3, 4, -1, 4, 1, 1);
		_testSubtract(1, 1, -1, 4, 5, 4);
		_testSubtract(5, 4, -1, 4, 3, 2);
		_testSubtract(3, 2, -1, 4, 7, 4);
		_testSubtract(7, 4, -1, 4, 2, 1);
		_testSubtract(2, 1, -1, 4, 9, 4);
		
		_testSubtract(0, 4, 1, -4, 1, 4);
		_testSubtract(1, 4, 1, -4, 1, 2);
		_testSubtract(1, 2, 1, -4, 3, 4);
		_testSubtract(3, 4, 1, -4, 1, 1);
		_testSubtract(1, 1, 1, -4, 5, 4);
		_testSubtract(5, 4, 1, -4, 3, 2);
		_testSubtract(3, 2, 1, -4, 7, 4);
		_testSubtract(7, 4, 1, -4, 2, 1);
		_testSubtract(2, 1, 1, -4, 9, 4);
		
		_testSubtract(1, 4, 0, 4, 1, 4);
		_testSubtract(1, 4, 1, 4, 0, 1);
		_testSubtract(1, 4, 1, 2, -1, 4);
		_testSubtract(1, 4, 3, 4, -1, 2);
		_testSubtract(1, 4, 1, 1, -3, 4);
		_testSubtract(1, 4, 5, 4, -1, 1);
		_testSubtract(1, 4, 3, 2, -5, 4);
		_testSubtract(1, 4, 7, 4, -3, 2);
		_testSubtract(1, 4, 2, 1, -7, 4);
		
		_testSubtract(-1, 4, 0, 4, -1, 4);
		_testSubtract(-1, 4, 1, 4, -1, 2);
		_testSubtract(-1, 4, 1, 2, -3, 4);
		_testSubtract(-1, 4, 3, 4, -1, 1);
		_testSubtract(-1, 4, 1, 1, -5, 4);
		_testSubtract(-1, 4, 5, 4, -3, 2);
		_testSubtract(-1, 4, 3, 2, -7, 4);
		_testSubtract(-1, 4, 7, 4, -2, 1);
		_testSubtract(-1, 4, 2, 1, -9, 4);
	}
	
	private void _testMultiply(int num1, int den1, int num2, int den2, int eNum, int eDen) {
		int[] result = null;
		try {
			result = LA5a.multiplyFractions(new int[] {num1, den1}, new int[] {num2, den2});
		} catch (ExitException e) {}
		assertArrayEquals(new int[] {eNum, eDen}, result);
	}
	
	public void testMultiply() {
		_testMultiply(0, 7, 5, 8, 0, 1);
		_testMultiply(0, 7, 0, 8, 0, 1);
		
		_testMultiply(1, 7, 1, 8, 1, 56);
		_testMultiply(-1, 7, 1, 8, -1, 56);
		_testMultiply(1, -7, 1, 8, -1, 56);
		_testMultiply(1, 7, -1, 8, -1, 56);
		_testMultiply(1, 7, 1, -8, -1, 56);
		_testMultiply(-1, 7, 1, -8, 1, 56);
		_testMultiply(1, -7, -1, 8, 1, 56);
		_testMultiply(-1, -7, -1, -8, 1, 56);
		
		_testMultiply(2, 5, 50, 20, 1, 1);
	}
	
	private void _testDivide(int num1, int den1, int num2, int den2, int eNum, int eDen) {
		int[] result = null;
		try {
			result = LA5a.divideFractions(new int[] {num1, den1}, new int[] {num2, den2});
		} catch (ExitException e) {}
		assertArrayEquals(new int[] {eNum, eDen}, result);
	}
	
	public void testDivide() {
		_testDivide(0, 7, 5, 8, 0, 1);
		
		_testDivide(2, 5, 50, 20, 4, 25);
		_testDivide(2, 5, 20, 50, 1, 1);
		
		_testDivide(1, 7, 1, 8, 8, 7);
		_testDivide(-1, 7, 1, 8, -8, 7);
		_testDivide(1, -7, 1, 8, -8, 7);
		_testDivide(1, 7, -1, 8, -8, 7);
		_testDivide(1, 7, 1, -8, -8, 7);
		_testDivide(-1, 7, 1, -8, 8, 7);
		_testDivide(1, -7, -1, 8, 8, 7);
		_testDivide(-1, -7, -1, -8, 8, 7);
	}
	
	private static final String E_DEN_ZERO = "Denominator cannot be zero.";
	private static final String E_OP_INVALID = "Invalid operation.";
	
	private void _test(String[] values, String result) {
		final String input = String.join(" ", values);
		
		final String output = TestSuite.stringOutput(new String[] {
			"Enter the numerator for the first fraction: ",
			"Enter the denominator for the first fraction: ",
			"Enter the numerator for the second fraction: ",
			"Enter the denominator for the second fraction: ",
			"Enter the operation (+, -, *, /): ",
			"%s%n" }, new Object[] {result});
		
		final ByteArrayOutputStream outContent = new ByteArrayOutputStream();
		
		System.setIn(new ByteArrayInputStream(input.getBytes()));
		System.setOut(new PrintStream(outContent));
		
		try {
			LA5a.main(new String[] { "foo" });
		} catch (ExitException e) {}
		assertEquals(output, outContent.toString());
		
		System.setIn(null);
		System.setOut(null);
	}
	
	public void testOp() {
		_test(new String[] {"1", "2", "3", "4", "?"}, E_OP_INVALID);
		_test(new String[] {"1", "2", "3", "4", "++"}, E_OP_INVALID);
		_test(new String[] {"1", "2", "3", "4", "--"}, E_OP_INVALID);
		_test(new String[] {"1", "2", "3", "4", "\\"}, E_OP_INVALID);
		_test(new String[] {"1", "2", "3", "4", "."}, E_OP_INVALID);
		_test(new String[] {"1", "2", "3", "4", "!"}, E_OP_INVALID);
		_test(new String[] {"1", "2", "3", "4", "_"}, E_OP_INVALID);
		_test(new String[] {"1", "2", "3", "4", "#"}, E_OP_INVALID);
	}
	
	public void testDenom() {
		_test(new String[] {"1", "2", "3", "0", "+"}, E_DEN_ZERO);
		_test(new String[] {"1", "2", "3", "0", "-"}, E_DEN_ZERO);
		_test(new String[] {"1", "2", "3", "0", "*"}, E_DEN_ZERO);
		_test(new String[] {"1", "2", "3", "0", "/"}, E_DEN_ZERO);
		
		_test(new String[] {"1", "0", "3", "4", "+"}, E_DEN_ZERO);
		_test(new String[] {"1", "0", "3", "4", "-"}, E_DEN_ZERO);
		_test(new String[] {"1", "0", "3", "4", "*"}, E_DEN_ZERO);
		_test(new String[] {"1", "0", "3", "4", "/"}, E_DEN_ZERO);
		
		_test(new String[] {"1", "0", "3", "0", "+"}, E_DEN_ZERO);
		_test(new String[] {"1", "0", "3", "0", "-"}, E_DEN_ZERO);
		_test(new String[] {"1", "0", "3", "0", "*"}, E_DEN_ZERO);
		_test(new String[] {"1", "0", "3", "0", "/"}, E_DEN_ZERO);
	}
	
	private void _testProg(String[] input, String rN, String rD) {
		_test(input, String.format("%s/%s %s %s/%s = %s/%s", input[0], input[1], input[4], input[2], input[3], rN, rD));
	}
	
	private void _testProg(String[] input, String rN) {
		_test(input, String.format("%s/%s %s %s/%s = %s", input[0], input[1], input[4], input[2], input[3], rN));
	}
	
	public void testProgAdd() {
		_testProg(new String[] {"0", "1", "0", "1", "+"}, "0");
		_testProg(new String[] {"0", "2", "0", "3", "+"}, "0");
		
		_testProg(new String[] {"0", "7", "1", "3", "+"}, "1", "3");
		_testProg(new String[] {"1", "3", "0", "7", "+"}, "1", "3");
		_testProg(new String[] {"2", "4", "0", "7", "+"}, "1", "2");
		
		_testProg(new String[] {"0", "7", "-2", "4", "+"}, "-1", "2");
		_testProg(new String[] {"0", "7", "2", "-4", "+"}, "-1", "2");
		_testProg(new String[] {"-2", "4", "0", "7", "+"}, "-1", "2");
		_testProg(new String[] {"2", "-4", "0", "7", "+"}, "-1", "2");
		
		_testProg(new String[] {"1", "2", "1", "2", "+"}, "1");
		_testProg(new String[] {"1", "2", "2", "4", "+"}, "1");
		_testProg(new String[] {"2", "4", "1", "2", "+"}, "1");
		_testProg(new String[] {"3", "6", "4", "8", "+"}, "1");
		
		_testProg(new String[] {"1", "3", "1", "3", "+"}, "2", "3");
		_testProg(new String[] {"1", "7", "1", "7", "+"}, "2", "7");
		_testProg(new String[] {"1", "7", "2", "7", "+"}, "3", "7");
		_testProg(new String[] {"2", "7", "1", "7", "+"}, "3", "7");
		_testProg(new String[] {"4", "7", "2", "7", "+"}, "6", "7");
		_testProg(new String[] {"2", "7", "4", "7", "+"}, "6", "7");
		
		_testProg(new String[] {"7", "4", "2", "7", "+"}, "57", "28");
		_testProg(new String[] {"4", "7", "7", "2", "+"}, "57", "14");
		_testProg(new String[] {"7", "4", "7", "2", "+"}, "21", "4");
		_testProg(new String[] {"8", "4", "7", "2", "+"}, "11", "2");		
	}
	
	public void testProgSubtract() {
		_testProg(new String[] {"0", "1", "0", "1", "-"}, "0");
		_testProg(new String[] {"0", "2", "0", "3", "-"}, "0");
		
		_testProg(new String[] {"0", "7", "1", "3", "-"}, "-1", "3");
		_testProg(new String[] {"0", "7", "2", "10", "-"}, "-1", "5");
		_testProg(new String[] {"1", "3", "0", "7", "-"}, "1", "3");
		_testProg(new String[] {"2", "4", "0", "7", "-"}, "1", "2");
		
		_testProg(new String[] {"1", "3", "2", "6", "-"}, "0");
		_testProg(new String[] {"2", "4", "2", "4", "-"}, "0");
		
		_testProg(new String[] {"0", "4", "1", "4", "-"}, "-1", "4");
		_testProg(new String[] {"1", "4", "1", "4", "-"}, "0");
		_testProg(new String[] {"1", "2", "1", "4", "-"}, "1", "4");
		_testProg(new String[] {"3", "4", "1", "4", "-"}, "1", "2");
		_testProg(new String[] {"1", "1", "1", "4", "-"}, "3", "4");
		_testProg(new String[] {"5", "4", "1", "4", "-"}, "1");
		_testProg(new String[] {"3", "2", "1", "4", "-"}, "5", "4");
		_testProg(new String[] {"7", "4", "1", "4", "-"}, "3", "2");
		_testProg(new String[] {"2", "1", "1", "4", "-"}, "7", "4");
		
		_testProg(new String[] {"0", "4", "-1", "4", "-"}, "1", "4");
		_testProg(new String[] {"1", "4", "-1", "4", "-"}, "1", "2");
		_testProg(new String[] {"1", "2", "-1", "4", "-"}, "3", "4");
		_testProg(new String[] {"3", "4", "-1", "4", "-"}, "1");
		_testProg(new String[] {"1", "1", "-1", "4", "-"}, "5", "4");
		_testProg(new String[] {"5", "4", "-1", "4", "-"}, "3", "2");
		_testProg(new String[] {"3", "2", "-1", "4", "-"}, "7", "4");
		_testProg(new String[] {"7", "4", "-1", "4", "-"}, "2");
		_testProg(new String[] {"2", "1", "-1", "4", "-"}, "9", "4");
		
		_testProg(new String[] {"0", "4", "1", "-4", "-"}, "1", "4");
		_testProg(new String[] {"1", "4", "1", "-4", "-"}, "1", "2");
		_testProg(new String[] {"1", "2", "1", "-4", "-"}, "3", "4");
		_testProg(new String[] {"3", "4", "1", "-4", "-"}, "1");
		_testProg(new String[] {"1", "1", "1", "-4", "-"}, "5", "4");
		_testProg(new String[] {"5", "4", "1", "-4", "-"}, "3", "2");
		_testProg(new String[] {"3", "2", "1", "-4", "-"}, "7", "4");
		_testProg(new String[] {"7", "4", "1", "-4", "-"}, "2");
		_testProg(new String[] {"2", "1", "1", "-4", "-"}, "9", "4");

		_testProg(new String[] {"1", "4", "0", "4", "-"}, "1", "4");
		_testProg(new String[] {"1", "4", "1", "4", "-"}, "0");
		_testProg(new String[] {"1", "4", "1", "2", "-"}, "-1", "4");
		_testProg(new String[] {"1", "4", "3", "4", "-"}, "-1", "2");
		_testProg(new String[] {"1", "4", "1", "1", "-"}, "-3", "4");
		_testProg(new String[] {"1", "4", "5", "4", "-"}, "-1");
		_testProg(new String[] {"1", "4", "3", "2", "-"}, "-5", "4");
		_testProg(new String[] {"1", "4", "7", "4", "-"}, "-3", "2");
		_testProg(new String[] {"1", "4", "2", "1", "-"}, "-7", "4");

		_testProg(new String[] {"-1", "4", "0", "4", "-"}, "-1", "4");
		_testProg(new String[] {"-1", "4", "1", "4", "-"}, "-1", "2");
		_testProg(new String[] {"-1", "4", "1", "2", "-"}, "-3", "4");
		_testProg(new String[] {"-1", "4", "3", "4", "-"}, "-1");
		_testProg(new String[] {"-1", "4", "1", "1", "-"}, "-5", "4");
		_testProg(new String[] {"-1", "4", "5", "4", "-"}, "-3", "2");
		_testProg(new String[] {"-1", "4", "3", "2", "-"}, "-7", "4");
		_testProg(new String[] {"-1", "4", "7", "4", "-"}, "-2");
		_testProg(new String[] {"-1", "4", "2", "1", "-"}, "-9", "4");
	}
	
	public void testProgMultiply() {
		_testProg(new String[] {"0", "7", "5", "8", "*"}, "0");
		_testProg(new String[] {"0", "7", "0", "8", "*"}, "0");
		
		_testProg(new String[] {"1", "7", "1", "8", "*"}, "1", "56");
		_testProg(new String[] {"-1", "7", "1", "-8", "*"}, "1", "56");
		_testProg(new String[] {"1", "-7", "1", "8", "*"}, "-1", "56");
		_testProg(new String[] {"1", "7", "-1", "8", "*"}, "-1", "56");
		_testProg(new String[] {"1", "7", "1", "-8", "*"}, "-1", "56");
		_testProg(new String[] {"-1", "7", "1", "-8", "*"}, "1", "56");
		_testProg(new String[] {"1", "-7", "-1", "8", "*"}, "1", "56");
		_testProg(new String[] {"-1", "-7", "-1", "-8", "*"}, "1", "56");
		
		_testProg(new String[] {"2", "5", "50", "20", "*"}, "1");
	}
	
	public void testProgDivide() {
		_testProg(new String[] {"0", "7", "5", "8", "/"}, "0");
		
		_testProg(new String[] {"2", "5", "50", "20", "/"}, "4", "25");
		_testProg(new String[] {"2", "5", "20", "50", "/"}, "1");
		
		_testProg(new String[] {"1", "7", "1", "8", "/"}, "8", "7");
		_testProg(new String[] {"-1", "7", "1", "8", "/"}, "-8", "7");
		_testProg(new String[] {"1", "-7", "1", "8", "/"}, "-8", "7");
		_testProg(new String[] {"1", "7", "-1", "8", "/"}, "-8", "7");
		_testProg(new String[] {"1", "7", "1", "-8", "/"}, "-8", "7");
		_testProg(new String[] {"-1", "7", "1", "-8", "/"}, "8", "7");
		_testProg(new String[] {"1", "-7", "-1", "8", "/"}, "8", "7");
		_testProg(new String[] {"-1", "-7", "-1", "-8", "/"}, "8", "7");
	}

}
