/*
 * @Author: your name
 * @Date: 2020-06-17 15:58:27
 * @LastEditTime: 2020-06-17 15:59:16
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_09\493_reverse_pair.cpp
 */

#include <iostream>
#include <vector>
using namespace std;
int count;
void merge(vector<int>& nums, int l, int mid, int r) {
  int n1 = mid - l + 1;
  int n2 = r - mid;
  vector<int> left(n1, 0);
  vector<int> right(n2, 0);
  int i = l, j = mid + 1;
  for (i; i <= mid; ++i) {
    while (j <= r && (long)nums[i] > (long)2 * nums[j]) {
      j++;
    }
    count += j - (mid + 1);
  }
  for (int k = 0; k < n1; ++k) {
    left[k] = nums[l + k];
  }
  for (int k = 0; k < n2; ++k) {
    right[k] = nums[mid + k + 1];
  }
  int a = 0, b = 0;
  for (int k = l; k <= r; ++k) {
    if (b >= n2 || (i < n1 && left[a] <= right[b])) {
      nums[k] = left[a++];
    } else {
      nums[k] = right[b++];
    }
  }
}
void merge_sort(vector<int>& nums, int l, int r) {
  if (l < r) {
    int mid = l + (r - l) / 2;
    merge_sort(nums, l, mid);
    merge_sort(nums, mid + 1, r);
    merge(nums, l, mid, r);
  }
}
int reversePairs(vector<int>& nums) {
  if (nums.size() < 2) return 0;
  count = 0;
  merge_sort(nums, 0, nums.size() - 1);
  return count;
}
int main() {
    vector<int> nums = {1,3,2,3,1};
    int ans = reversePairs(nums);
    
    return 0;
}