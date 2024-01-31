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

bool isPalindrome(Node* head){
    Node* slow=head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow=slow->next;
        fast= fast->next->next;
    }
    //slow is pointing to middle element
    //2nd step-break the linked list in the middle

    Node* curr = slow->next;
    Node* prev = slow;
    slow->next=NULL;

    //step 3-reverse the second half of the linked list
    while(curr!=NULL){
        Node* nextNode= curr->next;
        curr->next = prev;
        prev=curr; 
        curr = nextNode;
    }
    //step 4-to check if the two linked list are equal
    Node* head1 = head;
    Node* head2 = prev;

    while(head2){
        if(head1->val != head2->val){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return true;
}

int main(){
LinkList ll;
ll.insertAtTail(1);
ll.insertAtTail(2);
ll.insertAtTail(2);
ll.insertAtTail(1);
// ll.insertAtTail(2);
// ll.insertAtTail(1);
ll.display();
cout<<isPalindrome(ll.head)<<endl;
return 0;    
}