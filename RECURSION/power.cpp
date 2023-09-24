#include<iostream>
using namespace std;

int power(int a,int b){
    if(b==0) return 1;

    return a * power(a,b-1);
}
int main(){
int ans =power(2,4);
cout<<ans;
return 0;
}