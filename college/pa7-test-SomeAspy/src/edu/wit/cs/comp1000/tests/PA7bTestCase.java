package edu.wit.cs.comp1000.tests;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.PrintStream;
import java.security.Permission;

import edu.wit.cs.comp1000.PA7b;
import junit.framework.TestCase;

public class PA7bTestCase extends TestCase {
	
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
	
	private void _test(String[] values, String result) {
		final String input = String.join(" ", values);
		
		final String output = TestSuite.stringOutput(new String[] {
			"Enter file path: ",
			"%s" }, new Object[] { result });
		
		final ByteArrayOutputStream outContent = new ByteArrayOutputStream();
		
		System.setIn(new ByteArrayInputStream(input.getBytes()));
		System.setOut(new PrintStream(outContent));
		
		try {
			PA7b.main(new String[] { "foo" });
		} catch (ExitException e) {}
		assertEquals(output, outContent.toString());
		
		System.setIn(null);
		System.setOut(null);
	}
	
	private void _testBad(String path) {
		_test(new String[] {path}, String.format("Could not open %s!%n", path));
	}
	
	public void testBadFile() {
		_testBad(new File(PA7bTestCase.class.getResource("files").getPath(), "foo.txt").getAbsolutePath());
		_testBad(new File(PA7bTestCase.class.getResource("files").getPath(), "bar.txt").getAbsolutePath());
		_testBad(new File(PA7bTestCase.class.getResource("files").getPath(), "baz.txt").getAbsolutePath());
	}
	
	private void _testGood(String fName, String counts) {
		_test(
			new String[] {new File(PA7bTestCase.class.getResource("files").getPath(), fName).getAbsolutePath()}, 
			String.format(counts + "%n")
		);
	}
	
	public void testEmpty() {
		_testGood("bi1.txt", "");
	}
	
	public void testZero() {
		_testGood("bi2.txt", "");
	}
	
	public void testLettersLower() {
		_testGood("bi3.txt", "A: 1%nB: 2%nC: 3%nD: 4%nE: 5");
	}
	
	public void testLettersUpper() {
		_testGood("bi4.txt", "A: 1%nB: 2%nC: 3%nD: 4%nE: 5");
	}
	
	public void testLettersMixed() {
		_testGood("bi5.txt", "A: 1%nB: 2%nC: 3%nD: 4%nE: 5");
	}
	
	public void testHelloWorld() {
		_testGood("bi6.txt", "D: 1%nE: 1%nH: 1%nL: 3%nO: 2%nR: 1%nW: 1");
	}
	
}
