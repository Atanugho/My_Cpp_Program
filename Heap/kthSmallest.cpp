#include<iostream>
using namespace std;
int const N = 1e3;


void heapify(int arr[],int &size,int curr){

    while(2*curr +1 < size){

        int leftChild = 2*curr+1;
        int rightChild = 2*curr+2;

        int minChild = leftChild;
        if(rightChild < size && arr[rightChild] < arr[leftChild]){
            minChild = rightChild;
        }

        if(arr[minChild] >= arr[curr]){
            return ;
        }
        swap(arr[curr],arr[minChild]);
        curr = minChild;
    }
}

void remove(int arr[],int &size){

    arr[0] = arr[size-1];
    size--;
    heapify(arr,size,0);

}

int kthSmallestElement(int arr[],int size,int k){

    for(int i = size/2-1;i>=0;i--){
        heapify(arr,size,i);
    }

    k-=1;
    while(k--){
        remove(arr,size);
    }
    
    return arr[0];
}

int main(){  

    int arr[N] = {60,10,80,50,5,20,70};
    int size = 7;

    cout<<kthSmallestElement(arr,size,3);

    return 0;
}