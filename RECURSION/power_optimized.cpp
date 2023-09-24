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
int main(){
int ans =power(2,5);
cout<<ans;
return 0;
}