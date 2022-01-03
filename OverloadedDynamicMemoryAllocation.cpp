#include <iostream>
#include <string>

using namespace std;

void* operator new (size_t n)
{
	cout<<"Allocation Requested: "<<n<<endl;
	return malloc(n);
}

void operator delete (void* ptr)
{
	//cout<<"Dealloction Requested: "<<ptr<<endl;
	free(ptr);
}

int main()
{
	string str = "Hello World: Trying Dynamic Memory Allocation";
	
	string* strPtr = new string;
	
	cout<<"Size of char"<<sizeof(char)<<endl;
	cout<<"Size of int"<<sizeof(int)<<endl;
	cout<<"Size of Small String in Gcc:"<<sizeof(string)<<endl;
	
	//max length of string that could be stored in a small string
	for (size_t i = 0; i < 24; ++i) {
	std::cout << i << ": " << std::string(i, '=') << std::endl;}
	
	//Copy on Write
	std::string a(50, 'c');
    std::string b = a;
  
    *const_cast<char*>(a.c_str()) = 'A';
    std::cout << "a: " << a << "\nb: " << b << std::endl;
	
	return 0;
}