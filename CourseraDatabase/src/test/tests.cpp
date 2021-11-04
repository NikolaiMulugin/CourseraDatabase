#include "tests.h"

//using namespace std;
void EqualityTest(){
	Assert(3+4 == 7, "3+4==7");
}

void CharEqualityTest(){
	Assert('a' == 'a', "a = a");
	Assert('0' == '0', "0 = 0");
}

void AllTests(){
	TestRunner tr;
	tr.RunTest(EqualityTest, "EqualityTest");
	tr.RunTest(CharEqualityTest, "CharEqualityTest");

}



