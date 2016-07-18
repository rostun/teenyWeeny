#include <stack>
/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int CompareLists(Node *headA, Node* headB)
{
    Node* current1 = headA;
    Node* current2 = headB;
    stack <int> values1;
    stack <int> values2;
    
    while(current1 != NULL){
        values1.push(current1->data);
        current1 = current1->next;
    }
    while(current2 != NULL){
        values2.push(current2->data);
        current2 = current2->next;
    }
    if(values1.size() != values2.size()){
        return 0;
    }
    
    //if they are equal in size
    int size = values1.size();
    while(size > 0){
        if(values1.top() != values2.top()){
            return 0;
        } else {
            values1.pop();
            values2.pop();
            size--;
        }
    }
    return 1;
}