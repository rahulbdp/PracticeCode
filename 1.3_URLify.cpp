#include <iostream>

using namespace std;

void urlify(char data[], int size)
{
	/*
	EXAMPLE
	Input: "Mr John Smith ", 13
	Output: "Mr%20John%20Smith" */
	
	/* Pseudocode:
	1. Count the number of spaces in the input string.
	2. Count the final size of the string.
	3. Allocate appropriate space for the urlified string.
	4. Start copying the input string into output string buffer from end.
	5. In copying process if a space is found then replace the space with %20. */
	
	//Using C style character array
	cout<<"Original = "<<data<<endl;
	
	int numberofspaces = 0;
	for (int i = 0; i < size; i++)
	{
		if (data[i] == ' ')
			numberofspaces++;
	}
	
	int newsize = size + numberofspaces*2;
	
	for (int j = newsize-1; j >=0; j--)
	{
		if (data[size - 1] != ' ')
		{
			data[j] = data[size -1];
		}
		else
		{
			data[j] = '0';
			data[--j] = '2';
			data[--j] = '%';
		}
		size--;
	}
	
	cout<<"URLified = "<<data<<endl;
}

int main()
{
	char data[19] = "Rahul is great";
	urlify(data, 14);
	return 0;
}