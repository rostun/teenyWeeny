/*
	Swap Nodes 
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct node{
    int data;
    int level;
    node* left;
    node* right;
};

node* insertIntoTree(node* parent, int a, int b);
void printInOrder(node* root);

int main() {
    node* root = new node;
    root->data = 1;
    root->level = 1;
    root->right = NULL;
    root->left = NULL;
    int height = 1;
    
    int n, a, b;
    cin >> n;
    
    int currentLevel = 1;
    int nextLevel = 0;
    node* currentNode = root;
    
    int i = 0;
    queue <node*> line;
    line.push(root);
    
    while(i < n){
        while(currentLevel > 0){
            currentNode = line.front();
            //take in user input and insert at currentNode
            cin >> a >> b;
            insertIntoTree(currentNode, a, b);
            if(a != -1){
                nextLevel++;
                line.push(currentNode->left);   
            }
            if(b != -1){
                nextLevel++;
                line.push(currentNode->right);
            }
            line.pop();
            currentLevel--;
        }
        currentLevel = nextLevel;
        nextLevel = 0;
        i++;
    }
    int T; //number of swaps we need
    vector <int> kValues;
    cin >> T;
    int k;
    
    for(int i = 0; i < T; i++){
        cin >> k;
        //cout << "pushing back: " << k << endl;
        kValues.push_back(k);
    }
    
    currentLevel = 1;
    nextLevel = 0;
    line.push(root);
    
    node* placeHolder;
    
    for(int i = 0; i < kValues.size(); i++){
        //swap children at level k
        while(!line.empty()){
            while(currentLevel > 0){
                currentNode = line.front();
                //if the level is the correct one, we need to switch it
                //cout << "line.front()->data: " << line.front()->data << endl;
                //cout << "line.front()->level: " << line.front()->level << endl;
                if(line.front()->level%kValues[i] == 0){
                    placeHolder = line.front()->right;
                    line.front()->right = line.front()->left;
                    line.front()->left = placeHolder;
                }
                if(currentNode->left){
                    nextLevel++;
                    line.push(currentNode->left);   
                }
                if(currentNode->right){
                    nextLevel++;
                    line.push(currentNode->right);
                }                    
                line.pop();
                currentLevel--;
            }
            currentLevel = nextLevel;
            nextLevel = 0;
        } 
        printInOrder(root); cout << endl;
        currentLevel = 1;
        line.push(root);
    }

    return 0;
}

node* insertIntoTree(node* parent, int a, int b){
    
    if(a == -1){
        parent->left = NULL;
    } else {
        node* l = new node;
        l->data = a;
        l->level = parent->level + 1;
        parent->left = l;
    }
    
    if(b == -1){
        parent->right = NULL;
    } else {
        node* r = new node;
        r->data = b; 
        r->level = parent->level + 1;
        parent->right = r;
    }
    return parent;
}

void printInOrder(node* root){
    if(root->left){
        printInOrder(root->left);       
    }
    cout << root->data << " ";
    if(root->right){
        printInOrder(root->right);        
    }
}