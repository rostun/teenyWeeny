#include <stack>

/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    Node *currentA = headA;
    Node *currentB = headB;
    
    stack <int> listA;
    stack <int> listB;
    
    while(currentA){
        listA.push(currentA->data);
        currentA = currentA->next;
    }
    while(currentB){
        listB.push(currentB->data);
        currentB = currentB->next;
    }
    
    int A;
    int B;
    int mergeNode = listA.top();
    
    while(listA.size() > 0 && listB.size() > 0){
        A = listA.top();
        B = listB.top();       
        if(A == B){
            mergeNode = A;
        } else {
            return mergeNode;
        }
        listA.pop();
        listB.pop();
    }
    return mergeNode;
}