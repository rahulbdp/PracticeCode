#include <iostream>

using namespace std;

class singleton
{
	private:
	singleton()
	{
		cout<<"Default Constructor Called"<<endl;
	}
	
	singleton& operator=(singleton& pSingleton)
	{
		cout<<"Assignment Operator Called"<<endl;
	}
	
	singleton(const singleton& obj)
	{
		cout<<"lvalue reference called"<<endl;
	}
	
	singleton(singleton&& obj)
	{
		cout<<"rvalue reference called"<<endl;
	}
	
	virtual ~singleton()
	{
		cout<<"Destructor called"<<endl;
		instance = nullptr;
	}
	
	static singleton* instance;
	
	public:
	static singleton* getInstance()
	{
		cout<<"getInstance Called"<<endl;
		if (instance == nullptr)
			instance =  new singleton;
		return instance;
	}
};

singleton* singleton::instance = nullptr;

int main()
{
	singleton* obj = singleton::getInstance();
	cout<<"obj = "<<obj<<endl;
	singleton* obj1 = move(obj);
	
	cout<<"obj = "<<obj<<endl;
	cout<<"obj1 = "<<obj1<<endl;
	return 0;
}