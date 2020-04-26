/*
 * @Author: your name
 * @Date: 2020-04-26 11:25:01
 * @LastEditTime: 2020-04-26 17:27:14
 * @LastEditors: Please set LastEditors
 * @Description: 75. 颜色分类
 * @FilePath: \algorithm008-class02\Week_02\75_color_category.cpp
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
  unordered_map<int, int> map;
  for (auto i : nums) {
    map[i]++;
  }
  int cnt_r = map[0];
  int cnt_w = map[1];
  int cnt_b = map[2];
  for (int i = 0; i < nums.size(); ++i) {
    if (cnt_r--) {
      nums[i] = 0;
      continue;
    }
    if (cnt_w--) {
      nums[i] = 1;
      continue;
    }
    if (cnt_b--) {
      nums[i] = 2;
      continue;
    }
  }
}

void sortColors_2(vector<int>& nums) {
  int first = 0, second = 1, last = nums.size() - 1;
  for (second; second < last;) {
    if (nums[second] == 0) {
      swap(nums[first++], nums[second]);
    } 
    if (nums[second] == 2) {
      swap(nums[second], nums[last--]);
    } 
    if(nums[second] == 1){
        
    }
    second++;
  }
}
int main() {
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  sortColors_2(nums);
  return 0;
}