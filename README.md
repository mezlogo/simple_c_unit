Simple unit test framework for C.

For linux os, cos' use color terminal codes.

0) Why:

I learning C, but have some problem with other test framework. Before i use minunit test framework, which is pretty genius, but it have 2 problem:
1 - many rows of boring code (huge runner, all tests pointer, every test case must return message with success is just 0)
2 - not very informative success / fail message
I was inspired by K. Beck book's and XUnit pattern, especially JUnit, with pretty good log information. 

1) Usage:

Test suit is contain multiple test cases, and test suit name.
Signature:
void testSuit(char* testSuitName, int testCount, ...) 

Test case in contain function pointer (which contain all assertions) and name of test case. 
Signature:
typedef struct TestCase{
	char* testName;
	void (*testMethodPointer)();
} TestCase;


Test method pointer should point to method, which contain assertions and must have signature:
void testCaseName()

Assertion is macros, which signature is:
assertTrue(errorMessage, test)

Example:
Inside someFuncTest.c
#include "SimpleCUnit.h"

void shouldntPass(){
	assertTrue("Assert should pass", 1 == 1);
	assertTrue("Assert should fail", 1 == 2);
	printf("You never see me!");
}

int main(){
	testSuit("My first test suit", 1, initTestCase("Fail test case", &shouldntPass));
	return 0;
}

All we do is just give some useful name for out test suit and test cases. 
Example contain only 1 case and helpful method initTestCase, as TestCase struct constructor.

Report:
-------------------------------------------------------------
Start test suit: My first test suit contain 1 test cases.
Num.  |Test case name                |Status
1     |Fail test case                |FAIL 
Error #1 in shouldntPass(src/test/SimpleCUnitTest.c:5): Assert should fail.
End of My first test suit. Contain 1 errors.
