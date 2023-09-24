#include<iostream>
#include<stack>
using namespace std;

class queue{
    stack<int>st;
public:
    queue(){}

    void push( int x){
        stack<int>tmp;
        while(not this->st.empty()){
            tmp.push(this->st.top());
            this->st.pop();
        } 
        this->st.push(x);
        while(not tmp.empty()){
            this->st.push(tmp.top());
            tmp.pop();
        }
    }
    void pop(){
        if(this->st.empty()) return;
        this->st.pop();
    }
    bool empty(){
        return this->st.empty();
    }
    int front(){
        if(this->st.empty()) return -1;
        return this->st.top();
    }


};
int main(){
queue qu;
qu.push(10);
qu.push(20);
qu.push(30);
qu.push(40);
qu.pop();
while(not qu.empty()){
    cout<<qu.front()<<" ";
    qu.pop();
}
return 0;
}