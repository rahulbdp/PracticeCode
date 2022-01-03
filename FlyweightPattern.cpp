#include<iostream>
#include <map>

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

class flyweightFactory
{
	//This class should be singleton
	flyweightFactory()
	{
	}
	
	static flyweightFactory* instance;
	map <int, commands*> commandlist;
	
	public:
	
	static flyweightFactory* getInstance()
	{
		if (instance == nullptr)
			instance = new flyweightFactory;
		
		return instance;
	}
	
	commands* getCommand(int index)
	{
		commands* obj = nullptr;

		for (auto itr = commandlist.begin(); itr != commandlist.end(); itr++)
		{
			cout <<itr->first<<" "<<itr->second<<endl;
		}
		if (commandlist[index] == nullptr)
		{
			switch (index)
			{
				case 1:
					obj = new command1;
					commandlist[1]  = obj;
					break;
				
				case 2:
					obj = new command2;
					commandlist[2]  = obj;
					break;
					
				case 3:
					obj = new command3;
					commandlist[3]  = obj;
					break;				
				
				default:
					cout<<"undefined Index"<<endl;
					break;
			}
		}		

		return obj;		
	}
};

flyweightFactory* flyweightFactory::instance = nullptr;

int main()
{
	flyweightFactory* instance = flyweightFactory::getInstance();
	int index = 0;
	
	while(index != 9)
	{
		cout<<"Enter the command Index"<<endl;
		cin>>index;	
		instance->getCommand(index);
	}
	
	return 0;
}
	