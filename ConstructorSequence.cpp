#include <iostream>

using namespace std;

class Base
{
	public:
	Base()
	{
		cout<<"Base Constructor Called"<<endl;
	}
	
	virtual ~Base()
	{
		cout<<"Base Destructor Called"<<endl;
	}
};



class Derived: public Base
{
	public:
	Derived()
	{
		cout<<"Derived Constructor Called"<<endl;
	}
	
	~Derived()
	{
		cout<<"Derived Destructor Called"<<endl;
	}
};



int main()
{
   Base* a = new Base;
   Base* b = new Derived;
   
   delete(a);
   delete(b);
   
   return(0);
}