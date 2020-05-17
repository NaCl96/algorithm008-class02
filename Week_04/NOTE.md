学习笔记

本周主要深入dfs，bfs问题。

#### 一、 DFS,BFS

- dfs和bfs都属于图的遍历。
- dfs的核心思想就是回溯算法
- bfs的核心思想就是把问题抽象成图，然后从一个点开始，向四周扩散。一般来说，写bfs算法都是用队列这种数据结构，每次将一个节点周围的所有节点加入队列。
- bfs和dfs最大的区别就是：bfs找到的路径一定是最短的，但是代价就是空间复杂度比dfs要大很多。



##### 算法框架

1. bfs

   **涉及到bfs算法问题的本质就是让你在一幅“图”中找到从起点start到终点target的最近距离。**

```c++
int bfs(Node start,Node target){
    queue<Node> q;
    Set<Node> visited;
    q.push(start);
    //visited主要是防止走回头路
    visited.push(start);
    int step = 0;
    
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; ++i){
            Node cur = q.top();
            q.pop();
            if(cur == target){
                return step;
            }
            //cur.adj()泛指cur相邻的节点。
            for(Node x : cur.adj()){
                if(x not in visited){
                    q.push(x);
                    visited.push(x);
                }
            }
        }
        step++;
    }
    
}
```



[二叉树的最小深度](https://note.youdao.com/ynoteshare1/index.html?id=7174e6af1e277e4a86bcb00f3345dad4&type=note)

[最小基因变化](https://leetcode-cn.com/problems/minimum-genetic-mutation/)

[打开密码锁](https://leetcode-cn.com/problems/open-the-lock/submissions/)





2. dfs框架

   **dfs算法的框架其实质就是之前的回溯算法框架。**

   ```
   void dfs(vector<vector<int>>& gird,int i,int j){
   	//dfs结束条件
   	if(i<0||j<0||i>=grid.size()||j>=grid[0].size()) return;
       if(grid[i][j] == 0) return;
      	grid[i][j] = 0;
       dfs(grid,i+1,j,cur);
       dfs(grid,i,j+1,cur);
       dfs(grid,i-1,j,cur);
       dfs(grid,i,j-1,cur);
   }
   
   int find_area(vector<vector<int>>& gird){
      ....
   }
   ```

   [岛屿的最大面积](https://note.youdao.com/ynoteshare1/index.html?id=5f182c28838ab7c2c9947cde466b69c2&type=note)

   [岛屿的数量](https://note.youdao.com/ynoteshare1/index.html?id=3ec18f5dafd1a60b76f05db6cbb407bf&type=note)





#### 二、贪心算法

1. 什么是贪心算法？

   - 贪心算法可以认为是动态规划算法的一个特例，相比动态规划，使用贪心算法需要满足更多的条件（贪心选择性质），但是效率比动态规划要高。
- 比如说一个算法问题使用暴力解法需要指数级时间，如果能使用动态规划消除重叠子问题，就可以降到多项式级别的时间，如果满足贪心选择性质，那么可以进一步降低时间复杂度，达到线性级别的。
   - 什么是贪心选择性质呢，简单说就是：每一步都做出一个局部最优的选择，最终的结果就是全局最优。注意哦，这是一种特殊性质，其实只有一部分问题拥有这个性质。



[无重叠子区间](https://note.youdao.com/ynoteshare1/index.html?id=1cbbbc7e8d66b2a73cbd77ecd3713ba3&type=note)

[买股票的最佳时期II](https://note.youdao.com/ynoteshare1/index.html?id=2d10e4d8e200a568788cf74110aa9dae&type=note)

[分发饼干](https://leetcode-cn.com/problems/assign-cookies/)





#### 二、二分查找

1. 二分查找框架

   ```
   int binarySearch(int[] nums, int target) {
       int left = 0, right = ...;
   
       while(...) {
           int mid = left + (right - left) / 2;
           if (nums[mid] == target) {
               ...
           } else if (nums[mid] < target) {
               left = ...
           } else if (nums[mid] > target) {
               right = ...
           }
       }
       return ...;
   }
   ```

   - 分析二分查找的一个技巧是：不要出现 else，而是把所有情况用 else if 写清楚，这样可以清楚地展现所有细节。本文都会使用 else if，旨在讲清楚，读者理解后可自行简化。
   - 其中...标记的部分就是二分查找所涉及的问题中的所有细节的地方，当你见到一个二分查找的代码时，首先注意这几个地方。
   - 另外，计算mid的时候要防止溢出，代码中left + (right - left) / 2有效的防止了left和right太大直接相加导致溢出的问题。



2. 寻找一个数（最基本的二分搜索）

   - 这个场景是最简单的，肯能也是大家最熟悉的，即搜索一个数，如果存在，返回其索引，否则返回 -1。

     ```c++
     int binary(vector<int>& nums,int target){
     	int left = 0, right = nums.size();
         int mid = 0;
         while(left < right){
             mid = left + (right - left) / 2;
             if(nums[mid] == target){
                 return mid;
             }
             else if(nums[mid] > target){
                 right = mid;
             }
             else if(nums[mid] < target){
                 left = mid + 1;
             }
         }
         return nums[left] == target ? left : -1;
     }
     ```

     

     ```c++
     int binary(vector<int>& nums,int target){
         int left = 0, right = nums.size()-1;
         int mid = 0;
         while(left <= right){
             mid = left + (right - left) / 2;
             if(nums[mid] == target){
                 return mid;
             }
             else if(nums[mid] > target){
                 right = mid - 1;
             }
             else if(nums[mid] < target){
                 left = mid + 1;
             }
         }
         return -1;
     }
     ```

     - 这里注意两种方式的right不同，right初始是nums.size()-1，因此left和right都是闭区间，注意区别right = nums.size()的情况。
     - 结束条件是left <= right，即最终left = right + 1; 结束条件left < right,即最终left == target，最后需要判断left的情况。



[33. 搜索旋转排序数组](http://note.youdao.com/noteshare?id=eaddae4528c345d01f12a0600548f8cf&sub=E88D7B880C2C4263B7051D7D4B113FE9)

[69. x 的平方根](https://leetcode-cn.com/problems/sqrtx/)

[875. 爱吃香蕉的珂珂](https://leetcode-cn.com/problems/koko-eating-bananas/)

