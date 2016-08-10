/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/

void decode_huff(node * root,string s)
{
    vector <char> finalString;
    node* current = root;
    
    for(int i = 0; i < s.length(); i++){
        if(current->data == '\0'){
            if(s[i] == '0'){ //go left
                current = current->left;
            } else { //go right
                current = current->right;
            }
        }
        if(current->data != '\0'){
            finalString.push_back(current->data);
            current = root;
        }
    }
    for(int i = 0; i < finalString.size(); i++){
        cout << finalString[i];
    }
}