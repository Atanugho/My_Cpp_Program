#include<iostream>
#include<string>  
#include<vector>
using namespace std;

int longestOnes(string str,int k){

    int start = 0;
    int end = 0;

    int zero_count = 0;
    int max_length = 0;

    for(;end < str.length();end++){

        if(str[end] == '0'){
            zero_count++;
        }

        while(zero_count > k){

            if(str[start] == '0')  zero_count--;

            start++;
        }

        max_length = max(max_length,end-start+1); 
    }

    return max_length;
}

int main(){

string str;
cout<<"Enter Binary String:";
cin>>str;

int k;
cout<<"Enter Max Flips:";
cin>>k;

cout<<longestOnes(str,k);

return 0;
}