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

bool checkEqualLinkedList(Node* head1,Node* head2){
    Node* ptr1=head1;
    Node* ptr2=head2;

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->val != ptr2->val){
            return false;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    //at thi point either ptr1 is null,or ptr2 is null,or both are null
    return (ptr1==NULL && ptr2==NULL);
}
int main(){
LinkList ll1;
ll1.insertAtTail(1);
ll1.insertAtTail(2);
ll1.insertAtTail(3);

LinkList ll2;
ll2.insertAtTail(1);
ll2.insertAtTail(2);
ll2.insertAtTail(3);

ll1.display();
ll2.display();
cout<<checkEqualLinkedList(ll1.head,ll2.head)<<endl;
 return 0;   
}