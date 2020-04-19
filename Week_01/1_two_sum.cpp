#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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