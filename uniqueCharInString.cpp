#include <iostream>

using namespace std;

bool isUnique(string inputStr)
{
	bool isUnique = false;
	bool asciiArray[256] ;
	
	if (inputStr.size() >= 256)
		return false;
	
	//loop way 1
	for (auto itr = inputStr.begin(); itr < inputStr.end(); itr++)
	{
		int index = *itr;
		if (asciiArray[index] == false)
		{
			asciiArray[index] = true;
		}
		else
			return false;
	}
	
	//loop way 2
	for ( auto &ch: inputStr)
	{
		if (asciiArray[ch] == false)
		{
			asciiArray[ch] = true;
		}
		else
			return false;
	}
	
	return true;
}

int main()
{
	cout<<"The characters in string \"rahul\" are unique = "<<isUnique("raahul")<<endl;
	
	return 0;
}


// Facing problem: looping iterator in C++, initializing an array, printing "" in cout 