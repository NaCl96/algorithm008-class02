/*
有效括号字符串为空 ("")、"(" + A + ")" 或 A + B，其中 A
和 B 都是有效的括号字符串，+ 代表字符串的连接。例如，""，"()"，"(())()" 和 "(()(()))" 都是有效的括号字符串。

如果有效字符串 S 非空，且不存在将其拆分为 S =
A+B 的方法，我们称其为原语（primitive），其中 A 和 B 都是非空有效括号字符串。

给出一个非空有效字符串 S，考虑将其进行原语化分解，使得：S = P_1 + P_2 + ... +
P_k，其中 P_i 是有效括号字符串原语。

对 S 进行原语化分解，删除分解中每个原语字符串的最外层括号，返回 S 。

*/
#include <iostream>
#include <stack> 
#include <string>
#include <vector>


using namespace std;

//方法一，使用栈先找出所有的原语。
string removeOuterParentheses(string s) {
  stack<char> stk;
  vector<string> primit;
  string temp = "";
  for (char c : s) { 
    temp += c;
    if (c == '(') {
      stk.push(c);
    } else { 
      stk.pop();
      if (stk.empty()) {
        temp = temp.substr(1, temp.size() - 2);
        primit.push_back(temp);
        temp = "";
        continue;
      }
    }
  }
  string res = "";
  for (auto i : primit) {
    res += i;
  }
  return res;
}

//原地操作，不使用辅助空间
string removeOuterParentheses_2(string s) {
  int cnt_left = 0;
  int cnt_right = 0;
  string res = "";
  int index = 0;
  // int length = 0;
  for (auto i : s) {
    if (i == '(') {
      cnt_left++;
    } else {
      cnt_right++;
    }
    if (cnt_left == cnt_right && cnt_left > 0) {
      res += s.substr(index + 1, cnt_left + cnt_right - 2 - index);
      index = cnt_left + cnt_right;
      // cnt_left = 0;
      // cnt_right = 0;
    }
  }
  return res;
}
//方法二的改进

string removeOuterParentheses_3(string s) {
  int count = 0;
  string res = "";
  for (auto i : s) {
    if (i == '(') {
      if (count++) {
        res += '(';
      }
    } else {
      if (--count) {
        res += ')';
      }
    }
  }
  return res;
}

int main() {
  string s = "(()())(())(()(()))";
  string ans = removeOuterParentheses_3(s);
  cout << ans;
  return 0;
}