
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

 int histogram(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    int ans = INT_MIN;
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() and arr[i] < arr[st.top()]){
            int ele = arr[st.top()];
            int nsi = i;
            int psi = (st.empty()) ? (-1) : st.top();
            ans = max(ans,ele*(nsi - psi - 1));
            st.pop();
        }
        st.push(i);
    }
    while(not st.empty()){
        int ele = arr[st.top()];
        int nsi = n;
        int psi = (st.empty()) ? (-1) : st.top();
        ans = max(ans,ele*(nsi - psi - 1));
        st.pop();
    }
    return ans;
}
int main(){