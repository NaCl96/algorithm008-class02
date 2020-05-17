/*
 * @Author: your name
 * @Date: 2020-05-16 08:12:34
 * @LastEditTime: 2020-05-16 08:33:36
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_04\875_koko_eating_bananas.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

int getMax(vector<int>& piles) {
  int mx = 0;
  for (auto n : piles) {
    mx = n > mx ? n : mx;
  }
  return mx;
}
bool canFinish(vector<int>& piles, int num, int H) {
  int cur = 0;
  for (auto n : piles) {
    cur += n / num;
    cur += n % num == 0 ? 0 : 1;
  }
  return cur <= H;
}
int minEatingSpeed(vector<int>& piles, int H) {
  int left = 1;
  int right = getMax(piles);
  int mid = 0;
  while (left <= right) {
    mid = left + (right - left) / 2;
    if (canFinish(piles, mid, H)) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return left;
}
int main() {
    vector<int> piles{30,11,23,4,20};
    int H = 6;
    int res = minEatingSpeed(piles,H);
    return 0;
}