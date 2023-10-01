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


int main() {

    b_tree* root = new b_tree(2);
    root->left = new b_tree(3);
    root->right = new b_tree(4);

    cout<<"Root Node:"<<root->data<<endl;
    cout<<"Left Child:"<<root->left->data<<endl;
    cout<<"Right Child:"<<root->right->data<<endl;
    
    return 0;
}
