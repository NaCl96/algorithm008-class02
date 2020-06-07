/*
 * @Author: your name
 * @Date: 2020-06-07 16:57:37
 * @LastEditTime: 2020-06-07 19:02:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_07\shortest-path-in-binary-matrix.cpp
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> direct = {{1, 0}, {-1, 0}, {0, 1},{0, -1},
                              {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
  int n = grid.size();
  if (n == 0) return -1;
  if (grid[0][0] == 1) return -1;
  if (n == 1 && grid[0][0] == 0) return 1;
  queue<pair<int, int>> que;
  vector<int> visited(n * n, 0);
  int res = 0;
  que.push({0, 0});
  visited[0] = 1;
  while (!que.empty()) {
    int m = que.size();
    res++;
    for (int i = 0; i < m; ++i) {
      auto cur = que.front();
      que.pop();
      int cur_i = cur.first;
      int cur_j = cur.second;
      if (cur_i == (n - 1) && cur_j == (n - 1)) return res;

      for (int j = 0; j < 8; ++j) {
        int new_i = cur_i + direct[j][0];
        int new_j = cur_j + direct[j][1];

        if (new_i < 0 || new_j < 0 || new_i >= n || new_j >= n) continue;

        if (visited[new_i * n + new_j] == 1) continue;

        if (grid[new_i][new_j] == 1) continue;

        visited[new_i * n + new_j] = 1;
        que.push({new_i, new_j});
      }
    }
  }
  return -1;
}
// int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//   int n = grid.size();
//   if (n == 0) return 0;
//   if (grid[0][0] == 1) return 0;
//   queue<pair<int, int>> que;
//   vector<int> visited(n * n, 0);
//   int res = 1;
//   que.push({0, 0});
//   while (!que.empty()) {
//     int m = que.size();
//     res++;
//     for (int i = 0; i < m; ++i) {
//       auto cur = que.front();
//       que.pop();
//       int cur_i = cur.first;
//       int cur_j = cur.second;
//       visited[cur_i * n + cur_j] = 1;
//       for (int j = 0; j < 8; ++j) {
//         int new_i = cur_i + direct[j][0];
//         int new_j = cur_j + direct[j][1];
//         if (new_i >= 0 && new_j >= 0 && new_i < n && new_j < n &&
//             visited[new_i * n + new_j] == 0 && grid[new_i][new_j] == 0) {
//           que.push({new_i, new_j});
//         }
//       }
//     }
//   }
//   return res;
// }

int main() {
  vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
  int res = shortestPathBinaryMatrix(grid);
  cout << res << endl;
  return 0;
}