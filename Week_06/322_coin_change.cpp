/*
 * @Author: your name
 * @Date: 2020-05-31 14:08:35
 * @LastEditTime: 2020-06-09 14:24:49
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_06\322_coin_change.cpp
 */

#include <iostream>
#include <vector>
using namespace std;

//动态规划解法
// dp[i] 表示有金额i最少的硬币数
int coinChange(vector<int>& coins, int amount) {
  vector<int> dp(amount + 1, amount + 1);
  // base case,当金额为0时，硬币数为0
  dp[0] = 0;
  //遍历金额从0到amount,求解最优子问题。    
  for (int i = 0; i < dp.size(); ++i) {
    for (int coin : coins) {
      //判断当前金额是否满足当前coin。
      if (i - coin < 0) continue;
      dp[i] = min(dp[i], 1 + dp[i - coin]);
    }
  }
  return (dp[amount] == amount + 1) ? -1 : amount + 1;
}

int coinChange_2(vector<int>& coins,int amount){
  if(coins.size() == 0) return -1;
  vector<int> dp(amount+1,0);
  for(int i = 1; i <= amount;++i){
    int min = INT_MAX;
    for(int j = 0; j < coins.size(); ++j){
      if(i - coins[j] >= 0 && dp[i-coins[j]] < min){
        min = dp[i-coins[j]] + 1;
      }
    }
    dp[i] = min;
  }
  return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
  vector<int> coins = {1, 2, 5};
  int res = coinChange_2(coins, 11);
  cout<<res<<endl;
  return 0;
}