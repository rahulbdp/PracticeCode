#include <iostream>

using namespace std;

class burger
{
	public:
	burger()
	{
		cout<<"Burger Constructor Called"<<endl;
	}
	
	virtual void deliverOrder() = 0;
};

class vegBurger: public burger
{
	public:
	vegBurger()
	{
		cout<<"Veg Burger Constructor  Called"<<endl;
	}
	
	void deliverOrder()
	{
		cout<<"veg Burger delivered"<<endl;
	}	
};

class decorator: public burger
{
	burger* order;
	
	public:
	decorator(burger* pOrder)
	{
		order = pOrder;
	}
	
	void deliverOrder()
	{
		order->deliverOrder();
	}	
};

class softDrinkDecorator: public decorator
{
	public:
	softDrinkDecorator(burger* pOrder):decorator(pOrder)
	{
		cout<<"softDrinkDecorator constructor called"<<endl;
	}
	
	void deliverOrder()
	{
		decorator::deliverOrder();
		cout<<"soft drink delivered"<<endl;
	}	
};

class iceCreamDecorator: public decorator
{
	public:
	iceCreamDecorator(burger* pOrder):decorator(pOrder)
	{
		cout<<"iceCreamDecorator constructor called"<<endl;
	}
	
	void deliverOrder()
	{
		decorator::deliverOrder();
		cout<<"ice cream delivered"<<endl;
	}	
};

class friesDecorator: public decorator
{
	public:
	friesDecorator(burger* pOrder):decorator(pOrder)
	{
		cout<<"friesDecorator constructor called"<<endl;
	}
	
	void deliverOrder()
	{
		decorator::deliverOrder();
		cout<<"fries delivered"<<endl;
	}	
};

int main()
{
	cout<<"Order 1"<<endl;
	burger* order1 = new friesDecorator(new vegBurger);
	order1->deliverOrder();
	
	cout<<"Order 2"<<endl;
	burger* order2 = new friesDecorator(new softDrinkDecorator(new vegBurger));
	order2->deliverOrder();
	
	cout<<"Order 3"<<endl;
	burger* order3 = new softDrinkDecorator(new friesDecorator(new iceCreamDecorator(new vegBurger)));
	order3->deliverOrder();
	
	return 0;
}
