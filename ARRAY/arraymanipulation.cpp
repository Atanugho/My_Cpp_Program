//find the unique number in a given array where all the elements are being repeted twice with one value being unique;

#include<iostream>
#include<vector>
using namespace std;

int main(){

int arr[]={2,3,1,3,2,4,1};
int size=7;
for(int i=0;i<size;i++){
    for(int j=i+1;j<size;j++){
        if(arr[i]==arr[j])
        arr[i]=arr[j]=-1;
    }
}
int unique=0;
for(int i=0;i<size;i++){
    if(arr[i]>0){
        unique=arr[i];
    }
}
cout<<unique<<endl;
return 0;
}