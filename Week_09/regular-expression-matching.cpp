/*
 * @Author: your name
 * @Date: 2020-06-21 17:04:24
 * @LastEditTime: 2020-06-21 17:10:04
 * @LastEditors: Please set LastEditors
 * @Description: 正则表达式匹配
 * @FilePath: \algorithm008-class02\Week_09\regular-expression-matching.cpp
 */ 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isMatch(string s,string p){
    s = " " + s;
    p = " " + p;
    int n = s.size();
    int m = p.size();
    vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
    dp[0][0] = true;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            if(s[i-1] == p[j-1] || p[j-1] == '.'){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '*'){
                if(s[i-1] != p[j-2] || p[j-2] != '.'){
                    dp[i][j] = dp[i][j-2];
                }
                else{
                    dp[i][j] = dp[i-1][j] || dp[i][j-2];
                }
            }
        }
    }
    return dp[n][m];
}
int main(){
    string s = "aa";
    string p ="a*";
    bool res = isMatch(s,p);
    cout<<res;
    return 0;
}