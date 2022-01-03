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

class linuxCommands: public commands
{
	public:
	linuxCommands()
	{
		cout<<"LinuxCommands object Created"<<endl;
	}
};

class windowsCommands: public commands
{
	public:
	windowsCommands()
	{
		cout<<"windowsCommands object Created"<<endl;
	}
};

class linuxCommand1: public linuxCommands
{
	public:
	linuxCommand1()
	{
		cout<<"Linux Command1 object Created"<<endl;
	}
};

class linuxCommand2: public linuxCommands
{
	public:
	linuxCommand2()
	{
		cout<<"Linux Command2 object Created"<<endl;
	}
};

class windowsCommand1: public windowsCommands
{
	public:
	windowsCommand1()
	{
		cout<<"windowsCommand1 object Created"<<endl;
	}
};

class windowsCommand2: public windowsCommands
{
	public:
	windowsCommand2()
	{
		cout<<"windowsCommand2 object Created"<<endl;
	}
};

class abstractFactory
{
	public:
	abstractFactory()
	{
		cout<<"abstractFactory object created"<<endl;
	}
	virtual commands* createCommand(int commandIndex) = 0;
};

class linuxFactory:public abstractFactory
{
	public:
	linuxFactory()
	{
		cout<<"linuxFactory Created"<<endl;
	}
	
	commands* createCommand(int commandIndex) 
	{
		switch(commandIndex)
		{
			case 1:
			return new linuxCommand1;
			break;
			
			case 2:
			return new linuxCommand2;
			
			default:
			cout<<"Undefined command Index"<<endl;
		}
	}	
};

class windowsFactory:public abstractFactory
{
	public:
	windowsFactory()
	{
		cout<<"windowsFactory Created"<<endl;
	}
	
	commands* createCommand(int commandIndex) 
	{
		switch(commandIndex)
		{
			case 1:
			return new windowsCommand1;
			break;
			
			case 2:
			return new windowsCommand2;
			
			default:
			cout<<"Undefined command Index"<<endl;
		}
	}	
};


int main()
{
	abstractFactory* linuxFactoryObj = new linuxFactory;
	abstractFactory* windowsFactoryObj = new windowsFactory;
	
	commands* cmd = nullptr;
	cmd = linuxFactoryObj->createCommand(1);
	cmd = linuxFactoryObj->createCommand(2);
	
	cmd = windowsFactoryObj->createCommand(1);
	cmd = windowsFactoryObj->createCommand(2);
		
	return 0;
}