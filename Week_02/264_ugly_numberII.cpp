/*
 * @Author: your name
 * @Date: 2020-04-24 11:45:19
 * @LastEditTime: 2020-04-25 10:04:33
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_02\264_ugly_numberII.cpp
 */

#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * @description: 小顶堆法，优先级队列
 * @param {type}
 * @return:
 */
int nthUglyNumber(int n) {
  priority_queue<int, vector<int>, greater<int>> pri_que;
  int cur = 1;
  for (int i = 1; i < n; ++i) {
    pri_que.push(cur * 2);
    pri_que.push(cur * 3);
    pri_que.push(cur * 5);
    cur = pri_que.top();
    pri_que.pop();
    while (!pri_que.empty() && cur == pri_que.top()) {
      pri_que.pop();
    }
  }
  return cur;
}

/**
 * @description: 动态规划
 * @param {type}
 * @return:
 */
int nthUglyNumber_2(int n) {
  vector<int> dp(n);
  dp[0] = 1;
  int p_2, p_3, p_5;
  p_2 = 0, p_3 = 0, p_5 = 0;
  for (int i = 1; i < n; ++i) {
    dp[i] = min(min(dp[p_2] * 2, dp[p_3] * 3), dp[p_5] * 5);
    if (dp[i] == dp[p_2] * 2) p_2++;
    if (dp[i] == dp[p_3] * 3) p_3++;
    if (dp[i] == dp[p_5] * 5) p_5++;
  }
  return dp[n - 1];
}

int main() {
  int res = nthUglyNumber_2(11);
  vector<int> mask({2, 3, 5});
  for (auto i : mask) {
    cout << i;
  }
  return 0;
}