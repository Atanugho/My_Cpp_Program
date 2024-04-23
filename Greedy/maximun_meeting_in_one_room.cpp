#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct meeting
{
    int start;
    int end;
    int idx;
};

bool cmp(meeting m1 ,meeting m2){
    return m1.end < m2.end;
}

void print_maximum_meeting(vector<meeting> &arr){
    sort(arr.begin(),arr.end(),cmp);

    cout<<arr[0].idx<<" ";
    meeting last = arr[0];
    for(int i = 1;i< arr.size();i++){
        if(arr[i].start > last.end){
            cout<<arr[i].idx<<" ";
            last = arr[i];
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<meeting> arr;
    int i=0;
    while(n--){
        int s,e;
        cin>>s >> e;
        i++;
        meeting m;
        m.start = s;
        m.end = e;
        m.idx = i;
        arr.push_back(m);

    }

    print_maximum_meeting(arr);
    return 0;
}