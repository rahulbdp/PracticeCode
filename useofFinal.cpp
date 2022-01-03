# include <iostream>

using namespace std;

class Base final
{
   public:
      virtual void print() final
	  {
		  cout<<"var ="<<10<<endl;
	  }
};

class Derived: public Base
{
	public:
	   virtual void print()
	   {
		   cout<<"var ="<<20<<endl;
	   }
};

int main()
{
   Base* b = new Base;
   Base* d = new Derived;
   
   b->print();
   d->print();
   
   return (0);
}
