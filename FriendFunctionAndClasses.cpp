// What is the actual use of friend function and friend class in C++
// Example: In case of test function that wants to print the values of private/public/protected variables
// Imp Point: In case of Inheritance the friend function will be able to access the member variabls of only the immediate cllass where its declared as friend andnot the other classes in inheritance hierarchy.

#include <iostream>

using namespace std;

class employee;
class admin;

void test(employee & emp);

class employee
{
	string empName;
	string empId;
	
	void modifyDetails(const string& name, const string& id)
	{
		empName = name;
		empId = id;
	}
	
	void viewEmpDetails()
	{
		cout<<"Name: "<<empName<<endl;
		cout<<"Emp ID: "<<empId<<endl;
	}

public:
	employee(const string& name, const string& id):empName(name),empId(id)
	{
	}
	
	friend class admin;
	friend void test(employee & emp);
};

class admin
{
	public:
	void modifyEmpDetails(employee & emp, const string& name, const string& id)
	{
		emp.modifyDetails(name,id);
	}
};

void test(employee & emp)
{
	emp.viewEmpDetails();
}

int main()
{
	employee rp("rahul","1397");
	
	test(rp);
	
	//rp.modifyDetails("Rahul","1397");  //Compilation Error
	
	admin master;
	master.modifyEmpDetails(rp, "Rahul Pandey","1397");
	test(rp);

	return 0;
}