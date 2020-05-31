/*
 * @Author: your name
 * @Date: 2020-05-29 22:19:31
 * @LastEditTime: 2020-05-30 07:37:59
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_06\62_unique_part.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n) {
  vector<vector<int>> dp(m, vector<int>(n, 0));
  dp[m - 1][n - 2] = 1;
  dp[m - 2][n - 1] = 1;
  for (int i = m - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      if (j == n - 1 && i == m - 1) {
        continue;
      } else if (j == n - 1) {
        dp[i][j] = dp[i + 1][j];
      } else if (i == m - 1) {
        dp[i][j] = dp[i][j + 1];
      } else {
        dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
      }
    }
  }
  return dp[0][0];
}

int uniquePaths_2(int m, int n){
  vector<int> cur(n,1);
  for(int i = 1; i < m; ++i){
    for(int j = 1;j < n; ++j){
      cur[j] += cur[j-1];
    }
  }
  return cur[n-1];
}

int main() {
  int res = uniquePaths_2(3, 2);
  cout << res;
  return 0;
}