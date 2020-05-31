/*
 * @Author: your name
 * @Date: 2020-05-31 10:29:12
 * @LastEditTime: 2020-05-31 11:07:25
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_06\1143_LCS.cpp
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//思路一：二维dp动态求解
int longestCommonSubsequence(string text1, string text2) {
  int n = text1.size();
  int m = text2.size();
  //这里增添了空串的情况，方便处理。
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < m + 1; ++j) {
      if (text1[i - 1] == text2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[n][m];
}

//思路二：压缩到一维数组，动态求解。
int longestCommonSubsequence_2(string text1, string text2) {
  int n = text1.size();
  int m = text2.size();
  vector<int> dp(m + 1, 0);

  int temp = 0;
  for (int i = 1; i < n + 1; ++i) {
    int last = 0;
    for (int j = 1; j < m + 1; ++j) {
        temp = dp[j];
        if(text1[i-1] == text2[j-1]){
            dp[j] = last + 1;
        }
        else{
            dp[j] = max(temp,dp[j-1]);
        }
        last = temp;
    }
  }
  return dp[m];
}

int main() {
  string text1 = "abcde";
  string text2 = "ace";
  int res = longestCommonSubsequence_2(text1, text2);
  cout << "res:" << res << endl;
  return 0;
}