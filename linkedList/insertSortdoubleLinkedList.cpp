#include <vector>
#include <algorithm>
/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    Node* insertion = new Node;
    insertion->data = data;
    
    //if head is null
    if(head == NULL){ //cout << "head is null" << endl;
        head = insertion;
        head->next = NULL;
        head->prev = NULL;
        return head;
    } 
    
    //insert at beginning
    insertion->next = head;
    insertion->prev = NULL;
    head->prev = insertion;
    head = insertion;
    
    //put list into vector and sort it
    Node *current = head;
    vector <int> list;
    while(current){
        list.push_back(current->data);
        current = current->next;
    }
    sort(list.begin(), list.end());
    
    //put it back into the linked list
    current = head;
    for(int i = 0; i < list.size(); i++){
        current->data = list[i]; //cout << current->data << " ";
        current = current->next;
    } //cout << endl;
    
    return head;
}