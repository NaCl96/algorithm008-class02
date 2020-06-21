/*
 * @Author: your name
 * @Date: 2020-06-17 17:19:40
 * @LastEditTime: 2020-06-17 17:21:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_09\887_super-egg-drop.cpp
 */

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> memo;
int dp(int K, int N) {
  if (K == 1) return N;
  if (N == 0) return 0;
  if (memo[K - 1][N - 1] != 0) return memo[K - 1][N - 1];

  int min_cur = INT_MAX;
  for (int i = 1; i < N + 1; ++i) {
    min_cur = min(min_cur, max(dp(K, N - i), dp(K - 1, i - 1))) + 1;
  }
  memo[K - 1][N - 1] = min_cur;
  return memo[K - 1][N - 1];
}
int superEggDrop(int K, int N) {
  if (K == 1) return N;
  if (N == 0) return 0;
  memo = vector<vector<int>>(K, vector<int>(N, 0));
  int res = dp(K, N);
  return res;
}
int main() {
    int ans = superEggDrop(2,6);
    cout<<ans;
    return 0;
}