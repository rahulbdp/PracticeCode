// What is auto keyword in c++11

#include <iostream>

using namespace std;

class base{};

int main()
{
	auto x = 5;
	auto y = 02.06;
	auto z = base();
	auto k = new base;
	
	cout<<"x Type: "<<typeid(x).name()<<endl;
	cout<<"y Type: "<<typeid(y).name()<<endl;
	cout<<"z Type: "<<typeid(z).name()<<endl;
	cout<<"k Type: "<<typeid(k).name()<<endl;
	
	return 0;
}