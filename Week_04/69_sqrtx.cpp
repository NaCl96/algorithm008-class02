/*
 * @Author: your name
 * @Date: 2020-05-14 11:30:58
 * @LastEditTime: 2020-05-14 11:57:04
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_04\69_sqrtx.cpp
 */

#include <iostream>
using namespace std;

int mySqrt(int x) {
  if (x == 0 || x == 1) {
    return x;
  }
  int left = 1, right = x;
  int mid = 1;
  while (left <= right) {
    mid = left + (right - left) / 2;
    if (mid * mid == x) {
      return mid;
    }
    if (mid * mid < x) {
      left = mid + 1;
    } else if (mid * mid > x) {
      right = mid - 1;
    }
  }
  return right;
}

bool isPerfectSquare(int num) {
  if (num == 0 || num == 1) {
    return true;
  }
  int left = 1, right = num;
  int mid = 1;
  while (left <= right) {
    mid = left + (right - left) / 2;
    if (mid * mid == num) {
      return true;
    } else if (mid * mid > num) {
      right = mid - 1;
    } else if (mid * mid < num) {
      left = mid + 1;
    }
  }
  return false;
}

int main() {
  int x = 8;
  bool res = isPerfectSquare(x);
  cout << res;
  return 0;
}