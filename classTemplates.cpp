#include <iostream>

using namespace std;

template <class T>

class array
{
	public:
	array(int pLen): len(pLen), data(new T[pLen]) {}
	~array()
	{
		delete [] data;
	}
	
	void printArray()
	{
		for(int i = 0; i<len; i++)
		{
			cout<<data[i]<<endl;
		}
	}
	
	void setArray(T* value, int pLen)
	{
		len = pLen;
		for (int i = 0; i < len;i++)
		{
			data[i] = value[i];
		}
	}
		
	private:
	int len = 0;
	T* data;
};

int main()
{
	array<int> A(5);
	array<float> B(5);
	
	int val1[] = {1,2,3,4,5};
	float val2[] = {1.1,1.2,1.3,1.4,1.5};
	A.setArray(val1,5);
	B.setArray(val2,5);
	
	A.printArray();
	B.printArray();
	
	return (0);
}