/*
 * @Author: your name
 * @Date: 2020-05-12 09:48:44
 * @LastEditTime: 2020-05-12 10:07:35
 * @LastEditors: Please set LastEditors
 * @Description: 200. 岛屿数量
 * @FilePath: \algorithm008-class02\Week_04\200_number_of_islands.cpp
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> direction {{1,0},{0,1},{-1,0},{0,-1}};

void find_area(int i, int j, vector<vector<char>>& grid,
               vector<vector<bool>>& visited) {
  for (auto dir : direction) {
    int new_i = i + dir[0];
    int new_j = j + dir[1];
    if (new_i >= 0 && new_i < grid.size() && new_j >= 0 &&
        new_j < grid[0].size() && grid[new_i][new_j] == '1' &&
        !visited[new_i][new_j]) {
      visited[new_i][new_j] = true;
      find_area(new_i, new_j, grid, visited);
    }
  }
}

int numIslands(vector<vector<char>>& grid) {
  int n = grid.size();
  int m = grid[0].size();
  int ans = 0;
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '1' && visited[i][j]==false) {
        visited[i][j] = true;
        find_area(i, j, grid, visited);
        ans++;
      }
    }
  }
  return ans;
}

int main() {
    
    vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    int res = numIslands(grid);
    cout<<res;

}