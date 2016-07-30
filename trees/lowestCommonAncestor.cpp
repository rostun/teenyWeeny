/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/


node * lca(node * root, int v1,int v2)
{
    node* pathV1 = root;
    node* pathV2 = root;

    while(pathV1 == pathV2){
        //both either need to go right or left
        if(v1 > pathV1->data && v2 > pathV2->data){
            pathV1 = pathV1->right;
            pathV2 = pathV2->right;
        }
        else if(v1 < pathV1->data && v2 < pathV2->data){
            pathV1 = pathV1->left;
            pathV2 = pathV2->left;            
        }
        //one of them is equal, which means the other is a child
        else if(v1 == pathV1->data || v2 == pathV2->data){
            return pathV1;
        }
        //if they break apart
        else{
            return pathV1;
        }
    }
    
    //they broke apart
    return pathV1;
}
