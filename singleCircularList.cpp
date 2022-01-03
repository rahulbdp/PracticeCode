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
	node* newNode = new node;
	newNode->value = value;
	
	if (head != nullptr)
	{
		if (head->next == nullptr)
		{
			newNode->next = head;
			head->next = newNode;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
		}
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
			cout<<"Entry "<<index<<" = "<<head->value<<" Node Pointer = "<<head<<" Next = "<<head->next<<endl;
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