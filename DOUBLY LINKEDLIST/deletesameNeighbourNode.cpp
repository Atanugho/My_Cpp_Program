#include<iostream>
using namespace std;
class Node{
public:
      int val;
      Node* prev;
      Node* next;
      
      Node(int data){
        val=data;
        prev = NULL;
        next=NULL;
      }
};
class doublyLinkList{
public:
       Node* head;
       Node* tail;
       doublyLinkList(){
        head=NULL;
        tail=NULL;
       } 
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }cout<<endl;
    }
    void insertAtTail(int val){
        Node* new_node=new Node(val);
        if(tail==NULL){
            head=new_node;
            tail=new_node;
            return ;
        }
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
        return;
    } 
};
void deleteSameNeighbourNode(Node* &head,Node* &tail){
    Node* currNode =tail->prev;
    while(currNode!=head){
        Node* prevNode = currNode->prev;
        Node* nextNode =currNode->next;
        if(prevNode->val==nextNode->val){
            //Ineed to delete the curr node
            prevNode->next = nextNode;
            nextNode->prev= prevNode;
            free(currNode);
        }
        currNode = prevNode;
    }
} 
int main(){
doublyLinkList dll;
dll.insertAtTail(2);
dll.insertAtTail(1);
dll.insertAtTail(1);
dll.insertAtTail(2);
dll.insertAtTail(1);
dll.display();

deleteSameNeighbourNode(dll.head,dll.tail);
dll.display();

return 0;
}   