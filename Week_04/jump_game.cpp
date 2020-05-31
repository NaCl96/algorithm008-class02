/*
 * @Author: your name
 * @Date: 2020-05-24 08:38:13
 * @LastEditTime: 2020-05-24 08:39:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_04\jump_game.cpp
 */ 
#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums){
    int far = 0;
    for(int i = 0; i < nums.size(); ++i){
        if(far < i) return false;
        far = max(far,nums[i] + i);
    }
    return true;
}

int main() {
    vector<int> nums = {3,2,1,0,4};
    auto res = canJump(nums);
    return 0;
}