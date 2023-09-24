

#include<iostream>
using namespace std;
int power(int a,int b){
    if(b==0) return 1;
    if(b%2==0){
        int result=power(a,b/2);
    return result*result;
    }
    else{
        int result=power(a,(b-1)/2);
        return a * result * result;
    }

}
int f(int n,int d){
    //base case
    if(n==0) return 0;
    return power(n%10,d) + f(n/10,d);
}
int main(){
int n;
cin>>n;

int no_of_digit=0;
int temp=n;
while(temp>0){
    temp = temp/10;
    no_of_digit++;
}
int result = f(n,no_of_digit);
if(result==n){
    cout<<"Yes";
}
else{
    cout<<"No";
}
return 0;
}
