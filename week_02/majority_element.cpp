/*
 * @Author: your name
 * @Date: 2020-05-23 15:44:12
 * @LastEditTime: 2020-05-23 15:52:00
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\week_02\majority_element.cpp
 */ 

#include <iostream>
#include <vector>

using namespace std; 

int majorityElement(vector<int>& nums){
    int candidate = -1;
    int count = 0;
    for(int num : nums){
        if(num == candidate){
            ++count;
        }else if(--count < 0){
            candidate = num;
            count = 1;
        }
    }
    return candidate;
}

int main(){
    vector<int> nums = {2,2,1,1,1,2,2};
    int res = majorityElement(nums);
    cout << res;
    return 0;
}