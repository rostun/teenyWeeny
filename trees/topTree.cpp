void left(node * root);
void right(node * root);
/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

//can do it in one function by altering tree or maybe using stack

void top_view(node * root)
{  
    left(root->left);
    cout << root->data << " ";
    right(root->right);
}

void left(node * root){
    if(root->left){
        left(root->left);        
    }
    cout << root->data << " ";  
}
void right(node * root){
    cout << root->data << " ";
    if(root->right){
        right(root->right);
    }
}