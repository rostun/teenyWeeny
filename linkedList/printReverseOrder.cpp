#include <stack>
/*
  Print elements of a linked list in reverse order as standard output
  head pointer could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void ReversePrint(Node *head)
{
    Node* current = head;
    stack <Node*> list;
    while(current != NULL){
        list.push(current);
        current = current->next;
    }
    
    int size = list.size();
    while(size > 0){
        current = list.top();
        cout << current->data << endl;
        list.pop();
        size--;
    }
}