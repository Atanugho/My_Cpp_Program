#include<iostream>
using namespace std;

class stack{
    int capacity;
    int* arr;
    int top;
    public:
    stack(int c){
        this->capacity = c;
        arr = new int[c];
        this->top = -1;
    }
    void push(int data){
        if(this->top >= this->capacity-1){
            cout<<"overflow\n";
            return;
        }
         this->top++;
         this->arr[this->top] = data;
    }
    int pop(){
        if(this->top == -1){
            cout<<"underflow\n";
            return INT_MIN;
        }
        this->top--;
    }
    int getTop(){
        if(this->top == -1){
            cout<<"underflow\n";
            return INT_MIN;
        }
        return this->arr[this->top];
    }
    bool isEmpty(){
        return this->top == -1;
    }
    int size(){
        return this->top + 1;
    }
    bool isFull(){
        return this->top >= this->capacity-1;
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