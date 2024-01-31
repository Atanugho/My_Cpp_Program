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

int remove(int arr[],int &size){

    int removedVal = arr[0];
    arr[0] = arr[size-1];
    size--;
    heapify(arr,size,0);
    return removedVal;
}

int sumOfSmallest(int arr[],int size,int k1,int k2){

    for(int i = size/2-1;i>=0;i--){
        heapify(arr,size,i);
    }

    int sum = 0;
    int elements = k2-k1-1;

    while(k1--){
        remove(arr,size);
    }

    while(elements--){
        sum +=remove(arr,size);
    }
    return sum;
}

int main(){  

    int arr[N] = {20,8,22,4,12,10,14};
    int size = 7;

    int k1 = 3;
    int k2 = 6;

    cout<<sumOfSmallest(arr,size,k1,k2);

    return 0;
}