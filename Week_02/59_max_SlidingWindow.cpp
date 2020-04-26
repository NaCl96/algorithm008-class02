#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    if (nums.size() == 0 || k < 1 || nums.size() < k)
    {
        return {};
    }
    deque<int> que;
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i)
    {
        while (!que.empty() && nums[que.back()] <= nums[i])
        {
            que.pop_back();
        }
        que.push_back(i);
        if (que.front() == (i - k))
        {
            que.pop_front();
        }
        if (i >= (k - 1))
        {
            res.push_back(nums[que.front()]);
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    auto ans = maxSlidingWindow(nums,3);
    cout<<endl;
    return 0;
}