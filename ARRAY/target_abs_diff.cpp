#include<iostream>
using namespace std;
int main(){

int arr[]={-2,-1,0,3,6,8,11,12};
int x=3;
int n=8;

int i=0;
int j=1;
bool found =false;
while(i<n && j<n){
    if(abs(arr[i]-arr[j])==x){
        found=true;
        break;
    }
    else if(abs(arr[i]-arr[j])<x){
        j++;
    }else{
        i++;
    }
}
if(found==true){
    cout<<"yes";
}
else{
    cout<<"no";
}

return 0;
}