

#include "pch.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

//Creating a new node and returning a pointer that points to it
struct Node* GetNewNode(int x) {
	//Allocating Dynamic Memory on the Heap
	struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
	NewNode->data = x;
	NewNode->next = NULL;
	NewNode->prev = NULL;
	return NewNode;
}

//Global pointer initialized - head of node 
struct Node* head;
struct Node* tail;

//Function Prototypes
void insertAtHead(int x);
void insertAtTail(int x);
void printList();
void reversePrintList();

int main()
{
	head = NULL;
	insertAtTail(2); printList(); reversePrintList();
	insertAtTail(4); printList(); reversePrintList();
	insertAtHead(6); printList(); reversePrintList();
	insertAtTail(8); printList(); reversePrintList();
}

//This function inserts the int value to the beginning of the list
void insertAtHead(int x)
{
	struct Node* NewNode = GetNewNode(x);

	//Checking to see if the node is populated
	if (head == NULL) {
		head = NewNode;
		return;
	}

	head->prev = NewNode;
	NewNode->next = head;
	head = NewNode;
}

void insertAtTail(int x) 
{
	struct Node* NewNode = GetNewNode(x);

	//Checking to sees if node is populated
	if (tail == NULL) {
		tail = NewNode;
		head = NewNode;
		return;
	}
	//Setting our tail ptr to the end of the list
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = NewNode;
	NewNode->prev = tail;
	tail = NewNode;
}


//PrintList() uses forward traversal order to print our DLL
void printList()
{
	struct Node* tempPtr = head;

	printf("Forward: ");
	while (tempPtr != NULL) {
		printf("%d ", tempPtr->data);
		tempPtr = tempPtr->next;
	}
	printf("\n");
}


void reversePrintList()
{
	struct Node* tempPtr = head;
	if (tempPtr == NULL) {
		return;
	}
	
	//Traversing to the end of the list
	while (tempPtr->next != NULL) {
		tempPtr = tempPtr->next;
	}

	printf("Reverse: ");

	while (tempPtr != NULL) {
		printf("%d ", tempPtr->data);
		tempPtr = tempPtr->prev;
	}
	printf("\n");
}