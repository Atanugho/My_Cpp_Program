
#include<iostream>
#include<vector>
using namespace std;

int findPeak(vector<int >&input){
    int lo=0;
    int n=input.size()-1;
     int hi=n-1;
     int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(mid==0){
            if(input[mid]>input[mid+1]){
                return 0;
            }
            else{
                return 1;
            }
        }
        else if(mid=n-1){
            if(input[mid]>input[mid-1]){
                return n-1;
            }
            else{
                return n-2;
            }
        }
        else{
            if(input[mid]>input[mid+1] && input[mid]>input[mid-1]){
                return mid;
            }
            else if(input[mid]>input[mid-1]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }    
    }             
    return ans;       
}
int main(){

vector<int>input;
int n;
cin>>n;
while(n--){
    int x;
    cin>>x;
    input.push_back(x);
}
cout<<findPeak(input)<<"\n";
return 0;
}
