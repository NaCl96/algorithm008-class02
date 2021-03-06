学习笔记



#### 位运算

以下两个最常用，熟记！

- x & (-x) 获取二进制中最右边的1
- x & (x-1) 去除二进制最右边的1

[\52. N皇后 II](https://leetcode-cn.com/problems/n-queens-ii/)

[\191. 位1的个数](https://leetcode-cn.com/problems/number-of-1-bits/)



#### LRU Cache

- LRU Cache 是常用的置换算法，即Least recently used，最近最少使用算法。据数据的历史访问记录来进行淘汰数据，其核心思想是“如果数据最近被访问过，那么将来被访问的几率也更高”。
- 那么如何来实现呢?
  - 使用hashmap和双向链表来共同实现
  - hashmap用来记录结点Key，双向链表存储key以及value。
  - 使用双向链表的原因是我们可能会经常删除一些结点，然后放到头部，又因为单链表删除操作比较麻烦，需要找到其前一个结点。所有这里使用双向链表。

```c++
struct CacheNode {
  int key;
  int val;
  CacheNode *pre, *next;
  CacheNode(int k, int v) : key(k), val(v), pre(nullptr), next(nullptr){};
};

class LRUCache_2 {
 private:
  int max_cap;
  CacheNode *head, *tail;
  unordered_map<int, CacheNode *> map;

 public:
    LRUCache_2(int capacity){
        max_cap = capacity;
        head = nullptr;
        tail = nullptr;
    }

    int get(int key){
        unordered_map<int,CacheNode*>::iterator it = map.find(key);
        if(it == map.end()){
            cout<<"not find"<<endl;
            return -1;
        }
        else{
            CacheNode* nd = it->second;
            remove(nd);
            setHead(nd);
            cout<<"find:"<<nd->val<<endl;
            return nd->val;
        }
    }

    void put(int key,int val){
        unordered_map<int,CacheNode*>::iterator it =map.find(key);
        if(it != map.end()){
            CacheNode* nd = it->second;
            nd->val =val;
            remove(nd);
            setHead(nd);
        }else{
            CacheNode* node = new CacheNode(key,val);
            if(map.size() >= max_cap){
                unordered_map<int,CacheNode*>::iterator it_ = map.find(tail->key);
                remove(tail);
                map.erase(it_);
            }
            setHead(node);
            map[key] = node;
            cout<<"has put"<<endl;
        }
    }

    void remove(CacheNode* node){
        if(node->pre != nullptr){
            node->pre->next = node->next;
        }
        else{
            head = node->next;
        }
        if(node->next != nullptr){
            node->next->pre = node->pre;
        }else{
            tail = node->pre;
        }
    }

    void setHead(CacheNode* node){
        node->next = head;
        node->pre = nullptr;
        if(head != nullptr){
            head->pre = node;
        }
        head = node;
        //注意这里的重要性，这里是在put第一个节点的的时候，对tail进行赋值
        
        //，没有这部分会出错。在删除最久未使用的节点时会出错，因为tail是nullptr
        if(tail == nullptr){
            tail = head;
        }
    }
};
```



#### 排序

这里我只整理了快速排序，也是最常用的排序算法。

代码如下：

```c++
//快速排序
int partition(vector<vector<int>>& intervals,int left,int right){
    int pivot = left;
    int index = pivot;
    for(int i = left+1; i <=right;++i){
        if(intervals[i][0] < intervals[pivot][0]){
            swap(intervals[i],intervals[++index]);
        }
    }
    swap(intervals[pivot],intervals[index]);
    return index;
}

void quick(vector<vector<int>>& intervals,int left,int right){
    if(left < right){
        int x = partition(intervals,left,right);
        quick(intervals,left,x-1);
        quick(intervals,x+1,right);
    }
}
```

