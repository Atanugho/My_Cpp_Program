#include <iostream>
using namespace std;


class Node {
public:    
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int maxDepth(Node* root){

    if(root==NULL){
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth,rightDepth)+1;
}
int main() {

    Node* rootNode = new Node(2);
    rootNode->left = new Node(4);
    rootNode->right = new Node(10);
    rootNode->left->left = new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->right->right = new Node(11);

    cout<<maxDepth(rootNode)<<endl;
    
    return 0;
}

   //     2
   //  4    10
   //6   5     11