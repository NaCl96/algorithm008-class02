#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 
方法一:
类似三数之和，又加了一层循环。
增添了几个判别条件。
 */
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    if (nums.size() < 4)
    {
        return {};
    }
    vector<vector<int>> ans;
    vector<int> temp(4, -1);
    for (int i = 0; i < nums.size() - 3; ++i)
    {
        if (target < 0 && nums[i] > 0)
        {
            break;
        }
        if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
        {
            break;
        }
        if (nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3] < target)
        {
            continue;
        }
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        temp[0] = nums[i];
        for (int j = i + 1; j < nums.size() - 2; ++j)
        {
            if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
            {
                break;
            }
            if (nums[i] + nums[j] + nums[nums.size() - 1] + nums[nums.size() - 2] < target)
            {
                continue;
            }
            if (j > i+1 && nums[j] == nums[j - 1])
                continue;
            temp[1] = nums[j];
            int k = j + 1;
            int r = nums.size() - 1;
            while (k < r)
            {
                if (nums[i] + nums[j] + nums[k] + nums[r] == target)
                {
                    temp[2] = nums[k++];
                    temp[3] = nums[r--];
                    if (find(ans.begin(), ans.end(), temp) == ans.end())
                    {
                        ans.push_back(temp);
                        while (k < r && nums[k] == nums[k - 1])
                            k++;
                        while (k < r && nums[r] == nums[r + 1])
                            r--;
                    }
                }
                else if (nums[i] + nums[j] + nums[k] + nums[r] > target)
                {
                    r--;
                }
                else
                {
                    k++;
                }
            }
        }
    }
    return ans;
}

/* 
方法二：尝试使用深度优先遍历来解
 */

void dfs(vector<int> &nums, int index, int target, int n, vector<int> &temp, vector<vector<int>> &ans)
{
    if (n == 2)
    {
        int l = index;
        int r = nums.size() - 1;
        while (l < r)
        {
            int sum = nums[l] + nums[r];
            if (sum == target)
            {
                temp.push_back(nums[l++]);
                temp.push_back(nums[r--]);
                ans.push_back(temp);
                temp.pop_back();
                temp.pop_back();
                while (l < r && nums[l] == nums[l - 1])
                    l++;
                while (l < r && nums[r] == nums[r + 1])
                    r--;
            }
            else if (sum < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return;
    }

    for (int i = index; i < nums.size() - n + 1; ++i)
    {
        if (nums[i] * n > target && nums[nums.size() - 1]*n < target)
        {
            break;
        }
        if (i > index && nums[i] == nums[i - 1]){
            continue;
        }
        temp.push_back(nums[i]);
        dfs(nums, i + 1, target - nums[i], n - 1, temp, ans);
        temp.pop_back();
        // i++;
    }
}

vector<vector<int>> fourSum_dfs(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    sort(nums.begin(), nums.end());

    if (nums.size() < 4)
    {
        return {};
    }

    dfs(nums, 0, target, 4, temp, ans);
    return ans;
}

int main()
{
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    auto res = fourSum(nums, target);
    return 0;
}