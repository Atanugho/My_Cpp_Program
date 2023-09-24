#include <iostream>
using namespace std;


class bs_tree {
public:    
    int data;
    bs_tree* left;
    bs_tree* right;
    bs_tree(int val) {
        data = val;
        left = right = NULL;
    }
};
bs_tree* r_insertion(bs_tree*  root, int x) {

    bs_tree* t = new bs_tree(x);
    if (root == NULL) {
        root = t;
    }
    if (x < root->data) {
        root->left = r_insertion(root->left, x);
    } else if (x > root->data) {
        root->right = r_insertion(root->right, x);
    }
    
    return root;
}

bs_tree* i_insertion(bs_tree* root, int x) {
    bs_tree* t = new bs_tree(x);
    if (root == NULL) {
        return t;
    }
    
    bs_tree* current = root;
    bs_tree* parent = NULL;
    
    while (current != NULL) {
        
        if (x < current->data) {
            parent = current;
            current = current->left;
        } else if (x > current->data) {
            parent = current;
            current = current->right;
        }
    }
    if (x < parent->data) {
        parent->left = t;
    } else {
        parent->right = t;
    }
    
    return root;
}

void inorderTraversal(bs_tree* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    bs_tree* root = NULL;
    
    root = r_insertion(root, 50);
    root = r_insertion(root, 30);
    root = r_insertion(root, 70);
    root = i_insertion(root, 20);
    root = i_insertion(root, 40);
    root = i_insertion(root, 60);
    root = i_insertion(root, 80);
    
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;
    
    return 0;
}