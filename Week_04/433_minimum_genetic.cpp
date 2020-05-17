/*
 * @Author: your name
 * @Date: 2020-05-11 14:32:57
 * @LastEditTime: 2020-05-11 14:59:32
 * @LastEditors: Please set LastEditors
 * @Description: 433. 最小基因变化
 * @FilePath: \algorithm008-class02\Week_04\433_minimum_genetic.cpp
 */

#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int minMutation(string start, string end, vector<string>& bank) {
    if(start.empty() || end.empty() || bank.empty()){
        return -1;
    }
    queue<string> que;
    que.push(start);
    vector<int> visited(bank.size(),0);
    int ans = 0;
    while(!que.empty()){
        ans++;
        for(int i = que.size()-1;i >= 0; --i){
            string temp = que.front();
            que.pop();
            for(int j = 0;j < bank.size();++j){
                if(visited[j] == 0){
                    int diff = 0;
                    for(int k = 0;k < temp.size(); ++k){
                        if(temp[k] != bank[j][k]) diff++;
                    }
                    if(diff == 1){
                        if(bank[j] == end) return ans;
                        visited[j] = 1;
                        que.push(bank[j]);
                    }
                }
            }
        }
    }
    return -1;
}

int main() { 
    string start = "AAAAACCC";
    string end = "AACCCCCC";
    vector<string> bank = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
    int res = minMutation(start,end,bank);
    cout<<res;
    return 0; }