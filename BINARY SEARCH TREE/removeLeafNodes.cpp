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

Node* removeLeafNodes(Node* root){

    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        return NULL;
    }
    
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);
    return root;
}

void preOrderTraversal(Node* root){

    if(root == NULL) return;


    cout<<root->value<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    
}

int main(){

BST bst;
bst.root = insertBSTRecursive(bst.root,3);
insertBSTRecursive(bst.root,1);
insertBSTRecursive(bst.root,4);
insertBSTRecursive(bst.root,6);
insertBSTRecursive(bst.root,2);

preOrderTraversal(bst.root);
cout<<endl;
removeLeafNodes(bst.root);
preOrderTraversal(bst.root);
cout<<endl;

return 0;    
}