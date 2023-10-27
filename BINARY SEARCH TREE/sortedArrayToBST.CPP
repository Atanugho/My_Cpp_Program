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

Node* sortedArrayToBst(vector<int>v,int start,int end){

    if(start>end){
        return NULL;
    }

    int mid = (start+end)/2;
    Node* root= new Node(v[mid]);

    root->left = sortedArrayToBst(v,start,mid-1);
    root->right = sortedArrayToBst(v,mid+1,end);
    return root;
}



void preOrderTraversal(Node* root){

    if(root == NULL) return;


    cout<<root->value<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    
}

int main(){

int n;
cin>>n;

vector<int>v(n);
for(int i=0;i<n;i++){
    cin>>v[i];
}
BST bst;
bst.root = sortedArrayToBst(v,0,n-1);

preOrderTraversal(bst.root);

return 0;    
}