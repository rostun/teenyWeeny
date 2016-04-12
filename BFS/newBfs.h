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

#include <iostream>
using namespace std;

class node{
	private:
		string character; //a node
		vector <node> children; //its associated children 
									//you want a vector of nodes
	public:
		node(string character){
			this->character = character;
		}
		string getCharacter(){
			return character;
		}
		vector <node> getChildren(){
			return children;
		}
		//keep track of either we don't remember or we don't know
		void addChild(node child){
			children.push_back(child);
		}
};

int main(){
	node root("A");
	node nodeB("B");
	node nodeC("C"); root.addChild(nodeB); root.addChild(nodeC);
	node nodeD("D");
	node nodeE("E");
	node nodeF("F"); nodeB.addChild(nodeD); nodeB.addChild(nodeE); nodeB.addChild(nodeF);
	node nodeG("G");
	node nodeH("H"); nodeC.addChild(nodeG); nodeC.addChild(nodeH);
	node nodeI("I"); nodeG.addChild(nodeI);
	
	//make another container 
	
	queue <node> nodesToVisit; 
	//First in first out
		//keep pushing back (and it'll push from the end)
		//can only deal with the beginning
		//[2] 3 4 5 6 7 <-
	
	//[A] B C D E F G H I
	
	nodesToVisit.front(); //get front of queue
	nodesToVisit.pop(); //remove front of queue 
	
	//some kind of initial push (probably going to be the root)
	//make your counters
	//etc 
	//BFS
	while(queue isn't empty){
		//keep a counter of some sort to keep track of the levels 
		//cout A
		//pop A
		//endl
		//cout A's children
		//pop B
		//cout B's children
		//endl;		
	}

	return 0;
}















