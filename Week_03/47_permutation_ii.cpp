/*
 * @Author: your name
 * @Date: 2020-05-08 09:32:43
 * @LastEditTime: 2020-05-08 09:59:44
 * @LastEditors: Please set LastEditors
 * @Description: 全排列II
 * @FilePath: \algorithm008-class02\Week_03\47_permutation_ii.cpp
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void trackBack(vector<vector<int>>& ans, vector<int>& cur, vector<int>& nums,
               vector<bool> visited) {
  if (cur.size() == nums.size()) {
    ans.push_back(cur);
    return;
  }
  for (int j = 0; j < nums.size(); ++j) {
    if (visited[j]) {
      continue;
    }
    if (j > 0 && nums[j] == nums[j - 1] && visited[j - 1]) {
      continue;
    }
    cur.push_back(nums[j]);
    visited[j] = true;
    trackBack(ans, cur, nums, visited);
    cur.pop_back();
    visited[j] = false;
  }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
  vector<vector<int>> ans;
  vector<int> cur;
  vector<bool> visited(nums.size(), false);
  sort(nums.begin(), nums.end());
  trackBack(ans, cur, nums, visited);
  return ans;
}

int main() {
  vector<int> nums = {1, 1, 2};
  auto res = permuteUnique(nums);
  return 0;
}
