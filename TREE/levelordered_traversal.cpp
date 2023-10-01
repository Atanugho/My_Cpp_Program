#include <iostream>
#include<queue>
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

void levelOrderTravarsel(b_tree *rootNode){

    if(rootNode ==NULL){
        return;
    }
    queue<b_tree*>q;
    q.push(rootNode);

    // while(!q.empty()){
    //     int nodes = q.size();

        while(rootNode != NULL){
            b_tree* currNode = q.front();
            q.pop();
            cout<<currNode->data<<" ";

            if(currNode->left !=NULL){
                q.push(currNode->left);
            }
            if(currNode->right !=NULL){
                q.push(currNode->right);
            }
        }
        cout<<endl;
}
int main() {

    b_tree* rootNode = new b_tree(2);
    rootNode->left = new b_tree(4);
    rootNode->right = new b_tree(10);
    rootNode->left->left = new b_tree(6);
    rootNode->left->right = new b_tree(5);
    rootNode->right->right = new b_tree(11);

    levelOrderTravarsel(rootNode);
    
    return 0;
}

   //     2
   //  4    10
   //6   5     11