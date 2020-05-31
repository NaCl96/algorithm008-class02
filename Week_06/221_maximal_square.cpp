/*
 * @Author: your name
 * @Date: 2020-05-30 14:16:50
 * @LastEditTime: 2020-05-30 16:46:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_06\221_maximal_square.cpp
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
  if (matrix.size() == 0 || matrix[0].size() == 0) {
    return 0;
  }
  int raws = matrix.size();
  int cols = matrix[0].size();
  int maxSide = 0;
  for (int i = 0; i < raws; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (matrix[i][j] == '1') {
        maxSide = max(1, maxSide);
        int curMax = min(raws - i, cols - j);
        for (int k = 1; k < curMax; ++k) {
          bool flag = true;
          if (matrix[i + k][j + k] == '0') {
            break;
          }
          for (int m = 0; m < k; ++m) {
            if (matrix[i + k][j + m] == '0' || matrix[i + m][j + k] == '0') {
              flag = false;
              break;
            }
          }
          if (flag) {
            maxSide = max(maxSide, 1);
          } else {
            break;
          }
        }
      }
    }
  }
  int res = maxSide * maxSide;
  return res;
}

int maximalSquare_2(vector<vector<char>>& matrix) {
  if (matrix.size() == 0 || matrix[0].size() == 0) {
    return 0;
  }
  int rows = matrix.size();
  int cols = matrix[0].size();
  int maxSide = 0;
  vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (matrix[i][j] == '1') {
        dp[i + 1][j + 1] = min(min(dp[i + 1][j], dp[i][j + 1]), dp[i][j]) + 1;
        maxSide = max(maxSide, dp[i + 1][j + 1]);
      }
    }
  }
  return maxSide * maxSide;
}

int maximalSquare_3(vector<vector<char>>& matrix) {
  if (matrix.size() == 0 || matrix[0].size() == 0) {
    return 0;
  }
  int row = matrix.size();
  int cols = matrix[0].size();
  // vector<vector<int>> dp(row+1,vector<int>(col+1,0));
  vector<int> dp(cols + 1, 0);
  int maxSide = 0;
  int northest = 0;
  for (auto chars : matrix) {
    northest = 0;
    for (int col = 0; col < cols; ++col) {
      int nextNorthest = dp[col + 1];
      if (chars[col] == '1') {
        dp[col + 1] = min(min(dp[col], dp[col + 1]), northest) + 1;
        maxSide = max(maxSide, dp[col + 1]);
      } else {
        dp[col + 1] = 0;
      }
      northest = nextNorthest;
    }
  }
  return maxSide * maxSide;
}

int main() {
  vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                 {'1', '0', '1', '1', '1'},
                                 {'1', '1', '1', '1', '1'},
                                 {'1', '0', '0', '1', '0'}};
  int res = maximalSquare_3(matrix);
  cout << "res:" << res << endl;
  return 0;
}
