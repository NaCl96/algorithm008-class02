/*
 * @Author: your name
 * @Date: 2020-04-19 15:40:50
 * @LastEditTime: 2020-04-26 09:19:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_01\42_trapping_rain_water.cpp
 */
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int trap(vector<int> &heights) {
  stack<int> stk;
  int mx = 0;
  for (int i = 0; i < heights.size(); ++i) {
    while (!stk.empty() && heights[i] > heights[stk.top()]) {
      int cur = stk.top();
      stk.pop();
      if (stk.empty()) {
        break;
      }
      int left = stk.top();
      int right = i;
      int h = min(heights[left], heights[right]) - heights[cur];
      mx += h * (right - left - 1);
    }
    stk.push(i);
  }
  return mx;
}
int trap_2(vector<int> &heights) {
  if (heights.size() == 0) {
    return 0;
  }
  int n = heights.size();
  int sum = 0;
  vector<int> left(n, 0);
  vector<int> right(n, 0);

  for (int i = 1; i < n - 1; ++i) {
    left[i] = max(left[i - 1], heights[i - 1]);
  }
  for (int j = n - 2; j >= 0; --j) {
    right[j] = max(right[j + 1], heights[j + 1]);
  }
  for (int k = 0; k < n; ++k) {
    int min_height = min(left[k], right[k]);
    if (min_height > heights[k]) {
      sum += min_height - heights[k];
    }
  }
  return sum;
}
int main() {
  vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int res = trap(heights);
  return 0;
}