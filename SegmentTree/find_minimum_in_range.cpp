#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void buildSegmentTree(vector<int> &nums,vector<int> &segTree,int i,int l,int r){
    if(l == r){
        segTree[i] = nums[l];
        return;
    }

    int mid = l + (r-l)/2;

    buildSegmentTree(nums,segTree,2*i+1,l,mid);
    buildSegmentTree(nums,segTree,2*i+2,mid+1,r);

    segTree[i] = min(segTree[2*i+1],segTree[2*i+2]);
}

int rangeMinimumQuery(vector<int> &segTree,int i,int l,int r,int start,int end){

    if (end < l || start > r) {
        return INT_MAX; 
    }

    if(start <= l && r <= end){
        return segTree[i];
    }

    int mid = l + (r - l) / 2;

    int leftMin = rangeMinimumQuery(segTree,2*i+1,l,mid,start,end);
    int rightMin = rangeMinimumQuery(segTree,2*i+2,mid+1,r,start,end);

    return min(leftMin,rightMin);

}

int main() {

    cout<<"Enter the size of the array:";
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i = 0;i < n;i++){
        cin>> nums[i];
    }

    vector<int> segTree(4*n);

    buildSegmentTree(nums,segTree,0,0,n-1);

    int start = 1, end = 4; // also we can write this user defined 

    cout<<"Minimum in range [" << start << ", " << end<< "] is: " << rangeMinimumQuery(segTree,0,0,n-1,start,end) << endl;

    return 0;
}