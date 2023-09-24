//count the number of triplets whose sum is equal to the given value x;

#include<iostream>
#include<vector>
using namespace std;

int main(){

int arr[]={3,1,2,4,0,6};
int targetsum=5;
int size=6;
int count=0;
for(int i=0;i<size;i++){
    for(int j=i+1;j<size;j++){
        for(int k=j+1;k<size;k++){
            if(arr[i]+arr[j]+arr[k]==targetsum)
            count++;
        }
    }
}
cout<<count<<endl;

return 0;    
}