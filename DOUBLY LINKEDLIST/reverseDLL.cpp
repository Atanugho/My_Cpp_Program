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
    void reverseDll(Node* &head,Node* &tail){
        Node* currPtr = head;
        while(currPtr){
            Node* nextPtr=currPtr->next;
            currPtr->next=currPtr->prev;
            currPtr->prev=nextPtr;
            currPtr =nextPtr;
        }
        Node* newhead=tail;
        tail=head;
        head=newhead;
    }
};
int main(){
doublyLinkList dll;
dll.insertAtTail(1);
dll.insertAtTail(2);
dll.insertAtTail(3);
dll.display();
dll.reverseDll(dll.head,dll.tail);
dll.display();

return 0;
} 