/*
	reverse a singly linked list
*/

#include "stdafx.h"
#include <iostream> 
#include <stack>
using namespace std;

class node{
	private:
		int value;
		node* next;
	public:
		node(){
			value = NULL;
			next = NULL;
		}
		node(int value){
			setNode(value);
		}
		void setNode(int value){
			this->value = value;
		}
		int getValue(){
			return value;
		}
		void setNext(node* next){
			this->next = next;
		}
		node* getNext(){
			return next;
		}
};

int _tmain(int argc, _TCHAR* argv[])
{
	//1 2 3 4
	node root(1);
	node second(2);
	node third(3);
	node fourth(4);
	root.setNext(&second);
	second.setNext(&third);
	third.setNext(&fourth);

	//i want to grab from the back, so stack
	stack <node*> reverseContainer;
	node* currentNode = &root;

	while(currentNode != NULL){
		reverseContainer.push(currentNode); //4 is at top at the end of this
		currentNode = currentNode->getNext();
	}
	
	while(!reverseContainer.empty()){ //4 next should be 3, 3 next 2, 2 next 1
		currentNode = reverseContainer.top();
		reverseContainer.pop();
		if(reverseContainer.empty()){
			currentNode->setNext(NULL);
		}
		else{
			currentNode->setNext(reverseContainer.top());
		}
	}

	cout << fourth.getValue() << endl; //4
	cout << fourth.getNext()->getValue() << endl; //4->3
	cout << fourth.getNext()->getNext()->getValue() << endl; //3->2
	cout << fourth.getNext()->getNext()->getNext()->getValue() << endl; //2->1
	cout << fourth.getNext()->getNext()->getNext()->getNext()<< endl; //null

	return 0;
}

/*
	cout << root.getValue() << endl;
	cout << root.getNext()->getValue() << endl;
	node* placeholder = root.getNext();
	cout << (*placeholder).getValue() << endl;
*/