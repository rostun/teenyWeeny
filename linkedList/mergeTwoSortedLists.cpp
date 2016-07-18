/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
    Node* head;
    Node* current;
    Node* currentA = headA;
    Node* currentB = headB;
    
    
    //if one or both is NULL
    if(headA == NULL){
        return headB;
    }
    if(headB == NULL){
        return headA;
    }
    
    //figure out the head
    if(currentA->data < currentB->data){
        head = headA;
        current = currentA;
        currentA = currentA->next;
    } else {
        head = headB;
        current = currentB;
        currentB = currentB->next;
    }
    
    while(currentA != NULL || currentB != NULL){
        if(currentA == NULL){
            current->next = currentB;
            return head;
        }
        else if(currentB == NULL){
            current->next = currentA;
            return head;
        }
        else {
            if(currentA->data < currentB->data){
                current->next = currentA;
                currentA = currentA->next;
            } else {
                current->next = currentB;
                currentB = currentB->next;
            }
            current = current->next;            
        }
    }
    return head;
}