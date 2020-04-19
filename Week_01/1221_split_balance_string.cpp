/* 
在一个「平衡字符串」中，'L' 和 'R' 字符的数量是相同的。

给出一个平衡字符串 s，请你将它分割成尽可能多的平衡字符串。

返回可以通过分割得到的平衡字符串的最大数量。

输入：s = "RLRRLLRLRL"
输出：4
解释：s 可以分割为 "RL", "RRLL", "RL", "RL", 每个子字符串中都包含相同数量的 'L' 和 'R'。

 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int balancedStringSplit_1(string s)
{
    int count = 0;
    int cnt_R = 0, cnt_L = 0;
    for (int i = 0; i <= s.size(); ++i)
    {
        if(cnt_R!=0 &&  cnt_R == cnt_L){
            count++;
            cnt_R = 0;
            cnt_L = 0;
        }
        if(i < s.size() && s[i] == 'R'){
            cnt_R++;
        }
        else if(i < s.size() && s[i] == 'L'){
            cnt_L++;
        }
    }
    return count;
}


int balancedStringSplit_2(string s)
{
    int count = 0;
    int num = 0;
    for(const char& c : s){
        num += c == 'R' ? 1 : -1;
        if(num == 0){
            count++;
        }
    }
    return count;
}


int main()
{
    string s = "RLRRLLRLRL";
    int res = balancedStringSplit_1(s);

    return 0;
}