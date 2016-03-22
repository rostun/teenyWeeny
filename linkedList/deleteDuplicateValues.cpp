/*
	Cracking the Code Interview
	2.1 Write code to remove duplicated from an unsorted linked list
*/

#include "stdafx.h"
#include <string>
#include <iostream> 
#include <map>
using namespace std;

struct node{
	int value;
	node* next;
	node(int value){
		this->value = value;
		next = NULL;
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
		
	//set counter, make hash table
	node* currentNode;
	currentNode = &one;
	map<int, int> valueChart;

	//one while loop puts things into map
	while(currentNode != NULL){
		valueChart[currentNode->value] = 0; //set them all equal to 0
		currentNode = currentNode->next;
	}
	//check linked list
	currentNode = &one;
	while(currentNode != NULL){
		cout <<currentNode->value << endl;
		currentNode = currentNode->next;
	}
	//check map
	for(auto it = valueChart.begin(); it !=valueChart.end(); it++){
		cout << it->first << " " << it->second << endl;
	}
	//delete duplicate nodes
	node* prevNode = NULL;
	currentNode = &one;
	while(currentNode != NULL){
		if(valueChart[currentNode->value] == 1){
			prevNode->next = currentNode->next; //delete currentNode
		}
		else{ //visited
			valueChart[currentNode->value] = 1; 
		}
		prevNode = currentNode;
		currentNode = currentNode->next;
	}
	//check linked list
	currentNode = &one;
	while(currentNode != NULL){
		cout <<currentNode->value << endl;
		currentNode = currentNode->next;
	}
	
	return 0;
}