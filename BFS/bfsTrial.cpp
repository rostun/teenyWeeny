#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
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

    class node{
        private:
            //this is the objects parent
            node *parent;
            //this is the name of the node...this is what we call it
            string identifier;
            //the node might have children nodes under it, these are it
            vector<node*> children;
        public:
            //default and overloaded constructor
            node();
            //root node
            node(string ident){
                setIdentifier(ident);
            }
            //all other nodes
            node(string ident, node* parent){
                setIdentifier(ident);
                setParent(parent);
            }
                                //A
            void setParent(node* parent)
            {
                //B              A        parent becomes A
                this->parent = parent;
                //A                    B
                //A.addChild(B)
                this->parent->addChild(this);
            }

            node* getParent(){
                return parent;
            }

            void setIdentifier(string ident){
                identifier = ident;
            }

            string getIdentifier(){
                return identifier;
            }

            //this method sets the children and takes in the child as a param
            void addChild(node* child){
                children.push_back(child);
            }

            //this node gets the children of the parent...a parent is passed in and the function returns the children
            vector <node*> getChildren(){
                return children;
            }
    };


int main()
{
    //set up the root of the tree
    node* root = new node("A");
    //set other nodes by creating variable object and then calling constructor
    //tree setup - uses overloaded constructor passing it an identifier string and the parent of this node
    node* nodeB = new node("B",root);
    node* nodeC = new node("C",root);
    node* nodeD = new node("D", nodeB);
    node* nodeE = new node("E", nodeB);
    node* nodeF = new node("F", nodeB);
    node* nodeG = new node("G", nodeC);
    node* nodeH = new node("H", nodeC);
    node* nodeI = new node("I", nodeG);

    //keeps track of nodes to visit which are simply the children of the root.  Once we move past root we need to know where to go next
    //nodesToVisit keeps track of this
    queue <node*> nodesToVisit;

    //push the root onto the queue and then print the root
    //then get the children of the root, save them as future roots (nodes to visit and get their children), print out children
    nodesToVisit.push(root);
    cout << root->getIdentifier() << endl;
    while(!nodesToVisit.empty()){
        //sets the currentNode as the NEXT value in the queue, we then remove this node from the queue
        node *currentNode = nodesToVisit.front();
        nodesToVisit.pop();

        //print out all of the children of the currentNode...for loop will run all the way until parent has no more children
        for(int i = 0; i < currentNode->getChildren().size(); i++)
        {
            //we want to print the parents children but we also want to keep track of the children so we can print their children too
            node *child = currentNode->getChildren()[i];
            //add children as future nodes to check
            nodesToVisit.push(child);
            //print the child's Identifier which is the same thing as printing the parents child
            cout << child->getIdentifier();
        }

        //we want to check the nodes siblings so we need to take the next node and compare its parents to the current nodes parents
        node *nextNode = nodesToVisit.front();
        //we only want a new line IF the next node is not NULL AND the currentNodes parent is not the same as the NextNode's
        //parents AND the next node does in fact have children
        if((nextNode != NULL && currentNode->getParent() != nextNode->getParent()) && currentNode->getChildren().size() > 0)
        {
            cout << endl;
        }
/*
        if(nodesToVisit.empty()){
            cout << endl;
        }
*/
    }
    return 0;
}
