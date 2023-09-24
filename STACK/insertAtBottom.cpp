#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st,int x){
    stack<int> temp;
    while(not st.empty()){
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(x);
    while(not temp.empty()){
        int curr =temp.top();
        temp.pop();
        st.push(curr);
    }
}
//by recursion

void f(stack<int> &st,int x){
    if(st.empty()){
        st.push(x);
        return ;
    }
    int curr = st.top();
    st.pop();
    f(st,x);
    st.push(curr);
}

int main(){

stack<int> st;
st.push(1);
st.push(2);
st.push(3);
st.push(4);
//insertAtBottom(st,100);
f(st,100);
while(not st.empty()){
    int curr = st.top();
    st.pop();
    cout<<curr<<"\n";
}
return  0;    
}