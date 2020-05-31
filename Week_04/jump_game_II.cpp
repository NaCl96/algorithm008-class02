/*
 * @Author: your name
 * @Date: 2020-05-24 08:58:20
 * @LastEditTime: 2020-05-24 09:44:24
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_04\jump_game_II.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums) {
  int min_step = 0;
  int far = 0;
  int n = nums.size();
  int end = 0;
  for(int i = 0; i < n-1; ++i){
      if(far >= i){
          far = max(far,nums[i] + i);
          if(i == end){
              end = far;
              ++min_step;
          }
      }
  }
  return min_step;
}
int main() { 
    vector<int> nums = {2,3,1,2,4,2,3}; 
    int res = jump(nums);
    return 0;
}
