#include<iostream>
#include<unordered_map>
using namespace std;


int main(){

unordered_map<int ,string>record;

record.insert(make_pair(3,"ria"));
record[1] = "rohan";
record[2] = "ani";
// record[3] = "payel"; change no 3 -> its use for update value
// record.insert(make_pair(3,"payel")); do not change no 3

for(auto pair:record){
    cout<<"Roll no-"<<pair.first<<endl;
    cout<<"name-"<<pair.second<<endl;
}
 
return 0;    
}