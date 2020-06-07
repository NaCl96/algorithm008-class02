/*
 * @Author: your name
 * @Date: 2020-06-03 08:15:56
 * @LastEditTime: 2020-06-03 08:32:29
 * @LastEditors: Please set LastEditors
 * @Description: 并查集
 * @FilePath: \algorithm008-class02\Week_07\friend_circles.cpp
 */

#include <iostream>
#include <vector>
using namespace std;

class UF {
 private:
  int count;
  vector<int> parent;
  vector<int> size;

 public:
  UF(int n) {
    count = n;
    parent.resize(n);
    size.resize(n);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int find(int x) {
    while (parent[x] != x) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }
  void Union(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    if (rootQ == rootP) {
      return;
    }
    if (size[rootP] > size[rootQ]) {
      parent[rootQ] = rootP;
      size[rootP] += size[rootQ];
    } else {
      parent[rootP] = rootQ;
      size[rootQ] += size[rootP];
    }
    count--;
  }

  bool connected(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    return rootQ == rootP;
  }

  int getCount() const { return count; }
};
