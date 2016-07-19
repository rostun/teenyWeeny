/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/

//can also swap data
Node* Reverse(Node* head)
{
    if(head == NULL){
        return head;
    }
    
    Node* current = head;
    Node* save = head->prev;
    
    //switch prev and after's
    while(current){
        current->prev = current->next;
        current->next = save;
   
        save = current;
        current = current->prev;
    }
    head = save;
    return head;
}