#include <iostream>
using namespace std;


class b_tree {
public:    
    int data;
    b_tree* left;
    b_tree* right;
    b_tree(int val) {
        data = val;
        left = right = NULL;
    }
};

void inOrderTravarsel(b_tree *rootNode){

    if(rootNode == NULL){
        return ;
    }

    inOrderTravarsel(rootNode->left);
    cout<<rootNode->data<<" ";
    inOrderTravarsel(rootNode->right);

}
int main() {

    b_tree* rootNode = new b_tree(2);
    rootNode->left = new b_tree(4);
    rootNode->right = new b_tree(10);
    rootNode->left->left = new b_tree(6);
    rootNode->left->right = new b_tree(5);
    rootNode->right->right = new b_tree(11);

    inOrderTravarsel(rootNode);
    
    return 0;
}

   //     2
   //  4    10
   //6   5     11