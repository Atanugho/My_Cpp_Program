

#include<iostream>
using namespace std;

void f(int num,int k){
    //base case
    if(k==0) return;

    f(num,k-1);

    cout<<(num * k)<<" ";
}
int main(){
f(8 ,5);
return 0;
}