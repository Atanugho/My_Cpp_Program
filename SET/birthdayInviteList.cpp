#include<iostream>
#include<set>
using namespace std;

int main(){

set<string> list;

int n; 
cin>>n;

while(n--){
    string name;
    cin>>name;

    list.insert(name);
}

for(auto name:list){
    cout<<name<<endl;
}

return 0;    
}