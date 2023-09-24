
#include<iostream>
#include<vector>
using namespace std;

bool canDistChoco(vector<int>arr,int mid,int s){
    int n=arr.size();
    int studentsReqd=1;
    int currsum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>mid){
            return false;
        }
        if(currsum+arr[i]>mid){
            studentsReqd++;
            currsum=arr[i];
            if(studentsReqd>s) return false;
        }
        else{
            currsum+=arr[i];
        }
    }
    return true;
}

int distChoco(vector<int>&arr,int s){
    int n=arr.size();
    int lo=arr[0];
    int hi=0;
    for(int i=0;i<arr.size();i++){
        hi+=arr[i];
    }
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(canDistChoco(arr,mid,s)){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return ans;
}
int main(){

int n;
cin>>n;
vector<int>v;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    v.push_back(x);
}
int s;
cin>>s;
cout<<distChoco(v,s)<<"\n";
return 0;
}
