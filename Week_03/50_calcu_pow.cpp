/*
 * @Author: your name
 * @Date: 2020-04-30 10:10:22
 * @LastEditTime: 2020-04-30 13:44:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_03\50_calcu_pow.cpp
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

double calcu_pow(double x, long long N) {
  if (N == 0) {
    return 1.0;
  }
  double half = calcu_pow(x, N / 2);
  if (N % 2 == 0) {
    return half * half;
  } else {
    return half * half * x;
  }
}

double myPow(double x, int n) {
  long long N = n;
  if (N < 0) {
    x = 1 / x;
    N = -N;
  }
  return calcu_pow(x, N);
}

double myPow_2(double x, int n) {
  int temp = n;
  double ans = 1;
  while (n != 0) {
    if ((n & 1) != 0) {
      ans = ans * x;
    }
    x = x * x;
    // n /= 2;
    n >>= 1;
  }
  return temp > 0 ? ans : 1 / ans;
}

vector<string> split(string& data) {
  int start = 0;
  vector<string> res;
  while(1){
    auto end = data.find(',',start);
    if(end == string::npos) break;
    res.push_back(data.substr(start,end-start));
    start = end + 1;
  }
  return move(res);
}

int main() {
  double x = 2.0;
  int n = 10;
  string data = "12,42,1,4,5,7";
  auto res = split(data);
  //   int end = n & 1;
  // double res = myPow_2(x, n);
  // cout << res;
  return 0;
}