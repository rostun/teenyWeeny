/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/

//duplicates are supposed to be excluded
node * insert(node * root, int value)
{
    node* current = root;
    node* last = root;
    int flag = 0; //0 for right, 1 for left
 
    node* insert = new node;
    insert->data = value;
    
    if(root == NULL){
        return insert;
    }
    
    while(current){
        last = current;
        if(current->data > value){
            current = current->left;
            flag = 1; 
        } else {
            current = current->right;
            flag = 0; 
        }
    }
    
    //last should be the parent node

    if(flag == 0){
        last->right = insert;
    } else {
        last->left = insert;
    }
    
    return root;
}