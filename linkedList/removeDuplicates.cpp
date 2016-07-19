/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* current = head;
    Node* after = head->next;
    
    while(after != NULL){
        if(current->data == after->data){
            current->next = after->next;
            delete after;
        } else {
            current = current->next;         
        }
        after = current->next;
    }
    return head;
}
