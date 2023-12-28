#include<iostream>
#include<unordered_set>
using namespace std;


int main(){

unordered_set<int> s1;

s1.insert(3);
s1.insert(7);
s1.insert(8);
s1.insert(2);

for(auto value:s1){
    cout<<value<<" ";
}



    return 0;
}