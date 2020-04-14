#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums){
    int j = 0;
    for (int i = 0; i < nums.size();++i){
        //方法一：swap交换
        if(nums[i] != 0){
            swap(nums[i],nums[j++]);
        }
        //方法二：更新值，两种方法本质一样
        // if(nums[i] != 0){
        //     nums[j++] = nums[i];
        //     if(i != j){
        //         nums[i] = 0;
        //     }
        // }
    }
}

int main(){
    vector<int> nums = {0,1,3,0,12,5,0,6};
    moveZeroes(nums);
    return 0;
}