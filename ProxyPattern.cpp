#include <iostream>

using namespace std;

class actualClass
{
	int index = 0;
	
	public:
	actualClass()
	{
		cout<<"Actual class constructor called"<<endl;
	}
	
	~actualClass()
	{
		cout<<"Actual class destructor called"<<endl;
	}
	
	void useActualClassObject()
	{
		cout<<"useActualClassObject() called"<<endl;
		cout<<"Index ="<<index<<endl;
	}
};

class proxyClass
{
	actualClass* actualObj = nullptr;
	
	public:
	proxyClass()
	{
		cout<<"Proxy class constructor called"<<endl;
	}
	
	~proxyClass()
	{
		cout<<"Proxy class destructor called"<<endl;
	}
	
	void useActualClassObject()
	{
		cout<<"Creating actualClass Object"<<endl;
		actualObj = new actualClass;
		actualObj->useActualClassObject();
	}
};

int main()
{
	bool option = false;
	cout<<"Do you want to create the object (1 or 0)"<<endl;
	cin>>option;
	
	if (true == option)
	{
		proxyClass* obj = new proxyClass;
		
			cout<<"Do you want to use the object (1 or 0)"<<endl;
			cin>>option;
			
			if (true == option)
			{
				obj->useActualClassObject();
			}
	}
	
	return 0;
}