#include <iostream>

using namespace std;

class state;
class machine
{
public:
	machine();
	void setCurrentState( state* newState )
	{
		currentState = newState;
	}
	void Open();
	void Close();
private:
	state* currentState;
};

class state
{
public:
	virtual void Open(machine* machineObj)
	{
		cout << "Already Open" << endl;
	}
	virtual void Close(machine* machineObj)
	{
		cout << "Already Close" << endl;
	}
};

class state_Open : public state
{
public:
	static state_Open* getInstance();
	void Close(machine* machineObj);

private:
	state_Open()
	{
		cout << "state_Open Constructor Called" << endl;
	}

	~state_Open()
	{
		cout << "state_Open Destructor Called" << endl;
	}
	//state_Open& operator=(const state_Open&) = delete;
	//state_Open(const state_Open&) = delete;

	static state_Open* instance;
};

class state_Close : public state
{
public:
	static state_Close* getInstance();
	void Open(machine* machineObj);

private:
	state_Close()
	{
		cout << "state_Close Constructor Called" << endl;
	}

	~state_Close()
	{
		cout << "state_Close Destructor Called" << endl;
	}
	//state_Close& operator=(const state_Close&) = delete;
	//state_Close(const state_Close&) = delete;

	static state_Close* instance;
};

machine::machine()
{
	currentState = static_cast<state*>(state_Open::getInstance()); 
	currentState = static_cast<state*>(state_Close::getInstance());
}

state_Open* state_Open::getInstance()
{
	if (instance == nullptr)
	{
		instance = new state_Open;
	}
	return instance;
}

state_Close* state_Close::getInstance()
{
	if (instance == nullptr)
	{
		instance = new state_Close;
	}
	return instance;
}

void state_Open::Close(machine* machineObj)
{
	cout << "Setting State to Close" << endl;
	machineObj->setCurrentState( static_cast<state*>(state_Close::getInstance()) );

}

void state_Close::Open(machine* machineObj)
{
	cout << "Setting State to Open" << endl;
	machineObj->setCurrentState(state_Open::getInstance());
}

state_Open* state_Open::instance = nullptr;
state_Close* state_Close::instance = nullptr;

void machine::Open()
{
	currentState->Open(this);
}

void machine::Close()
{
	currentState->Close(this);
}

int main2()
{
	machine* stateMachine = new machine;
	bool input = false;

	while (1)
	{
		cout << "Input (0/1) = ";
		cin >> input;
		if (input)
			stateMachine->Open();
		else
			stateMachine->Close();
	}
}