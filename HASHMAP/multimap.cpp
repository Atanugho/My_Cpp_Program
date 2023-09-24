#include<iostream>
#include<map>
using namespace std;


int main(){
multimap<string,int>directory;
directory.insert(make_pair("urvi", 36363));
directory.insert(make_pair("riyan", 6544));
directory.insert(make_pair("ratul", 66383));
directory.insert(make_pair("ratul", 66383));

//[]->not allowed

for(auto pair:directory){
    cout<<"Name-"<<pair.first<<endl;
    cout<<"phone no-"<<pair.second<<endl;
}

// cout<<directory.count("ratul"); ->2

return 0;    
}