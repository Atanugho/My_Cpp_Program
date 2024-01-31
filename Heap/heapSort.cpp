#include<iostream>
using namespace std;
int const N = 1e3;

void heapify(int arr[],int n,int curr){

    while(2*curr <= n){

        int leftChild = 2*curr;
        int rightChild = 2*curr+1;
        int maxChild = leftChild;

        if(rightChild <= n && arr[rightChild] > arr[maxChild]){
            maxChild = rightChild;
        }

        if(arr[maxChild] <= arr[curr]){
            return ;
        }
        swap(arr[maxChild],arr[curr]);
        curr = maxChild;
    }
}

void remove(int arr[],int& size){

    swap(arr[1],arr[size]);
    size--;
    heapify(arr,size,1);

}

void heapSort(int arr[],int n){

    for(int i = n/2;i>0;i--){
        heapify(arr,n,i);
    }

    //2.keep deleting element until size become zero

    while(n>0){
        remove(arr,n);
    }
}

int main(){  

    int arr[N] = {-1,60,10,80,50,5,20,70};
    int n = 7;
    heapSort(arr,n);

    for(int i = 1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}