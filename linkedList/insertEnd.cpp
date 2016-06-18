/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
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