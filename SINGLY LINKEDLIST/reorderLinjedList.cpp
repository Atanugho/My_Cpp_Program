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

Node* reorderedLinkedList(Node* &head){

    Node* slow=head;
    Node* fast = head;
    while(fast != NULL &&fast->next !=NULL){
        slow = slow->next;
        fast= fast->next->next;
    }
    //now slow is pointing to the middle of the linked list
    Node* curr= slow->next;
    slow->next=NULL;
    Node* prev =slow;

    while(curr != NULL){
        Node* nextptr = curr->next;
        curr->next= prev;
        prev = curr;
        curr=nextptr;
    }
    //merging two half of the linked list
    Node* ptr1 = head;
    Node* ptr2 =prev;

    while(ptr1 != ptr2){
        Node* temp = ptr1->next;
        ptr1->next = ptr2;
        ptr1 = ptr2;
        ptr2 = temp;
    }
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
ll.head = reorderedLinkedList(ll.head);
ll.display();

return 0;
}