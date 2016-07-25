#include <queue>
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

void LevelOrder(node * root)
{
    node* current = root;
    queue <node*> line;
    int level = 1;
    int levelChildren = 0;   
    
    line.push(current);
    
    while(!line.empty()){
        //pop off top of queue and get next level
        while(level > 0){
            current = line.front();
            cout << line.front()->data << " ";
            line.pop(); //pop off that guy
            if(current->left){
                line.push(current->left);
                levelChildren++;
            }        
            if(current->right){
                line.push(current->right);
                levelChildren++;
            }
            level--;
        }
        level = levelChildren; //switch off
        levelChildren = 0; //reset next level
    }
}