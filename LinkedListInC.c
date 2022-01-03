/* Linked List in C */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int value;
	struct node* next;
} node;

/* ADDITION OF NEW NODE */
/* push: adds new node at the start of the linked list */
/* insertAfter: adds new node at the middle of the linked list */
/* append: adds new node at the end of the linked list */

void push( struct node** head, int val )
{
	/* Pseudocode:
	1. allocate a new node
	2. assign value to the new node 
	3. assign the current head node address into the new node's next pointer
	4. modify the current head with the new node's address
	*/
	
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->value = val;
	newNode->next = (*head);
	*head = newNode;
}

void insertAfter(struct node** prevNode, int val)
{
	/* Pseudocode:
	1. allocate a new node.
	2. assign the new value in the new node
	3. the prevNode next node address to be copied to the next node address of new node
	4. the new node address to be copied to the next node address of prevNode
	*/
	
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->value = val;
	newNode->next = (*prevNode)->next;
	(*prevNode)->next = newNode;
}

void append(struct node** head, int val)
{
	/* Pseudocode:
	1. allocate a new node
	2. assign the value in the new node
	3. if head is pointing to null then assign new node address to head.
	4. else iterate the linked list head pointer till next is null.
	5. assign the new node address to the last.
	*/
	
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	struct node* last = *head;
	
	newNode->value = val;
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = newNode;
	}
}

void deleteNode(struct node** head, int val)
{
	/* Pseudocode:
	1. if head is not NULL.
	2. store head pointer and create a prev node pointer
	3. loop till node with val is found. Update prev node accordingly
	4. if node with val is found then prev node next pointer = found node next pointer
	5. free the found node pointer.
	*/
	
	if (*head != NULL)
	{
		struct node* curNode = *head;
		struct node* prevNode = NULL;
		
		while ((curNode != NULL) &&
				 (curNode->value  != val))
		{
			prevNode = curNode;
			curNode = curNode->next;
		}
		
		if (prevNode == NULL)
		{
			*head = (*head)->next;
		}
		else
		{
			if (curNode != NULL)
				prevNode->next = curNode->next;
			else
				return;
		}
		free(curNode);
	}
}

bool search(struct node* head, int val)
{
	/* Pseudocode:
	1. check if head is not null.
	2. store head
	3. iterate through list to find val.
	4. if val is found then return true
	*/
	
	if (head != NULL)
	{
		struct node* curNode = head;
		
		while ((curNode != NULL) &&
				 (curNode->value  != val))
		{
			curNode = curNode->next;
		}
		
		if (curNode != NULL)
			return true;
		else
			return false;
	}
}

bool recursiveSearch(struct node* head, int val)
{
	if  (head != NULL) 
	{
		if (head->value != val)
			return recursiveSearch(head->next,val);
		else
			return true;
	}
	else
	{
		return false;
	}
}

void printList(struct node* head)
{
	while (head != NULL)
	{
		printf("%d\t",head->value);
		head = head->next;
	}
}

int main()
{
	struct node* linkedListHead = NULL;
	
	push(&(linkedListHead),5);
	push(&(linkedListHead),9);
	push(&(linkedListHead),1);
	push(&(linkedListHead),4);
	
	insertAfter(&(linkedListHead),20);
	insertAfter(&(linkedListHead),30);
	
	append(&(linkedListHead),-2);
	append(&(linkedListHead),-6);
	
	printf("Is 9 present: %d\n",search(linkedListHead,9));
	printf("Is 7 present: %d\n",search(linkedListHead,7));
	printf("Is 1 present: %d\n",recursiveSearch(linkedListHead,1));
	printf("Is 15 present: %d\n",recursiveSearch(linkedListHead,15));
	
	deleteNode(&(linkedListHead),-2);
	deleteNode(&(linkedListHead),4);
	deleteNode(&(linkedListHead),8);
	
	printList(linkedListHead);
	
	return 0;
}