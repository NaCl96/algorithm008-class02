#### 本周主要是复盘动态规划相关题目以及字符串相关题目

关于动态规划问题，有以下几个要点要注意。 

- 动态规划问题的一般形式是求最值。比如说让你求最长递增子序列呀，最小编辑距离呀
- 求解动态规划的核心问题是穷举。动态规划的穷举有点特别，因为这类问题**存在「重叠子问题」**，如果暴力穷举的话效率会极其低下，所以需要「备忘录」或者「DP table」来优化穷举过程，避免不必要的计算。
- 动态规划问题一定会具备**最优子结构**，才能通过子问题的最值得到原问题的最值。
- 列出正确的**状态转移方程**，才能正确的进行穷举。

**明确 base case -> 明确「状态」-> 明确「选择」 -> 定义 dp 数组/函数的含义**。

#### 动态规划面试题主要分成以下三大类

- 线性规划，线性，就是说各个子问题的规模以线性的方式分布，并且子问题的最佳状态或结果可以存储在一维线性的数据结构里，例如一维数组，哈希表等。
- 区间规划，区间规划，就是说各个子问题的规模由不同的区间来定义，一般子问题的最佳状态或结果存储在二维数组里。一般用 dp[i][j] 代表从第 i 个位置到第 j 个位置之间的最佳状态或结果。
- 约束规划

关于 [不同路径II](https://leetcode-cn.com/problems/unique-paths-ii/)的问题，这里贴出代码进行总结：

```c++
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if(n == 0) return 0;
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(n,vector<int>(m,0));
        //base case 当第一行，第一列有障碍时，后面的都为0，否则为1
        for(int i = 0;i < n;++i){
            if(obstacleGrid[i][0] == 1) break;
            dp[i][0] = 1;
        }
        for(int i = 0;i < m;++i){
            if(obstacleGrid[0][i] == 1) break;
            dp[0][i] = 1;
        }
        //状态选择
        for(int i = 1;i < n;++i){
            for(int j = 1;j < m;++j){
                //当前有障碍物
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                //没有障碍物
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};
```







#### 字符串相关

有关字符串的问题是笔试中常见的题型，没有什么多说的，就是多练习，多总结经验即可。