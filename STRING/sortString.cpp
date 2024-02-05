#include<iostream>
#include<string>
#include<vector>
using namespace std;

string countSort(string str){

    vector<int> freqArr(26,0);

    for(auto &s:str){
        int idx = s - 'a';
        freqArr[idx]++;
    }

    int j =0;
    for(int i = 0;i< 26;i++){

        while(freqArr[i] --){
            str[j++] = i + 'a';
        }
    }

    return str;

}

int main(){

string str;
cin>>str;

cout<<countSort(str)<<endl;

return 0;
}