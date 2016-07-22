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
void postOrder(node *root) {
    if(root->left){
        postOrder(root->left);
    }
    if(root->right){
        postOrder(root->right);
    }
    cout << root->data << " ";
}

//iteratively (using two stacks)
//can use a queue for less storage

void postOrder(node *root) {
    node* current;
    
    stack <node*> container;
    stack <node*> output;
    
    container.push(root);
    
    while(!container.empty()){
        current = container.top();
        output.push(current);
        container.pop();
        if(current->left){
            container.push(current->left);
        }
        if(current->right){
            container.push(current->right);
        }
    }
    while(!output.empty()){
        cout << output.top()->data << " ";
        output.pop();
   
