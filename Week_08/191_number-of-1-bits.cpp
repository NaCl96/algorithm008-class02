/*
 * @Author: your name
 * @Date: 2020-06-08 08:13:35
 * @LastEditTime: 2020-06-08 16:40:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_08\191_number-of-1-bits.cpp
 */

#include <iostream>

using namespace std;

int hammingWeight(uint32_t n) {
  uint32_t m = 1;
  int count = 0;
  for (int i = 0; i < 32; ++i) {
    if ((m & n) != 0) {
      count++;
    }
    m = m << 1;
    // m <<= 1;
  }
  return count;
}
int main() {
    // uint32_t n = 11111111111111111111111111111101;
    // int res = hammingWeight(n);
    // cout << res;
    int mast = 1;
    int b = 4;
    if(!(mast&b)){
        cout<<"yes";
    }
    return 0;
}