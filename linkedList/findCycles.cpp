/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

//could use hash map
//need to alter data structure with visited or not visited
//make all nodes point to head as they are visited, if a node is pointed to a node pointed to head, there's a cycle
/*
    Floyd’s Cycle-Finding Algorithm (This is the fastest method)
    Traverse linked list using two pointers.  Move one pointer by one and other pointer by two.  
    If these pointers meet at some  node then there is a loop.  
    If pointers do not meet then linked list doesn’t have loop. (second pointer wil get stuck on the loop)
*/
bool has_cycle(Node* head) {
    if(head == NULL){
        return false;
    }
    
    //check if there's a cycle
    Node* tortoise = head;
    Node* hare = head;
    
    //while they exist
    while(tortoise && hare){
        tortoise = tortoise->next;
        hare = hare->next->next;
        if(tortoise == hare){
            return true;
        }
    }
    //if they don't exist
    return false;    
}