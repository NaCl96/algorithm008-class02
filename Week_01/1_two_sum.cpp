#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//hash表线性时间解决
vector<int> twoSum_2(vector<int> &nums, int target){
    unordered_map<int,int> map;
    for(int i = 0; i < nums.size();++i){
        if(map.count(target-nums[i])){
            return {map[target-nums[i]],i};
        }
        map[nums[i]] = i;
    }
    return {};
}

vector<int> twoSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;
    while (i < j)
    {
        if (nums[i] + nums[j] == target)
        {
            return {i, j};
        }
        else if (nums[i] + nums[j] < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return {};
}

int main()
{
    vector<int> nums = {3,2,4};
    auto res = twoSum(nums,6);
    return 0;
}