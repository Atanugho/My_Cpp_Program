#include<iostream>
using namespace std;

class Node{
public:
      int data;
      Node* next;
      Node(int d){
        this->data =d;
        this->next = NULL;
      }
};
class stack{
    Node* head;
    int capacity;
    int currSize;
    public:
    stack(int c){
        this->capacity = c;
        this->currSize = 0;
        head =NULL;
    }
    bool isEmpty(){
        return this->head == NULL;
    }
    bool isFull(){
        return this->currSize == this->capacity; 
    }
    void push(int data){
    if(this->currSize == this->capacity){
        cout<<"overflow\n";
        return;
    }
    Node* newnode = new Node(data);
    newnode->next =this->head;
    this->head = newnode;
    this->currSize++;
   } 
   int pop(){
    if(this->head ==NULL){
        cout<<"underflow\n";
        return INT_MIN;
    }
    Node* new_head = this->head->next;
    this->head->next = NULL;
    Node*toBeRemoved = this->head;
    int result = toBeRemoved->data;
    delete toBeRemoved;
    this->head = new_head;
    return result;
   }
   int getTop(){
    if(this->head == NULL){
        cout<<"underflow\n";
        return INT_MIN;
    }
    return this->head->data;
   }
   int size(){
    return this->currSize;
   }
};


int main(){
stack st(5);
st.push(1);
st.push(2);
st.push(3);
cout<<st.getTop()<<"\n";
st.push(4);
st.push(5);
cout<<st.getTop()<<"\n";
st.push(6);

st.pop();
st.pop();
cout<<st.getTop()<<"\n";

return 0;
}

