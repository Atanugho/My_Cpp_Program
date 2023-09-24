#include<iostream>
#include<map>
using namespace std;


int main(){

map<string,int>directory;
directory["naman"] = 3876;
directory["animesh"] = 72463;
directory["ritam"]= 53847;

for(auto element:directory){
    cout<<"Name-"<<element.first<<endl;
     cout<<"phone no.-"<<element.second<<endl;
}
cout<<endl;
//directory.insert(make_pair("ritam",76353));
// for(auto element:directory){
//     cout<<"Name-"<<element.first<<endl;
//      cout<<"phone no.-"<<element.second<<endl;
// }

map<string,int>::reverse_iterator itr;
for(itr = directory.rbegin(); itr!=directory.rend();itr++){
    cout<<itr->first<<"-"<<itr->second<<endl;
}
return 0;    
}