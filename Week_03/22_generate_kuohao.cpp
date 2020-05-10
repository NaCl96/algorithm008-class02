/*
 * @Author: your name
 * @Date: 2020-04-27 08:46:08
 * @LastEditTime: 2020-04-27 09:22:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_03\22_generate_kuohao.cpp
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//递归写法
vector<string> res;

void generator(int left, int right, int n, string s, vector<string>& res) {
  if (left == n && right == n) {
    res.push_back(s);
    return;
  }
  if (left < n) {
    generator(left + 1, right, n, s + '(', res);
  }
  if (right < left && right < n) {
    generator(left, right + 1, n, s + ')', res);
  }
}

vector<string> generateParenthesis_1(int n) {
  string s = "";
  generator(0, 0, n, s, res);
  return res;
}

int main(){
    auto ans = generateParenthesis_1(3);
    for(auto i : ans){
        cout<<i<<endl;
    }
}