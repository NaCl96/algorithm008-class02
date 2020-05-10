学习笔记

#### 递归算法思路

递归思维要点：

- 不要人肉进行递归（最大误区）
- 找到最近最简去解答，即找最近重复子问题
- 数学归纳法，n=1,n=2可以归纳，然后求递归其他

#### 普通泛型递归模板

```c++
void recursion(level,param1,param2..){
    //结束条件
    if(level > MAX_LEVEL){
		process_result;
        return;
    }
    //当前层的处理
    process(level,data...)
        
    //下一层递归
    recursion(level+1,p1,.)
    
    //合并结果
    result = process_result()
}
```

参考习题：

[二叉树的最大深度](http://note.youdao.com/noteshare?id=56884ee3e7abda0bc1f358bd635bd0f3&sub=56A0E76035004765A87D49BE57F4B552)

[二叉树的最小深度]()

[验证二叉搜索树](http://note.youdao.com/noteshare?id=0ffb0855e334fcea57d3bc7100540a2c&sub=DFB860ED32A440AAA63329E3A602FECE)

[二叉树的直径](http://note.youdao.com/noteshare?id=976048cd7eadba17d54e0831ff6486dc&sub=1F3456F2BB9640FEAA99DD37A7BED802)

[二叉树的最近公共祖先](https://note.youdao.com/ynoteshare1/index.html?id=48d53e2665eea5568334fdd1ac53f097&type=note)

####  回溯算法思路

- 回溯是利用的递归的思想，进行的深入探索。
- 回溯实际上是一种试探算法，这种算法跟暴力搜索最大的不同在于，在回溯算法里，是一步一步地小心翼翼地进行向前试探，会对每一步探测到的情况进行评估，如果当前的情况已经无法满足要求，那么就没有必要继续进行下去，也就是说，它可以帮助我们避免走很多的弯路。
- 回溯算法的特点在于，当出现非法的情况时，算法可以回退到之前的情景，可以是返回一步，有时候甚至可以返回多步，然后再去尝试别的路径和办法。

解题模板：

- 判断当前情况是否非法，如果非法就立即返回；
- 当前情况是否已经满足递归结束条件，如果是就将当前结果保存起来并返回；
- 当前情况下，遍历所有可能出现的情况并进行下一步的尝试。
- 递归完毕后，立即回溯，回溯的方法就是取消前一步进行的尝试

#### 回溯代码模板

```c++
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```

参考习题：

[全排列问题](http://note.youdao.com/noteshare?id=e7ce12b74aad7a8425e0efe8e58e7dd0&sub=E37F6516CF684E0B9C4B44990E93CA2A)

[括号生成](http://note.youdao.com/noteshare?id=a7b6d6b3c0a933d448a2075403450332&sub=949DBB6344754FE4BE7D5F5126082DE5)

[N-皇后问题](https://leetcode-cn.com/problems/n-queens/)

[电话号码的组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)

