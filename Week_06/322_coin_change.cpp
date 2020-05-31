/*
 * @Author: your name
 * @Date: 2020-05-31 14:08:35
 * @LastEditTime: 2020-05-31 14:45:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_06\322_coin_change.cpp
 */

#include <iostream>
#include <vector>
using namespace std;

//递归 + 记忆化搜索
int findway(vector<int>& coins, int amount, vector<int>& memo) {
  if (amount < 0) {
    return -1;
  }
  if (amount == 0) {
    return 0;
  }
  if(memo[amount-1] != 0){
      return memo[amount-1];
  }
  int min = INT_MAX;
  for (int i = 0; i < coins.size(); ++i) {
    int cur = findway(coins, amount - coins[i], memo);
    if(cur > 0 && cur < min){
        min = res + 1;
    }
  }
  memo[amount-1] = (min == INT_MAX ? -1 : min);
  return memo[amount-1];
}

int coinChange_recur(vector<int>& coins, int amount) {
  if (coins.size() == 0) {
    return -1;
  }
//   int res = INT_MAX;
  vector<int> memo(amount,-1);
  findway(coins, amount, 0, memo);
  if (res == INT_MAX) {
    return -1;
  }
  return res;
}

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

int main() {
  vector<int> coins = {1, 2, 5};
  int res = coinChange(coins, 11);
  return 0;
}