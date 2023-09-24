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

    void insertAtStart(int val){

        Node* new_node=new Node(val);
        if(head==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
        return;
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
    void insertAtKthPosition(int val,int k){
        Node* temp=head;
        int count=1;
        while(count<(k-1)){
            temp=temp->next;
            count++;
        }
        Node* new_node=new Node(val);
        new_node->next=temp->next;
        temp->next=new_node;
        new_node->prev=temp;
        new_node->next->prev=new_node;
        return;
    } 
    void deleteAtstart(){
        if(head==NULL){
            return;
        }
        Node* temp=head;
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        free(temp);
    }
    void deleteAtTail(){
        if(head==NULL){
            return;
        }
        Node* temp=tail;
        tail=tail->prev;
        if(tail==NULL){
            head=NULL;
        }else{
            tail->next=NULL;
        }
        free(temp);
        return;
    }
    void deleteAtPosition(int k){
        Node* temp=head;
        int count=1;
        while(count<k){
            temp=temp->next;
            count++;
        }
        //now k is pointing to the node t kth position
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        return;
    }
};

int main(){

doublyLinkList dll;
//dll.insertAtStart(1);
//dll.insertAtStart(2);
//dll.insertAtStart(3);
//dll.display();
dll.insertAtTail(1);
dll.insertAtTail(2);
dll.insertAtTail(3);
dll.insertAtTail(4);
dll.display();
dll.insertAtKthPosition(4,3);
dll.display();
//dll.deleteAtstart();
//dll.display();
//dll.deleteAtTail();
//dll.display();
dll.deleteAtPosition(3);
dll.display();


return 0;
}

