#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* 
思路一：从当前下标向两端寻找，这里使用两个数组left_vec,right_vec来存储左右两边已经知道最小高度的值，用来优化。
 */
int largestRectangleArea(vector<int> &heights)
{
    if (heights.size() == 0)
    {
        return 0;
    }
    int mx = 0;
    int n = heights.size();
    vector<int> left_vec(n, 0);
    vector<int> right_vec(n, 0);
    left_vec[0] = -1;
    right_vec[n - 1] = n;
    for (int i = 1; i < heights.size(); ++i)
    {
        int left_bount = i - 1;
        while (left_bount >= 0 && heights[left_bount] > heights[i])
        {
            left_bount = left_vec[left_bount];
        }
        left_vec[i] = left_bount;
    }
    for (int i = heights.size() - 2; i >= 0; --i)
    {
        int right_bound = i + 1;
        while (right_bound < n && heights[right_bound] > heights[i])
        {
            right_bound = right_vec[right_bound];
        }
        right_vec[i] = right_bound;
    }
    for (int i = 0; i < heights.size(); ++i)
    {
        mx = max(mx, (right_vec[i] - left_vec[i] - 1) * heights[i]);
    }
    return mx;
}

/* 
思路二：维护一个单调递增的栈^
 */
int largestRectangleArea_2(vector<int> &heights)
{
    if (heights.size() == 0)
    {
        return 0;
    }
    if (heights.size() == 1)
    {
        return heights[0];
    }
    stack<int> stk;
    int mx = 0;
    for (int i = 0; i < heights.size(); ++i)
    {
        while (!stk.empty() && heights[stk.top()] > heights[i])
        {
            int cur = stk.top();
            stk.pop();
            while (!stk.empty() && heights[stk.top()] == heights[cur])
            {
                stk.pop();
            }
            int width;
            if (stk.empty())
            {
                width = i;
            }
            else
            {
                width = i - stk.top() - 1;
            }
            mx = max(mx, width * heights[cur]);
        }
        stk.push(i);
    }

    while(!stk.empty()){
        int cur = stk.top();
        stk.pop();
        while (!stk.empty() && heights[stk.top()] == cur)
        {   
            stk.pop();
        }
        int cur_width;
        if(stk.empty()){
            cur_width = heights.size();
        }
        else{
            cur_width = heights.size() - stk.top()-1;
        }
        mx = max(mx,cur_width * heights[cur]);
    }
    return mx;
}

int main()
{
    vector<int> heights = {2,1,5,6,2,3};
    int res = largestRectangleArea(heights);
    cout << res;
    return 0;
}