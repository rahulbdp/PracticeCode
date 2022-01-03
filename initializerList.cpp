#include <iostream>
#include <string>
#include <vector>

using namespace std;

class array
{
	public:
	array(initializer_list<string> args)
	{
		for (auto i = args.begin(); i!=args.end(); i++)
		{
			var.push_back(*i);
		}
	}
	
	void printArray()
	{
		for (auto i = var.begin(); i !=var.end(); i++)
		{
			cout<<*i<<endl;
		}
	}
	
	private:
	vector<string> var;
};


int main()
{
	array a{"one","two","three","four","five"};
	a.printArray();
	return (0);
}
	