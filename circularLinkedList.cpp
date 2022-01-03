#include <iostream>

using namespace std;

class node
{
	public:
	int value = 0;
	node* next = nullptr;
	node* previous = nullptr;
};

node* addNode(node* head, int value)
{
	node* newNode = new node;
	newNode->value = value;
	
	if (head != nullptr)
	{
		newNode->next = head;
		if (head->previous != nullptr)
		{
			node* temp = head->previous;
			head->previous = newNode;
			head = temp;
			head->next = newNode;
		}
		else
		{
			head->previous = newNode;
			head->next = newNode;
		}		
		newNode->previous = head;
	}
	else
	{
		head = newNode;
	}
	
	return head;
}

void printList(node* head)
{
	int index = 1;
	if (head != nullptr)
	{
		node* headPtr = head;
		do
		{
			cout<<"Entry "<<index<<" = "<<head->value<<" Node Pointer = "<<head<<" Previous = "<<head->previous<< " Next = "<<head->next<<endl;
			head = head->next;
			index++;
		}
		while((head != nullptr) && (head != headPtr));
	}
}

int main()
{
	node* HEAD = addNode(nullptr, 10);
	printList(HEAD);
	addNode(HEAD, 20);
	printList(HEAD);
	addNode(HEAD, 30);
	printList(HEAD);
	addNode(HEAD, 40);
	
	printList(HEAD);
	
	return (0);
}