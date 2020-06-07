/*
 * @Author: your name
 * @Date: 2020-06-03 14:42:44
 * @LastEditTime: 2020-06-03 14:52:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_07\130_surrounded_regions.cpp
 */

#include <iostream>
#include <vector>
using namespace std;

class UF {
 private:
  int count;
  vector<int> parent;
  // vector<int> size;

 public:
  UF(int n) {
    parent.resize(n);
    // size.resize(n);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
      // size[i] = 1;
    }
    count = n;
  }
  int find(int x) {
    while (parent[x] != x) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }
  void Union(int p, int q) {
    int rootp = find(p);
    int rootq = find(q);
    if (rootp == rootq) return;
    parent[rootp] = rootq;
    // if(size[rootq] > size[rootp]){
    //     parent[rootp] = rootq;
    //     size[rootq] += size[rootp];
    // }
    // else{
    //     parent[rootq] = rootp;
    //     size[rootp] += rootq;
    // }
    // count--;
  }
  bool connect(int p, int q) {
    int rootp = find(p);
    int rootq = find(q);
    return rootp == rootq;
  }
};

void solve(vector<vector<char>>& board) {
  int n = board.size();
  if (n == 0) return;
  int m = board[0].size();
  UF* uf = new UF(m * n + 1);
  int dummy = n * m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (board[i][j] == 'O') {
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
          uf->Union(dummy, i * m + j);
        } else {
          if (i > 0 && board[i - 1][j] == 'O') {
            uf->Union(i * m + j, (i - 1) * m + j);
          }
          if (i < n - 1 && board[i + 1][j] == 'O') {
            uf->Union(i * m + j, (i + 1) * m + j);
          }
          if (j > 0 && board[i][j - 1] == 'O') {
            uf->Union(i * m + j, i * m + j - 1);
          }
          if (j < m - 1 && board[i][j + 1] == 'O') {
            uf->Union(i * m + j, i * m + j + 1);
          }
        }       
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (uf->connect(i * m + j, dummy))
        continue;
      else {
        board[i][j] = 'X';
      }
    }
  }
}

int main() {
  vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                {'X', 'O', 'O', 'X'},
                                {'X', 'X', 'O', 'X'},
                                {'X', 'O', 'X', 'X'}};
  solve(board);
  return 0;
}