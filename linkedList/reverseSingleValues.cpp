#include <stack>
/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
    Node* current = head;
    if(head == NULL){
        return head;
    }
    stack <int> list;
    while(current != NULL){
        list.push(current->data);
        current = current->next;
    }
    
    current = head;
    while(current != NULL){
        current->data = list.top();
        list.pop();
        current = current->next;
    }
    return head;
}