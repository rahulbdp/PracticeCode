#include <iostream>

using namespace std;

/*
Finding Prime Numbers:
1. Loop for the range in which prime numbers has to be found. Start from 3 and 1 & 2 are not prime numbers 
2. Check if the number is not an even number or divisibe by 3 or 5.
3.  

*/

bool checkPrimeNumber( int inputNumber )
{
	bool isPrime = true;
	
	int halfInputNum = inputNumber/2;
	
	if ( inputNumber == 2 )
		return true;
	else if ( inputNumber == 3 )
		return true;
	else if ( inputNumber <= 1 )
		return false;
	else	if ( inputNumber % 2 == 0 )
		return false;
	else if ( inputNumber % 3 == 0 )
		return false;
	else
	{
		for (int div = 5; div <= halfInputNum; div+=2)
		{
			if ( inputNumber % div == 0 )
				return false;
		}
	}
	
	return isPrime;
}

int main()
{
	int inpNum = 1;
	
	while (inpNum != 0)
	{
		cout<<"Enter the number to check if its Prime"<<endl;
		cin>>inpNum;
	
		cout<<"The Number "<<inpNum<<" is Prime = "<<checkPrimeNumber(inpNum)<<endl;
	}
	
	return 0;
}