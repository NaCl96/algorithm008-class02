/*
 * @Author: your name
 * @Date: 2020-05-22 16:48:07
 * @LastEditTime: 2020-05-22 17:11:19
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_06\minimun_window_substring.cpp
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string minWindow(string s, string t) {
  unordered_map<char, int> need, windows;
  for (auto c : t) {
    need[c]++;
  }
  int left = 0, right = 0;
  int isvalid = 0;
  int start = 0, len = INT_MAX;
  while (right < s.size()) {
    char c = s[right];
    right++;

    if (need.count(c)) {
      windows[c]++;
      if (windows[c] == need[c]) {
        isvalid++;
      }
    }

    while (isvalid == need.size()) {
      if (right - left < len) {
        start = left;
        len = right - left;
      }
      char d = s[left++];
      if (need.count(d)) {
        if (windows[d] == need[d]) isvalid--;
        windows[d]--;
      }
    }
  }
  return len == INT_MAX ? "" : s.substr(start, len);
}

bool checkInclusion(string s1, string s2) {
  unordered_map<char, int> need, window;
  for (auto c : s1) {
    need[c]++;
  }
  int left = 0, right = 0;
  int valid = 0;

  while (right < s2.size()) {
    char c = s2[right];
    right++;
    if (need.count(c)) {
      window[c]++;
      if (window[c] == need[c]) {
        valid++;
      }
    }

    while (right - left >= s1.size()) {
Z