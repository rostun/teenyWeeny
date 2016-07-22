/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/

void inOrder(node *root) {
    if(root->left){
        inOrder(root->left);
    }
    cout << root->data << " ";
    if(root->right){
        inOrder(root->right);
    }
}

//iteratively

void inOrder(node *root) {
    stack <node*> output;
    node* current = root;
    
    int flag = 1; //not done
    
    while(flag == 1){
        if(current != NULL){
            output.push(current);
            current = current->left;
        } else {
            if(!output.empty()){
                current = output.top();
                cout << current->data << " ";
                output.pop();
                current = current->right;
            } else {
                flag = 0;
            }
        }
    }
}