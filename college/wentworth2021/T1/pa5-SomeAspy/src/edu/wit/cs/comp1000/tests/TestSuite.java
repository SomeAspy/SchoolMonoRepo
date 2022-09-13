package edu.wit.cs.comp1000.tests;

import org.junit.runner.RunWith;
import org.junit.runners.Suite;

@RunWith(Suite.class)
@Suite.SuiteClasses({
	PA5aTestCase.class,
	PA5bTestCase.class,
})

public class TestSuite {
	
	static String stringOutput(String[] lines, Object[] values) {
		return String.format(String.join("", lines), values);
	}
	
}
