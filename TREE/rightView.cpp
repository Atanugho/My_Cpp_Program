#include <iostream>
#include<vector>
#include<queue>
using namespace std;


class Node {
public:    
    int value;
    Node* left;
    Node* right;
    Node(int val) {
        value = val;
        left = right = NULL;
    }
};
vector<int> rightviewBinaryTree(Node* root){

    vector<int>ans;
    if(root == NULL){
        return ans;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int NodeAtCurrLevel = q.size();
        while(NodeAtCurrLevel){

            Node* currNode = q.front();
            q.pop();

            if(NodeAtCurrLevel == 1){
                ans.push_back(currNode->value);
            }
            if(currNode->left){
                q.push(currNode->left);
            }
            if(currNode->right){
                q.push(currNode->right);
            }
            NodeAtCurrLevel--;
        }
    }
    return ans;

}
int main() {

    Node* rootNode = new Node(2);
    rootNode->left = new Node(4);
    rootNode->right = new Node(10);
    rootNode->left->left = new Node(6);
    rootNode->left->right = new Node(5);
    rootNode->right->right = new Node(11);

    vector<int> ans = rightviewBinaryTree(rootNode);

    for(auto itr :ans){
        cout<<itr<<endl;
    }
    
    return 0;
}

   //     2
   //  4    10
   //6   5     11