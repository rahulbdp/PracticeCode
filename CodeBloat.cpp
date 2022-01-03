// what is code bloating
// Code bloat is the production of code that is perceived as unnecessarily long, slow, or otherwise wasteful of resources. 
// It is a problem in Software Development which makes the length of the code of software long unnecessarily. 
// So for writing the quality code, we always avoid code bloating in our program.

//Effects of Code Bloat:
//    It creates object of some classes unnecessarily that can make our software slow in execution.
//    It is a problem in Software Development which made the length of code of software long unnecessarily.


#include <iostream>

using namespace std;

int main()
{
	//The string variable is redundant as the constant sentence can be printed directly. The string object adds unnecessary lines of assembly code.
	string str("C++ is awesome");
	
	cout<<str<<endl;
	
	return 0;
}