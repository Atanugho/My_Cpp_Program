//find the second largest of an array;

#include<iostream>
using namespace std;
int main(){

int arr[]={2,5,6,7,8,9};
int size=6;
int max=INT_MIN;
int smax=INT_MIN;

for(int i=0;i<size;i++){
    if(arr[i]>max){
        max=arr[i];
    }
}
for(int i=0;i<size;i++){
    if(arr[i]!=max && smax<arr[i]){
        smax=arr[i];
    }
}
cout<<smax<<endl;

return 0;    
}