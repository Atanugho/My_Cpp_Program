#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int value;
    Node* left;
    Node* right;

    Node(int v){
        value = v; 
        left = right =  NULL;
    }
};

class BST{
    public:
        Node* root;
    BST(){
        root = NULL;
    }    
};
Node* insertBSTRecursive(Node* root,int val){
    if(root==NULL){
        Node* newNode = new Node(val);
        return newNode;
    }
    if(root->value>val){
        root->left = insertBSTRecursive(root->left,val);
    }
    else if(root->value<val){
        root->right = insertBSTRecursive(root->right,val);

    }
    return root;
}

Node* lowestCommonAncestor(Node* root,Node* node1,Node* node2){

    if(root == NULL){
        return NULL;
    }

    if(root->value > node1->value && root->value > node2->value){
        return lowestCommonAncestor(root->left,node1,node2);
    }
    if(root->value < node1->value && root->value < node2->value){
        return lowestCommonAncestor(root->right,node1,node2);
    }
    return root;

}



int main(){

BST bst;

bst.root = insertBSTRecursive(bst.root,3);
insertBSTRecursive(bst.root,1);
insertBSTRecursive(bst.root,4);
insertBSTRecursive(bst.root,6);
insertBSTRecursive(bst.root,2);


Node* node1 = new Node(2);
Node* node2 = new Node(6);

Node *temp = lowestCommonAncestor(bst.root,node1,node2);
cout<<temp->value<<endl;

return 0;    
}