/*
	Given an array of integers, write a funciton to find the maximum product of any three unique numbers
	alternate solution **without sorting**
		pick out the top three positive numbers and lowest two negative numbers
*/

#include <iostream>
#include <vector>
#include <algorithm> //sort
#include <functional> //greater

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node* Insert(Node *head,int data);

int main()
{
	Node *head;

	head = Insert(NULL, 2);
	cout << head->data << endl;
	Insert(head, 3);
	cout << head->next->data << endl;
	Insert(head, 5);
	cout << head->next->next->data << endl;

	cin.get();
	return 0;
}

Node* Insert(Node *head,int data)
{
	Node *current;
    
	//make a node
	Node* tail = new Node;
    tail->data = data; //have to add it no matter what
    tail->next = NULL;

    //if node is NULL
    if(head == NULL){
        return tail;
    }

	//we have at least one node
	current = head;
	while(current->next != NULL){
		current = current->next;
	}

	//current should be null
	current->next = tail;

    return head;
}