/*
 * @Author: your name
 * @Date: 2020-05-06 19:27:31
 * @LastEditTime: 2020-05-06 19:37:43
 * @LastEditors: Please set LastEditors
 * @Description: 扫雷游戏
 * @FilePath: \algorithm008-class02\Week_03\529_minesweeper.cpp
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                 vector<int>& click) {
  int i = click[0];
  int j = click[1];
  int m = board.size();
  int n = board[0].size();
  if (board[i][j] == 'M') {
    board[i][j] = 'X';
    return board;
  }
  vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                                    {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  vector<vector<int>> adj(m, vector<int>(n, 0));
  for (int k = 0; k < m; ++k) {
    for (int l = 0; l < n; ++l) {
      if (board[k][l] == 'M' || board[k][l] == 'X') {
        for (auto dir : directions) {
          int x = k + dir[0];
          int y = l + dir[1];
          if (x >= 0 && x < m && y >= 0 && y < n) {
            ++adj[x][y];
          }
        }
      }
    }
  }

  if (adj[i][j] > 0) {
    board[i][j] = adj[i][j] + '0';
    return board;
  }
  queue<pair<int, int>> q;
  board[i][j] = 'B';
  q.push({i, j});
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    int x = p.first;
    int y = p.second;
    for (auto dir : directions) {
      int new_x = x + dir[0];
      int new_y = y + dir[1];
      if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) {
        if (adj[new_x][new_y] > 0) {
          board[new_x][new_y] = '0' + adj[new_x][new_y];
        } else if (board[new_x][new_y] == 'E') {
          board[new_x][new_y] = 'B';
          q.push({new_x, new_y});
        }
      }
    }
  }
  return board;
}

int main() {
  vector<vector<char>> board = {{'E', 'E', 'E', 'E', 'E'},
                                {'E', 'E', 'M', 'E', 'E'},
                                {'E', 'E', 'E', 'E', 'E'},
                                {'E', 'E', 'E', 'E', 'E'}};
  vector<int> click{3, 0};
  auto res = updateBoard(board, click);

  return 0;
}