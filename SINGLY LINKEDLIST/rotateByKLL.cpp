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
 
Node* rotateByK(Node* head,int k){

    //find length of linked list
    int n=0;
    //find tail node
    Node* tail = head;

    while(tail->next){
        n++;
        tail = tail->next;
    }
    n++;  //for including last node

    k = k%n;
    if(k==0){
        return head;
    }
    tail->next=head;
     //traverse  n-k nodes
    Node* temp = head;
    for(int i=1;i<n-k;i++){
        temp = temp->next;
    }
    Node* newhead= temp->next;
    temp->next=NULL;
    return newhead;
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
ll.head =rotateByK(ll.head,3);
ll.display();
return 0;    
}