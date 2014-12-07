#include "SimpleCUnit.h"

void shouldntPass(){
	assertTrue("Assert should pass", 1 == 1);
	assertTrue("Assert should fail", 1 == 2);
	printf("You should never see me!");
}	

void shouldntPassLongEquals(){
	assertLongEquals("Assert long equals should pass, with expect: 2 actual: 2", 2, 2);
	assertLongEquals("Assert long equals should fail, with exp: 1, act: 2", 1, 2);
	printf("You should never see me!");
}	

void shouldntPassPointerEquals(){
	char some[1];
	char other[1];
	
	assertPointerEquals("Assert pointer equals should pass, with exp: some act: some", some, some);
	assertPointerEquals("Assert pointer equals should fail, with exp: some, act: other", some, other);
	printf("You should never see me!");
}

void shouldPass(){
	assertTrue("Assert should pass", 1 == 1);
}

int main(){
	testSuit("Contain 1 error suit", 3, 
		initTestCase("Fail test case assert true", &shouldntPass),
		initTestCase("Fail test case assert equals", &shouldntPassLongEquals),
		initTestCase("Fail test case assert pointer", &shouldntPassPointerEquals),
		initTestCase("Pass test case", &shouldPass));
	
	testSuit("No one error suit", 1, 
		initTestCase("Pass test case", &shouldPass));
	
	return 0;
}
