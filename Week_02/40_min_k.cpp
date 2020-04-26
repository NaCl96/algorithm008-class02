/*
 * @Author: your name
 * @Date: 2020-04-26 10:53:46
 * @LastEditTime: 2020-04-26 11:06:22
 * @LastEditors: Please set LastEditors
 * @Description: leetcode 面试题40 --最小的k个数
 * @FilePath: \algorithm008-class02\Week_02\40_min_k.cpp
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//方法一 ：大顶堆
vector<int> getLeastNumbers(vector<int>& arr, int k) {
  vector<int> ans;
  priority_queue<int, vector<int>> que;
  for (auto i : arr) {
    que.push(i);
    if (que.size() > k) {
      que.pop();
    }
  }

  while (!que.empty()) {
    ans.push_back(que.top());
    que.pop();
  }
  return ans;
}


//方法二 ：快速选择
int partition(vector<int>& arr,int l,int r){
    int pivot = l;
    int index = pivot;
    for(int i = l+1;i <= r;++i){
        if(arr[i] < arr[pivot]){
            swap(arr[++index],arr[i]);
        }
    }
    swap(arr[pivot],arr[index]);
    return index;
}

void partitionArr(vector<int>& arr,int l, int r,int k){
    int x = partition(arr,l,r);
    if(k == x){
        return;
    }
    else if(k < x){
        partitionArr(arr,l,x-1,k);
    }
    else if(k > x){
        partitionArr(arr,x+1,r,k);
    }
}

vector<int> getLeastNumbers_2(vector<int> &arr,int k){
    if(k == 0){
        return {};
    }
    else if(k >= arr.size()){
        return arr;
    }
    partitionArr(arr,0,arr.size()-1,k);
    vector<int> ans(k,0);
    for(int i = 0; i < k;++i){
        ans[i] = arr[i];
    }
    return ans;
}

int main() { 
    
    return 0; }