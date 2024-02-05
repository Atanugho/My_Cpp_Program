
#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;


int leastInterval(vector<char> tasks, int n){

    unordered_map<char,int> taskFreq;
    for(auto t:tasks){
        taskFreq[t]++;
    }

    priority_queue<int> pq;

    for(auto e:taskFreq){
        pq.push(e.second);

    }

    //finding time until pq is empty

    int totalTime = 0;
    while(!pq.empty()){

        vector<int> temp;
        for(int i =0 ;i<=n;i++){
            if(!pq.empty()){
                int freq = pq.top();
                pq.pop();

                if(freq > 1){
                    temp.push_back(freq-1);
                }
            }

            totalTime++;

            if(pq.empty() && temp.empty()){
                return totalTime;
            }
        }

        for(auto t:temp){
            pq.push(t);
        }
    }

    return totalTime;
}

int main(){

vector<char> tasks = {'A','A','A','B','B','B'};
int coolDown  = 2;

int leastTime = leastInterval(tasks,coolDown);
cout<<"Least number of units of time:"<<leastTime<<endl;

return 0;

}