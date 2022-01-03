#include <iostream>
#include <string>
#include <map>
#include <any>

using namespace std;

class caretaker
{
public:
	void setState(void* name, map<string, std::any> value)
	{
		stack[name] = value;
	}

	map<string, any> getState(void* name)
	{
		return (stack[name]);
	}

private:
	map<void*, map <string, any>> stack;
};

//------------------------------------------------

class memento
{
protected:
	caretaker* ct;

public:
	void setCaretaker(caretaker* ct)
	{
		this->ct = ct;
	}

	virtual void saveCurrentState() = 0;
	virtual void retrieveState() = 0;
};

//------------------------------------------------

class playerInfo : public memento
{
public:
	playerInfo(int par_id, string par_name, double par_salary) :id(par_id), name(par_name), salary(par_salary)
	{

	}

	void diaplay()
	{
		cout << "----------------------------------------------" << endl;
		cout << "id = "<< id << endl;
		cout << "name = " << name.c_str() << endl;
		cout << "salary = " << salary << endl;
		cout << "----------------------------------------------" << endl;
	}

	void retrieveState()
	{
		map<string,any> lastState = ct->getState(this);
		id = any_cast<int> (lastState["id"]);
		name = any_cast<string> (lastState["name"]);
		salary = any_cast<double> (lastState["salary"]);
	}

	void saveCurrentState()
	{
		map<string, any> currentState;
		currentState["id"] = id;
		currentState["name"] = name;
		currentState["salary"] = salary;

		ct->setState(this, currentState);
	}

	void updateState(int id, string name, double salary)
	{
		this->id = id;
		this->name = name;
		this->salary = salary;
	}

private:
	int id;
	string name;
	double salary;
};

//--------------------------------------------------------------

int main5()
{
	caretaker ct;
	playerInfo player1(1, "sachin", 1000);
	player1.setCaretaker(&ct);
	playerInfo player2(2, "virat", 2000);
	player2.setCaretaker(&ct);
	playerInfo player3(3, "dhoni", 3000);
	player3.setCaretaker(&ct);

	player1.saveCurrentState();
	player2.saveCurrentState();
	player3.saveCurrentState();

	cout << "ORIGINAL STATE" << endl;
	player1.diaplay();
	player2.diaplay();
	player3.diaplay();

	player1.updateState(1, "Sachin Tendulkar", 10000);
	player2.updateState(2, "Virat Kohli", 8000);
	player3.updateState(3, "Mahendra Singh Dhoni", 11000);

	cout << "STATE MODIFIED" << endl;
	player1.diaplay();
	player2.diaplay();
	player3.diaplay();

	player1.retrieveState();
	player2.retrieveState();
	player3.retrieveState();

	cout << "PREVIOUS STATE RETRIEVED" << endl;
	player1.diaplay();
	player2.diaplay();
	player3.diaplay();

	return (0);
}