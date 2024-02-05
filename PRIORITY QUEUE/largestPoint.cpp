
#include<iostream>
#include<queue>
using namespace std;


int largestPoint(vector<int> arr,int n,int k){

    priority_queue<int ,vector<int>, greater<int> >pq;

    for(auto i : arr){
        pq.push(i);
    }

    while(k--){
        int firstElement = pq.top();
        pq.pop();
        int secondElement = pq.top();
        pq.pop();

        int product = firstElement * secondElement;
        pq.push(product);
    }

    //find largest element in priority_queue

    while(pq.size() > 1){
        pq.pop();
    }

    return pq.top();

}

int main(){

int n,k;
cin>>n>>k;
vector<int> arr(n);
for(int i =0 ;i<n;i++){
    cin>>arr[i];
}

cout<<largestPoint(arr,n,k)<<endl;

    return 0;

}