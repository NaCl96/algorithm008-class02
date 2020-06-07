学习笔记

#### 字典树（前缀树）

- Trie树，即前缀树，又称单词查找树，字典树，是一种树形结构，是一种哈希树的变种。典型应用是用于统计和排序大量的字符串（但不仅限于字符串），所以经常被搜索引擎系统用于文本词频统计。
- Trie树的**核心思想**是空间换时间，利用字符串的**公共前缀**来降低查询时间的开销以达到提高效率的目的。 它的**优点**是：最大限度地减少无谓的字符串比较，查询效率比哈希表高

##### 基本性质

- 根节点不包含字符，除根节点外，每个结点都只包含一个字符
- 从根节点到某一个结点，路径上经过的字符连接起来，为该节点对应的字符串
- 每个结点的所有子节点包含的字符都不相同。

模板：

```c++
class Trie{
private:
    bool isEnd = false;
    Trie* next[26] = {nullptr};
public:
    //构造函数
    Trie(){
    }
    
    //insert
    void insert(string word){
        Trie* node = this;
        for(auto w : word){
            if(node->next[w-'a'] == nullptr){
                node->next[w-'a'] = new Trie();
            }
            node = node->next[w-'a'];
        }
        node->isEnd =true;
    }
    
    //search
    bool search(string word){
        Trie* node = this;
        for(auto w : word){
            if(node->next[w-'a'] == nullptr){
                return false;
            }
            node = node->next[w-'a];
        }
        return node->isEnd;
    }
    
    //starts with the given
    bool startswith(strign prefix){
        Trie* node = this;
        for(auto w : prefix){
            node = node->next[w-'a'];
            if(node == nullptr){
                return false;
            }
        }
        return true;
    }
}
```

[单词的压缩编码](http://note.youdao.com/noteshare?id=4925434a2ec4ae09ea69a96ea189b7dc&sub=126279A868734221ADC9D084164F9AE0)

[单词替换](http://note.youdao.com/noteshare?id=9eb11ab6968f18c237be51d85bbf92c1&sub=CE3B9DFD69EE4002AEB3361FDC7CCCAF)

[212. 单词搜索 II](https://leetcode-cn.com/problems/word-search-ii/)



#### 并查集

- 主要解决图论中的动态连通性问题而提出来的。
- [Union-Find](https://labuladong.gitbook.io/algo/gao-pin-mian-shi-xi-lie/unionfind-suan-fa-xiang-jie)

模板：

```c++
class UF {
 private:
  //所有连通分量的数量
  int count;
  //parent[x]表示x的父结点
  vector<int> parent;
  //size[x],记录x所在的连通分量的结点数
  vector<int> size;

 public:
  UF(int n) {
    count = n;
    parent.resize(n);
    size.resize(n);
    //初始化，每个结点的parent都是其本身。
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
      size[i] = 1;
    }
  }
  int find(int x) {
    while (parent[x] != x) {
      //路径压缩
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }
  void Union(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    if (rootQ == rootP) {
      return;
    }
    if (size[rootP] > size[rootQ]) {
      parent[rootQ] = rootP;
      size[rootP] += size[rootQ];
    } else {
      parent[rootP] = rootQ;
      size[rootQ] += size[rootP];
    }
    count--;
  }

  bool connected(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    return rootQ == rootP;
  }

  int getCount() const { return count; }
};
```

[547. 朋友圈](https://leetcode-cn.com/problems/friend-circles/)

[被围绕的区域](https://leetcode-cn.com/problems/surrounded-regions/)

一般来说，对于图的dfs相关的算法题，都可以用并查集来解答。可以提高时间复杂度。





#### 高级搜索

- 剪枝
- 双向BFS
- 启发式搜索(优先级队列)

先概述一下初级搜索：

- 朴素搜索
- 优化方式：不重复（fibonacci），剪枝（括号生成问题）
- 搜索方向：DFS/BFS



[零钱兑换](https://leetcode-cn.com/problems/coin-change/)



#### 红黑树

- 每个结点要么是红的，要么是黑的。
- 根节点是黑的
- 每个叶结点是黑的
- 如果一个结点是红的，那么它的两个儿子都是黑的
- 对于任一结点而言，其到叶结点树尾端NIL指针的每一条路径都包含相同数目的黑结点。

#####  为什么有了平衡树（AVL）还需要红黑树？

- 虽然平衡树解决了二叉查找树退化为近似链表的缺点，能够把查找时间控制在 O(logn)，不过却不是最佳的，因为平衡树要求**每个节点的左子树和右子树的高度差至多等于1**，这个要求实在是太严了，导致每次进行插入/删除节点的时候，几乎都会破坏平衡树的第二个规则，进而我们都需要通过**左旋**和**右旋**来进行调整，使之再次成为一颗符合要求的平衡树。
- 而红黑树是一种弱平衡二叉树，不必严格的要求高度平衡。红黑树在插入、删除等操作，**不会像平衡树那样，频繁着破坏红黑树的规则，所以不需要频繁着调整**，这也是我们为什么大多数情况下使用红黑树的原因。
- 单单在查找方面的效率，平衡树要比红黑树快。
- 平衡树是为了解决二叉查找树退化为链表的情况，而红黑树是为了解决平衡树在插入、删除等操作需要频繁调整的情况。

