#include <stack>
/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
    Node* current = head;
    stack <int> list;
    while(current != NULL){
        list.push(current->data);
        current = current->next;
    }
    
    int start = 0;
    if(start == positionFromTail){
        return list.top();
    }
    while(start < positionFromTail){
        list.pop();
        start++;
    }
    
    return list.top();
}