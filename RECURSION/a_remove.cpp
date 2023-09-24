

#include<iostream>
using namespace std;

string f(string &str,int idx,int n){
    if(idx==n){
        return " ";
    }
    string curr="";
    curr +=str[idx];
    return ((str[idx]=='a')?"":curr)+f(str,idx+1,n);
}
int main(){
string str="abcax";
int n=5;
cout<<f(str,0,n);
return 0;
}