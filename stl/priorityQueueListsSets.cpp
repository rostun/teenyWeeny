/*
	stl containers: Priority queue, lists, sets
*/

#include "stdafx.h"
#include <string>
#include <iostream> 
#include <queue>
#include <list>
#include <set>
using namespace std;

struct node{
	int value;
	node* next;
	node(int value){
		this->value = value;
		next = NULL;
	}
};

struct sortOrder{
	bool operator()(const node* node1, const  node* node2){ //functer
		int num = node1->value;
		int num1 = node2->value;
		return num<num1; //if first<second, will return true
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	//make nodes
	node one(1);
	node two(2);
	node three(3);
	node four(4);
	node two1(2);

	//1 2 3 4 2
	one.next = &two;
	two.next = &three;
	three.next = &four;
	four.next = &two1;

	priority_queue <node*> container;
	container.push(&two);
	container.push(&one);

	cout << "priority queue: 2 1" << endl;
	while(!container.empty()){
		cout << container.top()->value << endl;
		container.pop(); 
	}

	list <node*> listContainer;
	listContainer.push_back(&two);
	listContainer.push_back(&one);
	listContainer.push_front(&four);

	cout << "list: 2 1 4" << endl;
	for(auto i = listContainer.begin(); i!= listContainer.end(); i++){
		cout << (*i)->value << endl;
	}

	set<node*, sortOrder> setContainer;
	setContainer.insert(&one);
	setContainer.insert(&four);
	setContainer.insert(&two);
	
	cout << "set: 1 4 2" <<endl;
	for(auto i = setContainer.begin(); i!= setContainer.end(); i++){
		cout << (*i)->value << endl;
	}
	return 0;
}