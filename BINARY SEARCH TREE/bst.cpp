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




bool searchBST(Node* root,int key){

    if(root==NULL){
        return false;
    }
    if(root->value==key){
        return true;
    }
    
    if(root->value<key){
        return searchBST(root->right,key);
    }
    if(root->value>key){
        return searchBST(root->left,key);
    }
}





Node* largestNodeBst(Node *root){
    Node * curr = root;
    while(curr && curr->right){
        curr = curr->right;
    }
    return curr;
}

Node* deleteBST(Node* root,int key){

    if(root==NULL){
        return root;
    }
    if(root->value<key){
        root->right = deleteBST(root->right,key);
    }
    else if(root->value>key){
        root->left = deleteBST(root->left,key);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        else if(root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else{
            Node* justSmallerNode = largestNodeBst(root->left);
            root->value = justSmallerNode->value;
            root->left = deleteBST(root->left,justSmallerNode->value);
        }
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
cout<<endl;

// cout<<searchBST(bst.root,8)<<endl;

bst.root = deleteBST(bst.root,6);
inOrderTraversal(bst.root);
cout<<endl;

return 0;    
}