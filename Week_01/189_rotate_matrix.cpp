#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int> &nums, int k)
{
    //如果移动的k是0，或者nums长度的倍数时，不需要移动
    if (k % nums.size() == 0)
    {
        return;
    }
    k = k % nums.size();
    int count = 0;
    for (int start = 0; start < nums.size(); ++start)
    {
        int cur = start;
        int pre = nums[cur];
        if (count == nums.size())
            break;
        do
        {
            int index = (k + cur) % nums.size();
            int temp = nums[index];
            nums[index] = pre;
            cur = index;
            pre = temp;
            count++;
        } while (start != cur);
    }
    return;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6,7};
    rotate(nums, 3);
    for (auto i : nums)
    {
        cout << i << " ";
    }
    return 0;
}