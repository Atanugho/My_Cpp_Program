#include<iostream>
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

void insertBST(Node* &root,int val){
    Node* newNode = new Node(val);
    if(root == NULL){
        root = newNode;
        return;
    }

    Node* curr = root;
    while(true){
        if(curr->value > val){
            if(curr->left == NULL){
                curr->left = newNode;
                return;
            }
            curr = curr->left;
        }
        else{
            if(curr->right == NULL){
                curr->right = newNode;
                return;
            }
            curr = curr->right;
        }
    }
}

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

void inOrderTraversal(Node* root){

    if(root == NULL) return;

    inOrderTraversal(root->left);
    cout<<root->value<<" ";
    inOrderTraversal(root->right);
}

int main(){

BST bst;

bst.root = insertBSTRecursive(bst.root,3);
insertBSTRecursive(bst.root,1);
insertBSTRecursive(bst.root,4);
insertBSTRecursive(bst.root,6);
insertBSTRecursive(bst.root,2);

inOrderTraversal(bst.root);

return 0;    
}