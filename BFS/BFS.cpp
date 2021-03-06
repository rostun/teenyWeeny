// BFS.cpp : Defines the entry point for the console application.
/*
	Given a tree (generic, not binary, no cycles):
		A
	   /  \
	  B    C
	/ | \  |\
	D E  F G H
		   |
		   I

	Print the nodes in the following manner (each depth on its own line, followed by a line break):
	A
	BC
	DEFGH
	I
	
	http://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm
*/

#include "stdafx.h"
#include <iostream> 
#include <vector>
#include <string>
#include <queue>
using namespace std;

class treeNode{
	private:
		string parent; //the parent
		vector <treeNode*> children; //the parent's children
	public:
		treeNode();
		treeNode(string inParent){ 
			setParentNode(inParent);
		}
		void setParentNode(string inParent){ 
			parent = inParent;
		}
		string getValue(){ 
			return parent;
		}
		vector <treeNode*> getChildren(){ 
			return children;
		}
		void addChild(treeNode &inChild){ //take in address
			children.push_back(&inChild);
		}
};

int _tmain(int argc, _TCHAR* argv[])
{
	treeNode root("A");
	treeNode nodeB("B");
	treeNode nodeC("C"); root.addChild(nodeB); root.addChild(nodeC);
	treeNode nodeD("D");
	treeNode nodeE("E");
	treeNode nodeF("F"); nodeB.addChild(nodeD); nodeB.addChild(nodeE); nodeB.addChild(nodeF);
	treeNode nodeG("G");
	treeNode nodeH("H"); nodeC.addChild(nodeG); nodeC.addChild(nodeH);
	treeNode nodeI("I"); nodeG.addChild(nodeI);

	//BFS: print out level by level
	queue <treeNode*> nodesToVisit; //queues for nodes
	//line first in first out
	
	nodesToVisit.push(&root); //put root into queue
	cout << root.getValue() << endl; //output that root
	int counter = root.getChildren().size(); //set counter to roots children size
	int nextCounter = 0;
	while(!nodesToVisit.empty()){
		treeNode *currentNode = nodesToVisit.front(); //pointer to current node
		nodesToVisit.pop(); //pop off front of queue
		for(unsigned int i = 0; i<currentNode->getChildren().size(); i++){
			nodesToVisit.push(currentNode->getChildren()[i]);
				cout << currentNode->getChildren()[i]->getValue();	
				nextCounter = nextCounter + currentNode->getChildren()[i]->getChildren().size(); //B has 3 children and C has 2
				counter--;
				if(counter == 0 && nextCounter != 0){
					cout << endl;
					counter = nextCounter;
					nextCounter = 0;
				}
		}
		if(nodesToVisit.empty()){ //cout one last time
			cout << endl;
		}
	}
	return 0;
}
