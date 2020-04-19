#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
/* 
1.先进性排序，使用std的sort函数。
2.判断临界条件
3.声明i遍历一遍数组，作为target，注意当nums[i] > 0时结束循环。且i>0 && nums[i] == nums[i-1]时，continue操作。
4.剩下就是利用头尾指针j,k判断nums[j]+nums[k] == -taget是否成立。然后j++或者k--操作，具体看代码。
5.注意不能出现重复的组合。
*/
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp(3, -1);
    sort(nums.begin(), nums.end());
    if (nums.size() < 3 || nums[0] > 0 || nums[nums.size() - 1] < 0)
    {
        return {};
    }
   
    for (int i = 0; i < nums.size() - 2; ++i)
    {
        if (nums[i] > 0)
        {
            break;
        }
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int target = -nums[i];
        temp[0] = nums[i];
        int j = i + 1, k = nums.size() - 1;
        while (j < k)
        {
            if (nums[j] + nums[k] == target)
            {
                temp[1] = nums[j++];
                temp[2] = nums[k--];
                ans.push_back(temp);
                while (k > j && nums[k] == nums[k + 1])
                    k--;
                while (k > j && nums[j] == nums[j - 1])
                    j++;
            }
            else if (nums[j] + nums[k] < target)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return ans;
}

// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     vector<vector<int>> ans;
//     vector<int> temp(3, -1);
//     sort(nums.begin(), nums.end());
//     if (nums.size() < 3 || nums.front() > 0 || nums.back() < 0)
//     {
//         return {};
//     }
//     for (int i = 0; i < nums.size() - 2; ++i)
//     {
//         if (nums[i] > 0)
//         {
//             break;
//         }
//         if (i > 0 && nums[i] == nums[i - 1])
//         {
//             continue;
//         }
//         temp[0] = nums[i];
//         int j = i + 1, k = nums.size() - 1;
//         while (j < k)
//         {
//             if (nums[j] + nums[k] + nums[i] == 0)
//             {
//                 temp[1] = nums[j++];
//                 temp[2] = nums[k--];
//                 ans.push_back(temp);
//                 while (j < k && nums[j] == nums[j - 1])
//                     j++;
//                 while (j < k && nums[k] == nums[k + 1])
//                     k--;
//             }
//             else if (nums[j] + nums[k] > -nums[i])
//             {
//                 k--;
//             }
//             else
//             {
//                 j++;
//             }
//         }
//     }
//     return ans;
// }

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    auto res = threeSum(nums);
    return 0;
}