#include <iostream>

using namespace std;

class node
{
	public:
	int value = 0;
	node* next = nullptr;
};

node* addNode(node* head, int value)
{
	node* headPtr = head;
	node* newNode = new node;
	newNode->value = value;
	
	if (headPtr != nullptr)
	{
		while(head->next != nullptr)
		{
			head = head->next;
		}
		head->next = newNode;
	}
	else
	{
		headPtr = newNode;
	}
	
	return headPtr;
}

void printList(node* head)
{
	int index = 1;
	while(head != nullptr)
	{
		cout<<"Entry "<<index<<" = "<<head->value<<" "<<head<<" "<<head->next<<endl;
		head = head->next;
		index++;
	}
}

int main()
{
	node* HEAD = addNode(nullptr, 10);
	addNode(HEAD, 20);
	addNode(HEAD, 30);
	
	printList(HEAD);
	
	return (0);
}