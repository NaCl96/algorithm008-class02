/*
 * @Author: your name
 * @Date: 2020-05-17 11:48:16
 * @LastEditTime: 2020-05-17 11:49:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_04\752_open_the_lock.cpp
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

string pluOne(string s, int j) {
  if (s[j] == '9') {
    s[j] = '0';
  } else {
    s[j] += 1;
  }
  return s;
}
string minusOne(string s, int j) {
  if (s[j] == '0') {
    s[j] = '9';
  } else {
    s[j] -= 1;
  }
  return s;
}
int openLock(vector<string>& deadends, string target) {
  set<string> visited;
  queue<string> que;
  int step = 0;
  que.push("0000");
  visited.insert("0000");

  while (!que.empty()) {
    int n = que.size();
    for (int i = 0; i < n; ++i) {
      string temp = que.front();
      que.pop();
      if (find(deadends.begin(), deadends.end(), temp) != deadends.end()) {
        continue;
      }
      if (temp == target) {
        return step;
      }

      for (int j = 0; j < 4; ++j) {
        string up = pluOne(temp, j);
        if (visited.find(up) == visited.end()) {
          que.push(up);
          visited.insert(up);
        }
        string down = minusOne(temp, j);
        if (visited.find(down) == visited.end()) {
          que.push(down);
          visited.insert(down);
        }
      }
    }
    step++;
  }
  return -1;
}

int main() {
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";
    int res = openLock(deadends,target);
    return 0;
}