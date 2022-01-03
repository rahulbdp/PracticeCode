#include <iostream>
#include <memory>

using namespace std;

class node
{
	int data;
};

void* operator new (size_t size)
{
	cout<<"Allocation requested: "<<size<<endl;
	return malloc(size);
}

void operator delete (void* ptr)
{
	cout<<"Deallocation requested: "<<ptr<<endl;
	free(ptr);
}

void autoPointer()
{
	cout<<"Begin auto Pointer"<<endl;
	
	//auto_ptr<node> aptr = new node;
	
}

void uniquePointer()
{
	cout<<"Begin unique Pointer"<<endl;
	unique_ptr<node> aptr(new node);
	
}

void sharedPointer()
{
	cout<<"Begin shared Pointer"<<endl;
	shared_ptr<node> aptr(new node);
}

void weakPointer()
{
	cout<<"Begin weak Pointer"<<endl;
	//weak_ptr<node> aptr(new node);
}

int main()
{
	autoPointer();
	uniquePointer();
	sharedPointer();
	weakPointer();
	return 0;
}