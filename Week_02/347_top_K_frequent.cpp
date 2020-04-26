/*
 * @Author: your name
 * @Date: 2020-04-24 10:14:34
 * @LastEditTime: 2020-04-24 11:44:53
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_02\347_top_K_frequent.cpp
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
  unordered_map<int, int> map;
  for (auto i : nums) {
    map[i]++;
  }
  vector<int> ans;
  vector<vector<int>> list(nums.size()+1);
  for (auto key : map) {
    int value = key.second;
    list[value].push_back(key.first);
  }
  for (int i = list.size()-1; i >= 0 && ans.size() < k; i--) {
    if (list[i].size() == 0) {
      continue;
    }
    for (int j = 0; j < list[i].size(); ++j) {
      ans.push_back(list[i][j]);
    }
  }
  return ans;
}

int main() {
  vector<int> nums{1};
  auto res = topKFrequent(nums, 1);
  return 0;
}