/*
 * @Author: your name
 * @Date: 2020-05-13 09:16:13
 * @LastEditTime: 2020-05-13 09:18:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_04\455_assign_cookies.cpp
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
  if (g.empty() || s.empty()) {
    return 0;
  }
  int ans = 0;
  sort(g.begin(), g.end());
  sort(s.begin(), s.end());
  if(g[0] > s[s.size()-1]){
      return 0;
  }
  if (g[g.size() - 1] < s[0]) {
    return g.size();
  }
  int i = 0, j = 0;
  for (; i < g.size(); ++i) {
    for (; j < s.size(); ++j) {
      if (g[i] <= s[j]) {
        ans++;
        j++;
        break;
      }
    }
  }
  return ans;
}

int main() {
    vector<int> g = {1,2,3};
    vector<int> s = {1,2};
    int res = findContentChildren(g,s);
    cout<<res;
    return 0;
}