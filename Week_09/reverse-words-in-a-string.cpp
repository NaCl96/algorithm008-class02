/*
 * @Author: your name
 * @Date: 2020-06-22 09:55:20
 * @LastEditTime: 2020-06-22 09:56:42
 * @LastEditors: Please set LastEditors
 * @Description: 151. 翻转字符串里的单词
 * @FilePath: \algorithm008-class02\Week_09\reverse-words-in-a-string.cpp
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string reverseWords(string s) {
  int n = s.size();
  if (n == 0) {
    return "";
  }
  reverse(s.begin(), s.end());
  int idx = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != ' ') {
      if (idx != 0) {
        s[idx++] = ' ';
      }
      int end = i;
      while (end < n && s[end] != ' ') {
        s[idx++] = s[end++];
      }
      reverse(s.begin() + idx - (end - i), s.begin() + idx);
      i = end;
    }
  }
  s.erase(s.begin() + idx, s.end());
  return s;
}
int main() {
    string s = "the sky is blue";
    string res = reverseWords(s);

    cout<<res;
    return 0;
}