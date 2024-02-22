#include <iostream>
using namespace std;
int const N = 1e3;

void removeMinHeap(int minHeap[], int size)
{

    minHeap[1] = minHeap[size];
    size--;

    int curr = 1;
    while (2 * curr <= size)
    {
        int leftChild = 2 * curr;
        int rightChild = 2 * curr + 1;

        int minChild = leftChild;
        if (rightChild <= size && minHeap[rightChild] < minHeap[leftChild])
        {
            minChild = rightChild;
        }

        if (minHeap[minChild] >= minHeap[curr])
        {
            return;
        }
        swap(minHeap[minChild], minHeap[curr]);
        curr = minChild;
    }
}
int main()
{

    int minHeap[N] = {-1, 10, 20, 30, 40, 50};
    int size = 5;
    int val = 5;

    // insertMinHeap(minHeap,size,val);
    // for(int i = 0;i<=size;i++) {
    //     cout<<minHeap[i]<<" ";
    // }cout<<endl;

    removeMinHeap(minHeap, size);

    for (int i = 0; i < size; i++)
    {
        cout << minHeap[i] << " ";
    }
    cout << endl;

    return 0;
}