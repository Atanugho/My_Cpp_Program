#include <iostream>
#include<vector>
#include<queue>
#include<stack>
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
vector<int> reverseLevelOrder(Node *root){
    vector<int>ans;
    if(root == NULL){
        return ans;
    }
    queue<Node* >q;
    stack<Node*>st;
    q.push(root);

    while(!q.empty()){

        int size = q.size();
        while(size--){
            Node* currNode = q.front();
            q.pop();
            st.push(currNode);
            
            if(currNode->right){
                q.push(currNode->right);
            }
            if(currNode->left){
                q.push(currNode->left);
            }
        }
    }
    while(!st.empty()){
        ans.push_back(st.top()->value);
        st.pop();
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

   vector<int>ans = reverseLevelOrder(rootNode);
   for(auto itr:ans){
    cout<<itr<<" ";
   }
    
    return 0;
}

   //     2
   //  4    10
   //6   5     11