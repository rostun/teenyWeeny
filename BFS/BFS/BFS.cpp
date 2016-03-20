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
		vector <treeNode*> getChildren() { 
			return children;
		}
		void addChild(treeNode &inChild){ 
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
	queue <treeNode> nodesToVisit; //queues for nodes
	nodesToVisit.push(root); 
	treeNode currentNode = nodesToVisit.front(); //save front of queue
	root.getChildren()[0];
	nodesToVisit.pop(); //pop off front of queue

	for(int i = 0; i<currentNode.getChildren().size(); i++){
		nodesToVisit.push(currentNode.getChildren());
	}

	return 0;
}
