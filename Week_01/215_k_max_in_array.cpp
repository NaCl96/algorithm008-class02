#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
1.利用优先级队列，即维护一个大顶堆来解决问题
2.先进行快速排序，然后选择倒数第k个数
*/

// struct cmp{
//     bool operator()(int &a,int &b){
//         return a < b;
//     }
// };

int partition(vector<int> &nums, int l, int r)
{
    int pivot = l;
    int index = pivot;
    for (int i = l + 1; i <= r; ++i)
    {
        if (nums[i] < nums[pivot])
        {
            swap(nums[++index], nums[i]);
        }
    }
    swap(nums[pivot], nums[index]);
    return index;
}

void quick(vector<int> &nums, int l, int r)
{
    if (l < r)
    {
        int x = partition(nums, l, r);
        quick(nums, l, x - 1);
        quick(nums, x + 1, r);
    }
}

int findKthLargest(vector<int> &nums, int k)
{
    quick(nums, 0, nums.size() - 1);
    int cnt = 0;
    int ans = 0;
    for (int i = nums.size() - 1; i >= 0; --i)
    {
        cnt++;
        if (cnt == k)
        {
            ans = nums[i];
        }
    }
    return ans;
    // priority_queue<int,vector<int>> q;
    // for(auto i : nums){
    //     q.push(i);
    //     if(q.size() > k){
    //         q.pop();
    //     }
    // }
    // return q.top();
}
int main()
{
    vector<int> nums{3, 2, 3, 1, 2, 4, 5, 5, 6};
    int ans = findKthLargest(nums, 4);
    cout << ans << endl;
    return 0;
}