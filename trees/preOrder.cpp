/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/

//recursively
void preOrder(node *root) {
    cout << root->data << " ";
    
    if(root->left != NULL){
        preOrder(root->left);
    }
    
    if(root->right != NULL){
        preOrder(root->right);
    }
}

//To solve iteratively instead of recursively, use a stack - Pop current node off, then right child goes in first, 
then left, and repeat with popping off the most recently added node. When the stack is empty, process ends.

void preOrder(node *root) {
    stack <node*> branch;
    branch.push(root);
    
    node* current = root;
    
    while(!branch.empty()){
        current = branch.top();
        cout << branch.top()->data << " ";
        branch.pop();
        if(current->right != NULL){
            branch.push(current->right);
        }
        if(current->left != NULL){
            branch.push(current->left);
        }
    }
}