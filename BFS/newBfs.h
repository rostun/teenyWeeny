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
	
	monster Sam(100, 50);
	
	cout << Sam.getHP() << endl;
	
	return 0;
}