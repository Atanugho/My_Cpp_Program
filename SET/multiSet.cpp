#include<iostream>
#include<set>
using namespace std;


int main(){

multiset<int> ms;

ms.insert(4);
ms.insert(5);
ms.insert(5);
ms.insert(1);
ms.insert(7);
ms.insert(2);


for(auto value:ms){
    cout<<value<<" ";
}



    return 0;
}