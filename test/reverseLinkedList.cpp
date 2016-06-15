class node{
    private:
        int value;

    public:
        node* next;
        node();
        
};

class linkedList{
    private:
        node* beginning;
    public:
        void insertNode(int where, node* insert);
        void deleteNode(int value);
        
        
        void insert_front(int value); // O(1)
        void insert_back(int value); //O(n)
        int get_front(); //O(1)
        node* get_back(); //O(n)
        void remove_front(); //O(1)
        void remove_back(); //O(n)


        void reverse();    
        
}

void linkedList::reverse()
{
    // beginning points to 1
    node* placeholder;
    node* newBeginning;
    newBeginning = linkedList.get_back();
    
    for(int i = 0; i<linkedList.size(); i++){
        placeholder = linkedList.get_back(); //place holder is
        linkedList.remove_back(); //now 3 is the back
        placeholder->next = linkedList.get_back(); //now 4 is pointing to 3   // <-----
        
        
        
    }
    beginning = newBeginning;
    
    // beginning still points to 1
}


void linkedList::reverse()
{
    std::stack<node*> nodeStack;
    
    node* currentNode = beginning;
   
    while (currentNode != NULL) {
        nodeStack.push(currentNode);
        currentNode = currentNode->next;
    }
    
    beginning = nodeStack.front();
    
    while (!nodeStack.empty()) {
       currentNode = nodeStack.pop();
       currentNode.next = nodeStack.front();
    }
}


void linkedList::reverse() {


        


}








placeholder->next
(*placeholder).next


// 1 2 3 4
// 4 3 2 1