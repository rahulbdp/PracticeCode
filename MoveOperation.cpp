#include <iostream>

using namespace std;

class employee
{
	public:
	employee()
	{
		cout<<"Default Constructor Called"<<endl;
		empid = 0;
		empname = "";
	}
	
	employee(int id, string name)
	{
		cout<<"Parameterised Constructor Called"<<endl;
		empid = id;
		empname = name;
	}
	
	employee(const employee& par)
	{
		cout<<"Copy Constructor Called with lvalue reference"<<endl;
		this->empid = par.empid;
		this->empname = par.empname;
	}
	
	employee(employee&& par)
	{
		cout<<"Copy Constructor Called with rvalue reference"<<endl;
		this->empid = move(par.empid);
		this->empname = move(par.empname);
	}
	
	~employee()
	{
		cout<<"Destructor Called"<<endl;
		empid = 0;
		empname = "";
	}
	
	int empid;
	string empname;
};

void printEmployee(employee temp)
{
	cout<<"ID = "<<temp.empid<<endl;
	cout<<"Name = "<<temp.empname<<endl;
}

int main()
{
	employee emp1(1,"Rahul");
	employee emp2 = emp1;
	employee emp3(emp1);
	employee emp4(move(emp1));
	printEmployee(move(emp4));
	printEmployee(emp4);
	
	return (0);
}