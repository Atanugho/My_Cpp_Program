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
Node* reversell(Node* &head){
    Node* prevptr=NULL;
    Node* curptr=head;

    while(curptr!=NULL){
        Node* nextptr=curptr->next;
        curptr->next=prevptr;//move all 3 ptr by one step
        prevptr=curptr;
        curptr=nextptr;
    }
    //when this loop ends ,prevptr pointing to my last node which is new head
    Node* new_head=prevptr;
    return new_head;
}
int main(){

LinkList ll;
ll.insertAtTail(1);
ll.insertAtTail(2);
ll.insertAtTail(3);
ll.insertAtTail(4);
ll.insertAtTail(5);
ll.display();
ll.head=reversell(ll.head);
ll.display();
return 0;
}

