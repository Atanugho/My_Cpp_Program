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

void inorderPreSuccBST(Node* root,Node* &pre,Node* &succ,int key){

        if(root == NULL){
            return ;
        }
        if(root->value == key){
            if(root->left != NULL){
                Node* temp = root->left;
                while(temp->right != NULL){
                    temp = temp->right;
                }
                pre = temp;
            }
            if(root->right != NULL){
                Node* temp = root->right;
                while(temp->left != NULL){
                    temp = temp->left;
                }
                succ = temp;
            }
            return;
        }
        if(root->value>key){
            succ = root;
            inorderPreSuccBST(root->left,pre,succ,key);
        }else if(root->value<key){
            pre = root;
            inorderPreSuccBST(root->right,pre,succ,key);
        }
}

int main(){

BST bst1;
bst1.root = insertBSTRecursive(bst1.root,3);
insertBSTRecursive(bst1.root,1);
insertBSTRecursive(bst1.root,4);
insertBSTRecursive(bst1.root,6);
insertBSTRecursive(bst1.root,2);

Node* pre= NULL;
Node* succ = NULL;

inorderPreSuccBST(bst1.root,pre,succ,4);
if(pre!= NULL){
    cout<<"pre-"<<pre->value<<endl;
}
else{
    cout<<"pre-null"<<endl;
}
if(succ!= NULL){
    cout<<"succ-"<<succ->value<<endl;
}
else{
    cout<<"succ-null"<<endl;
}

    return 0;
}
