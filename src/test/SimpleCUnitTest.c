#include "SimpleCUnit.h"

void shouldntPass(){
	assertTrue("Should pass", 1 == 1);
	assertTrue("Shouldn't pass", 1 == 2);
	printf("Shouldn't see this");
}


void shouldPass(){
	assertTrue("Should pass", 1 == 1);
}

int main(){
	testSuit("Fail test suit", 1, 
		initTestCase("Fail test", &shouldntPass)
	);
	
	testSuit("Pass test suit", 1, 
		initTestCase("Pass test", &shouldPass)
	);
		
	return 0;
}
