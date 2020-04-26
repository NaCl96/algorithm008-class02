/*
 * @Author: your name
 * @Date: 2020-04-14 11:13:15
 * @LastEditTime: 2020-04-23 10:13:40
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_01\66_plus_one.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

//本人思路，代码有点繁琐，看着不太简介
vector<int> plusOne(vector<int> &digits) {
  // vector<int> ans;
  bool flag = false;
  int n = digits.size();
  if (digits[n - 1] < 9) {
    ++digits[n - 1];
    return digits;
  } else {
    digits[n - 1] = 0;
    if (n < 2) {
      flag = true;
    } else {
      for (int i = digits.size() - 2; i >= 0; --i) {
        if (digits[i] < 9) {
          digits[i] += 1;
          break;
        } else if (i > 0) {
          digits[i] = 0;
          continue;
        } else if (i == 0) {
          digits[i] = 0;
          flag = true;
        }
      }
    }
  }
  if (flag) {
    vector<int> ans(digits.size() + 1, 1);
    for (int i = 1; i < ans.size(); ++i) {
      ans[i] = digits[i - 1];
    }
    return ans;
  }
  return digits;
}

//思路二：参考最优解题过程,单独对首位进行判断，代码相当简洁。
vector<int> plusOne_best(vector<int> &digits) {
  int n = digits.size();
  for (int i = n - 1; i >= 0; --i) {
    if (digits[i] < 9) {
      ++digits[i];
      return digits;
    } else if (i == 0) {
      digits[i] = 1;
      digits.push_back(0);
    } else {
      digits[i] = 0;
    }
  }
  return digits;
}
int main() {
  vector<int> digits{9, 9, 9};
  auto res = plusOne_best(digits);
  return 0;
}