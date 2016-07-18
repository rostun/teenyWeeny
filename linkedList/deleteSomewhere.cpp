/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
  // Complete this method
    if(head == NULL){
        return NULL;
    }
    
    Node* current = head;
    Node* after = current->next;
    int start = 0;
    
    if(start == position){
        current = head->next;
        delete head;
        return current; 
    }
    
    for(int i = 0; i <= position; i++){
        start++;
        if(start == position){ //need to delete after
            current->next = after->next;
            delete after;
            return head;
        } else {
            current = after;
            after = current->next;
        }
        
    }
    //position dne
    return head;   
}