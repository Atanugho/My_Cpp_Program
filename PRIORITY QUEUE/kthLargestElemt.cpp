
#include<iostream>
#include<queue>
using namespace std;


int kthLargestElement(vector<int> arr,int n,int k){

    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i = 0; i<n;i++){
        pq.push(arr[i]);
        if(pq.size() > k){
            pq.pop();
        }
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

cout<<kthLargestElement(arr,n,k);

    return 0;

}