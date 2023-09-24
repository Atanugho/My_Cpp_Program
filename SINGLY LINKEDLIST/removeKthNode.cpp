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
void removeKthNodeFromEnd(Node* head,int k){
    Node* ptr1= head;
    Node* ptr2=head;

    int count =k;
    while(count--){
        ptr2=ptr2->next;
    }
    if(ptr2==NULL){
        Node* temp=head;
        head = head->next;
        free(temp);
        return;
    }
    while(ptr2->next != NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    //now ptr1 is pointing to the node before kth node from end
    Node* temp=ptr1->next;
    ptr1->next=ptr1->next->next;
    free(temp);
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
removeKthNodeFromEnd(ll.head,3);
ll.display();

return 0;
}  