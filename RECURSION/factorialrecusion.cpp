#include<iostream>
using namespace std;

int fact(int n){

    //base case
    if(n==1) return 1;

    int ans=n*fact(n-1);
    return ans;
}

int main(){
int result=fact(5);
cout<<result;
return 0;
}




