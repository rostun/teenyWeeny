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

class treeNode{ //object that is a tree

    private:
        //every node has children
        vector <char> children; //B C
    public:
        treeNode();
        void addChildren(char anotherNode);
        void getChildren(treeNode startingNode); //take in a node from the left child
        void printTreeLevel(){//print tree by level
            int start = 0;
            //starting from 0
            //go through every level and print out the children
            printChildren();
        }
        void printChildren(vector <char> child){
            for(int i = 0; i<child.size(); i++){
                cout << child[i]; //print out
            }
            cout << endl;
        }
};

int main(){
    //treeNode tree;
    
}

BFS
DFS

using namespace std;


class TreeNode {
    private:
        string value;
        vector<TreeNode*> children;

    public:
        string getValue();
        vector<TreeNode*> getChildren();
}


////// here ///////
class TreeNode {
    public:
        string value;
        vector<TreeNode*> children;
};

queue:
vod push(TreeNode*) // adds an element ot the end of the queue
TreeNode* pop() // Removes an element from the beginning of the queue


printLevels(TreeNode& root) {

    std::queue<TreeNode&> nodesToVisit;
    vector <string> level;
    nodesToVisit.push(root); //A
    int counter = 1;
    while(!nodesToVisit.empty()) {
    
        if(counter == 1)
        {
            //print out everything
            counter = 0;
        }
        TreeNode& node = nodesToVisit.pop(); // removing a node
        //counter represents how many times i need to go through the for loop next
        // do stuff with node  
        counter--;
        for (int i = 0; i < node.children.size(); ++i) { // adding more nodes
            counter++; //counter is 2
            nodesToVisit.push(node.children[i]);
            level.push_back(node.children[i].getValue());
        }   //counter will be number of children
    }
}

queue: A
queue: <nothing>
queue: B C
queue: C D E F
queue: D E F G H
queue: E F G H
queue: H I
queue: <empty!>

vector<type> // vector[0]
map<type1, type2> map<int, string>
queue<type> // first in, first out.  add 1, 2 ,3 pop() => 1, pop() =>  2
stack<type> // first in, last out. add 1, 2, 3, pop() => 3, pop() => 2, pop() => 1
list<type> 
set<type> // use when don't care about order of things (logn insert/lookup)
unordererd_set<type> // constant insert / lookup
priority_queue<type>  // logn insert, constant pop() 

http://www.cplusplus.com/reference/queue/queue/












