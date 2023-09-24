#include<iostream>
using namespace std;
class Node{
public:
      int val;
      Node* next;
      
      Node(int data){
        val=data;
        next=NULL;
      }
};
class LinkList{
public:
       Node* head;

       LinkList(){
        head=NULL;
       } 
    void insertAtTail(int value){

        Node* new_node=new Node(value);
        if(head==NULL){
            head=new_node;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    } 
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }cout<<"NULL"<<endl;
    }     
};
Node* reversekll(Node* &head,int k){
    Node* prevptr=NULL;
    Node* currptr=head;

    int counter=0; //for counting first k nodes
    while(currptr!=NULL && counter<k){
        Node* nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        counter++;
    }
    if(currptr!=NULL){
        Node* new_head=reversekll(currptr,k);
        head->next=new_head;
    }
    return prevptr;
}
int main(){

LinkList ll;
ll.insertAtTail(1);
ll.insertAtTail(2);
ll.insertAtTail(3);
ll.insertAtTail(4);
ll.insertAtTail(5);
ll.insertAtTail(6);
ll.display();
ll.head=reversekll(ll.head,2);
ll.display();
return 0;
}

