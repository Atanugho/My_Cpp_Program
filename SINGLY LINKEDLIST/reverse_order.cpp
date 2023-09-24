
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
void reversePrint(Node* head){
    if(head==NULL){
        return;
    }
    reversePrint(head->next);
    cout<<head->val<<" ";
}
int main(){

LinkList ll;
ll.insertAtTail(1);
ll.insertAtTail(2);
ll.insertAtTail(3);
ll.insertAtTail(4);
ll.display();
reversePrint(ll.head);
return 0;
}
