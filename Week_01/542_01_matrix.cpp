#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;

//leetcode:542 01矩阵
/* 
1.大体思路，广度优先搜索
2.初始化二维数组ans和队列que,将所有为0的元素入队
3.当队列不空时，出队front,然后走上下左右四个方向，新位置的值初始为INT_MAX，如果front()大于该值，则更新新位置的值。具体看代码如何实现
4.重复步骤3，知道队列 为空。
 */
vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
{
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
    queue<pair<int, int>> que;

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] == 0)
            {
                ans[i][j] == 0;
                que.push({i, j});
            }
        }
    }

    while (!que.empty())
    {
        pair<int, int> temp = que.front();
        que.pop();
        for (int k = 0; k < 4; ++k)
        {
            int x = temp.first + dx[k];
            int y = temp.second + dy[k];
            if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size())
            {
                if (ans[x][y] > ans[temp.first][temp.second])
                {
                    ans[x][y] = ans[temp.first][temp.second] + 1;
                    que.push({x, y});
                }
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}