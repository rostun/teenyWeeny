/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
    Node* new_node = new Node;
    new_node->data = data; //assign data
    new_node->next = NULL;
    
    //if node is NULL
    if(head == NULL){
        return new_node;
    }
    
    //else let's insert the node
    Node* current = head; //position 0
    Node* after = head->next; //position 1
    int start = 0;
    
    //if want to insert in beginning of linked list
    if(start == position){
        new_node->next = head;
        return new_node;
    }
    
    //somewhere in the middle of the linked list
    for(int i = 0; i <= position; i++){
        start++;
        if(start == position){ //we've arrived at position
            current->next = new_node;
            new_node->next = after;
            return head;
        }
        current = after;
        after = current->next;
    }
    //if position is not valid
    return head;
}