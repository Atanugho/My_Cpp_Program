#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr1[]={1,6,7,10};
    int arr2[]={0,1,3,8,11,12,15,18};
    int m=4;
    int n=8;

    int result[m+n];
    int i=0;
    int j=0;
    int k=0;

    while(i<m && j<n){
      if(arr1[i]<arr2[j]){
        result[k]=arr1[i];
        k++;
        i++;
      }
      else{
        result[k]=arr2[j];
        k++;
        j++;
      }
    }
    while(i<m){
        result[k]=arr1[i];
        k++;
        i++;
    }
    while(j<n){
        result[k]=arr2[j];
        k++;
        j++;
    }
    for(int i=0;i<(m+n);i++){
        cout<<result[i]<<" ";
    }
    return 0;
}