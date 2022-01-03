#include <iostream>

using namespace std;

class commands
{
	public:
	commands()
	{
		cout<<"commands constructor called"<<endl;
	}
	
	virtual void execute() = 0;
};

class command1:public commands
{
	public:
	command1()
	{
		cout<<"command1 constructor called"<<endl;
	}
	
	void execute()
	{
		cout<<"Execute: command1"<<endl;
	}
};

class command2:public commands
{
	public:
	command2()
	{
		cout<<"command2 constructor called"<<endl;
	}
	
	void execute()
	{
		cout<<"Execute: command2"<<endl;
	}
};

class command3:public commands
{
	public:
	command3()
	{
		cout<<"command3 constructor called"<<endl;
	}
	
	void execute()
	{
		cout<<"Execute: command3"<<endl;
	}
};

class commandManager
{
	//This should be singleton class
	public:
	commandManager()
	{
		cout<<"commandManager Constructor called"<<endl;
	}
	
	void ProcessCommand(int index)
	{
		commands* obj = nullptr;
		switch (index)
		{
			case 1:
				obj = new command1;
				break;
			
			case 2:
				obj = new command2;
				break;
			
			case 3:
				obj = new command3;
				break;
			
			default:
				cout<<"undefined Index"<<endl;
		}
		
		if (obj != nullptr)
			obj->execute();
	}
};

int main()
{
	int index = 0;
	commandManager Manager;
	
	cout<<"Enter the command"<<endl;
	cin>>index;
	Manager.ProcessCommand(index);
		
	return 0;
}