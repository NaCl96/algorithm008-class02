/*
 * @Author: your name
 * @Date: 2020-06-21 17:56:00
 * @LastEditTime: 2020-06-21 18:00:45
 * @LastEditors: Please set LastEditors
 * @Description: 115. 不同的子序列
 * @FilePath: \algorithm008-class02\Week_09\distinct-subsequences.cpp
 */ 


#include <iostream> 
#include <vector>
#include <string>

using namespace std;
int numDistinct(string s,string t){
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1, 0));
    //base case 当t[0]为空串的时候，对应的子序列都是1
    for(int i = 0;i <= n;++i){
        dp[i][0] = 1;
    }
    //选择
    for(int i = 1;i <= n;++i){
        for(int j = 1; j <= m; ++j){
            if(s[i-1] == t[j-1]){
                //注意这里可以保持j不动，去移动i,可以找子序列
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else{
                //如果字符不同，则只移动i。
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}
int main(){
    string s = "rabbbit";
    string t = "rabbit";    
    int res = numDistinct(s,t);
    cout<<res;
    return 0;
}

