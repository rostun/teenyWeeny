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
		node* prev;
	public:
		node(){
			value = NULL;
			next = NULL;
			prev = NULL;
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
		void setPrev(node* prev){
			this->prev = prev;
		}
		node* getNext(){
			return next;
		}
		node* getPrev(){
			return prev;
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
	second.setNext(&third); second.setPrev(&root);
	third.setNext(&fourth); third.setPrev(&second);
	fourth.setPrev(&third);

	cout << root.getValue() << endl;
	cout << root.getNext()->getValue() << endl;
	cout << root.getNext()->getPrev()->getValue() << endl;


	stack <node*> reverseContainer;
	
	node *currentNode = &root;
	node *saveNext;

	while(currentNode != NULL){
		reverseContainer.push(currentNode);
		currentNode = currentNode->getNext();
	}

	while(!reverseContainer.empty()){
		//right now prev = top(), next = prev
		currentNode = reverseContainer.top(); //3
		reverseContainer.pop();
		//save next
		saveNext = currentNode->getNext(); //save right node
		if(reverseContainer.size() == 0){
			currentNode->setNext(NULL);
		}else{
			currentNode->setNext(reverseContainer.top()); //2
		}
		currentNode->setPrev(saveNext);
	}
	cout << fourth.getValue() << endl;
	cout << fourth.getNext()->getValue() << endl;
	cout << fourth.getNext()->getPrev()->getValue() << endl;

	return 0;
}