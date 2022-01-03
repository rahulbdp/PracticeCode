#include <iostream>

using namespace std;

class commands
{
	public:
	commands()
	{
		cout<<"commands object created"<<endl;
	}
};

class command1:public commands
{
	public:
	command1()
	{
		cout<<"command1 object created"<<endl;
	}
};

class command2:public commands
{
	public:
	command2()
	{
		cout<<"command2 object created"<<endl;
	}
};

class command3:public commands
{
	public:
	command3()
	{
		cout<<"command3 object created"<<endl;
	}
};

class factory
{
	public:
	commands* createCommand(int commandIndex)
	{
		commands* obj;
		switch(commandIndex)
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
			cout<<"commandIndex undefined"<<endl;
		}
	}
};


int main()
{
	factory commandFactory;
	commands* commandObject = nullptr;
	int commandIndex = 0;

	while (commandIndex != 9)
	{
		cout<<"enter the object to be created (9 for Exit)"<<endl;
		cin>>commandIndex;
		commandObject = commandFactory.createCommand(commandIndex);
	}
	
	return (0);
}