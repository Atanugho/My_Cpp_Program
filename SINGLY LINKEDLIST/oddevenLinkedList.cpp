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
Node* oddEvenLinkedList(Node* &head){

        if(!head){
        return head;
        }
        Node* evenHead = head->next;
        Node* oddPtr = head;
        Node* evenPtr = evenHead;

        while(evenPtr && evenPtr->next){
            oddPtr->next= oddPtr->next->next;
            evenPtr->next = evenPtr->next->next;
            oddPtr =oddPtr->next;
            evenPtr = evenPtr->next;
        }
        oddPtr->next = evenHead;
        return head;
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
ll.head = oddEvenLinkedList(ll.head);
ll.display();

return 0;
}