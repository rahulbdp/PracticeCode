#include <iostream>

using namespace std;

int main()
{
	int array[] = {10,9,8,7,6,5,4,3,2,1};
	
	for (auto i = 0; i<10; i++)
	{
		cout<<"Loop 1"<<i<<endl;
		for (auto j = 0; j<i; j++)
		{
			cout<<"Loop 2"<<j<<endl;
			if (array[i]<array[j])
			{
				cout<<"array[i]>array[j]"<<endl;
				[&]() 
				{
					cout<<"Inside Lambda Function"<<i<<" "<<j<<endl;
					auto temp = array[i]; 
					array[i] = array[j]; 
					array[j] = temp;
				}();
			}
		}
	}
	
	for (auto i:array)
	{
		cout<<i<<endl;
	}
	
	return (0);
}