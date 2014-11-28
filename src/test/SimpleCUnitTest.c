#include "SimpleCUnit.h"

void shouldntPass(){
	assertTrue("Assert should pass", 1 == 1);
	assertTrue("Assert should fail", 1 == 2);
	printf("You never see me!");
}	

void shouldPass(){
	assertTrue("Assert should pass", 1 == 1);
}

int main(){
	testSuit("Contain 1 error suit", 2, 
		initTestCase("Fail test case", &shouldntPass),
		initTestCase("Pass test case", &shouldPass));
	
	testSuit("No one error suit", 1, 
		initTestCase("Pass test case", &shouldPass));
	
	return 0;
}
