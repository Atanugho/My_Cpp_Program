
#include<iostream>
#include<vector>
using namespace std;

bool canPlaceStudent(vector<int> &pos,int s,int mid){
    int studentsReqd=1;
    int lastpalce=pos[0];
    for(int i=1;i<pos.size();i++){
        if(pos[i]-lastpalce >=mid){
            studentsReqd++;
            lastpalce=pos[i];
            if(studentsReqd==s){
                return true;
            }
        }
    }
    return false;
}
int race(vector<int> &pos,int s){
    int n=pos.size();
    int lo=1;
    int hi=pos[n-1]-pos[0];
    int ans= -1;
    while(lo<=hi){
        int mid =lo+(hi-lo)/2;
        if(canPlaceStudent(pos,s,mid)){
            ans=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return ans;
}
int main(){

int n;
cin>>n;
vector<int>pos;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    pos.push_back(x);
}
int s;
cin>>s;
cout<<race(pos,s)<<"\n";
return 0;
}
