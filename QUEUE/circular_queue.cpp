#include<iostream>
#include<vector>
using namespace std;

class Queue{
    int front; 
    int back;
    vector<int>v;
    int size;
    int ts;
public:
    Queue(int n){
        v.resize(n);
        this->ts = n;
        this->back = n-1;
        this->front = 0;
        this->size = 0;
    } 
    void enqueue(int data){
        if(isFull()) return;
        this->back = (this->back + 1) % this->ts;
        this->v[this->back] = data;
        this->size++;
    }
    void dequeue(){
        if(isEmpty()) return ;
        this->front = (this->front+1) % this->ts;
        this->size--;
    }
    int getFront(){
        if(this->front ==-1) return -1;
        return  this->v[this->front];
    }
    bool isEmpty(){
        return this->size ==0;
    }
    bool isFull(){
        return this->size ==this->ts;
    }
};
int main(){

Queue qu(3);
qu.enqueue(10);
qu.enqueue(20);
qu.enqueue(30);
qu.dequeue();
qu.enqueue(40);

while(not qu.isEmpty()){
    cout<<qu.getFront()<<" ";
    qu.dequeue();
}
return 0;    
}