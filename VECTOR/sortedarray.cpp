//check if the given array is sorted or not

#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    int arr[]={1,2,3,4,5,6};
     

    bool flag=true; 
    for(int i=1;i<6;i++){
        if(arr[i]<=arr[i-1]){
           flag=false;
        }
    }

    cout<<flag<<endl;

    return 0;
}