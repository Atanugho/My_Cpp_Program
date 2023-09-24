
//find the difference between the sum of elements at even indices to the sum of elements at odd indices.

#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    int arr[]={1,2,3,6,3,4};
    int anssum=0;
    for(int i=0;i<6;i++){
        if(i%2==0){
            anssum+=arr[i];
        }
        else{
            anssum-=arr[i];
        }
    }
    cout<<anssum<<endl;
    return 0;
}