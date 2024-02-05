#include<iostream>
#include<string>  
#include<vector>
#include<algorithm>
using namespace std;
 
 //space complexity ->O(n);
 //time complexity -> O(n); where n is length of decoded string
 
string decodedString(string s){

    string result = "";

    for(int i = 0;i<s.size();i++){

        if(s[i] != ']'){
            result.push_back(s[i]);
        }else{
            string str = "";
            while(!result.empty() && result.back() != '['){
                str.push_back(result.back());
                result.pop_back();
            }

            reverse(str.begin(),str.end());

            result.pop_back();

            string num = "";
            while(!result.empty() && (result.back() >= '0' && result.back() <= '9')){
                num.push_back(result.back());
                result.pop_back();
            }

            reverse(num.begin(),num.end());

            int intNum = stoi(num);

            while(intNum){
                result += str;
                intNum--;
            }
        }
    }

    return result;
}

int main(){

string str;
cin>>str;

cout<<decodedString(str);
return 0;
}