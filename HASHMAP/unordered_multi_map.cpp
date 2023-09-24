#include<iostream>
#include<unordered_map>
using namespace std;


int main(){
unordered_multimap<string,int>fruitcount;

fruitcount.insert(make_pair("apple",6));
fruitcount.insert(make_pair("bananna",9));
fruitcount.insert(make_pair("apple",3));

for(auto pair:fruitcount){
    cout<<"fruit-"<<pair.first<<endl;
    cout<<"count-"<<pair.second<<endl;
}

return 0;    
}