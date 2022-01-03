#include <iostream>

using namespace std;

int main()
{
	int array[] = {1,2,3,4};
	int arraySize = sizeof(array)/sizeof(array[0]);
	
	for (int i = 0; i < arraySize; i++)
	{
		for (int j = i; j < arraySize; j++)
		{
			for (int k = i; k <= j; k++)
			{
				cout<<array[k]<<"  ";
			}
			cout<<endl;
		}
	}
	
	return 0;
}


/*
Array - 1,2,3,4
Finding all Subarrays:
1
1,2
1,2,3
1,2,3,4
2
2,3
2,3,4
3
3,4
4
*/