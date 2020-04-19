#### 学习笔记
本周主要练习了以下内容
- 数组
- 链表
- 栈和队列

### 课后作业解析

**leetcode 283: 移动零**

解题思路：

1. 采用快慢指针的思想
   - j从零开始表示慢指针，i从0开始遍历数组，遇到nums[i]  != 0时，交换nums[i],nums[j]的值 并且j++。
2. 也可也采用计数0的思想
   - 即统计所有0的个数，然后将非0元素依次从0开始放入，最后添加所有0即可。
```c++
//方法一：
void moveZeros(vector<int>& nums){
   int j = 0;  //慢指针
   for(int i = 0; i < nums.size();++i){
      if(nums[i] != 0){  //快指针i遇到非0元素就和j进行交换
         swap(nums[i],nums[j++]);
      }
   }
}

//方法二,其实与上述思路一致，只不过写法不同。
void moveZeros_2(vector<int>& nums){
   int j = 0;
   for(int i = 0; i < nums.size();++i){
      if(nums[i] != 0){
         nums[j++] = nums[i];
      }
   }
   for(j;j < nums.size();++j){
      nums[j] = 0;
   }
}

```

**leetcode  1: 两数之和**

解题思路：

1. 首先想到的就是暴力法，直接两个暴力循环去找出满足条件的。即nums[i] + nums[j] ==  target的答案，时间复杂度O(n)。

2. 以空间换时间，使用hash表来加速寻找，由于我们需要找到元素的下标，因此需要借助hash表来帮助存储下标和下标对应的元素值才可以快速的查到满足条件的结果。

   

这里只写第二种方法：

```c++
//1.hash
vector<int> twoSum(vector<int>& nums, int target){
	unordered_map<int,int> map_num;
	for(int i = 0; i < nums.size(); ++i){
		//利用c++ 标准库中的hash容器，unordered_map来存储。并使用容器中自带的find()函数来查询
		if(map_num.find(target - nums[i]) != map_num.end()){
			return {map_num[target-nums[i]] , i};
		}
		//这里hash的键存的是nums中元素的值，data存的是元素的下标
		map_num[nums[i]] = i;
	}
}
```

**拓展：leetcode15: 三数之和**

解题思路：

1. 在上述两数之和的基础上，我们可以将3个数中的一个确定为target，另外两个就满足a + b == target的形式
2. 因为满足条件的有不止一个解，且结果不是返回下标，因此我们先将数组进行排序
3. 用i遍历一遍数组，作为target。对于每个nums[i]，另j=i+1,k = num.size()-1，进行头尾查找。
4. 注意要筛除重复的解。

```c++
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp(3,-1);
	//先进行排序
    sort(nums.begin(),nums.end());
    //临界条件判断
    if(nums.size() < 3 || nums[0] > 0 || nums[nums.size()-1] < 0){
        return ans;
    }
    //注意这里i只用遍历到nums.size()-2即可
    for(int i = 0; i < nums.size()-2;++i){、
        //若nums[i]>0，那么它之后的也都大于0，不满足条件
        if(nums[i] > 0){
            break;
        }
        //去除重复
        if(i > 0 && nums[i] == nums[i-1]) continue;
        temp[0] = nums[i];
        int j = i+1,k = nums.size()-1;
        int target = -nums[i];
        //头尾遍历，加快速度                                  
        while(j < k){
            if(nums[j] + nums[k] == target){
                temp[1] = nums[j++];
                temp[2] = nums[k--];
                ans.push_back(temp);
                //去除后两个数的重复
                while(j < k && nums[j] == nums[j-1]) j++;
                while(j < k && nums[k] == nums[k+1]) k--;
            }
            else if(nums[j] + nums[k] > target){
                k--;
            }
            else{
                j++;
            }
        }
    }
    return ans;
}
```



**leetcode 66:加一**

解题思路：

1. 这个题目比较巧妙，其实就是进位的问题

2. 我们可以从后往前进行遍历，如果当前digits[i] < 9，那么直接+1并结束循环即可。

3. 如果遇到digits[i] == 9时候，又分为两种，一种是当i==0时，这个时候需要在补一个1在数组的最前面。

4. 另一种是i != 0时，这个时候直接令digits[i] = 0即可，然后继续遍历。

   

```c++
vector<int> plusOne(vector<int>& digits){
    int n = digits.size();
    for(int i = n - 1;i >=0; --i){
        if(digits[i] < 9){
            ++digits[i];
            return digits;
        }
        //注意这种情况出现的只能是 999，9999这种情况。
        else if(i == 0){
            digits[i] = 1;
            digits.push_back(0);
        }
        else{
            digits[i] = 0;
        }
    }
    return digits;
}
```



**leetcode 26:删除排序数组的重复项**

解题思路：

1. 首先明确题意，排好序，原地删除重复，并返回删除后的数组长度。

2. 这里其实还是用到了双指针之快慢指针的思想。

3. 初始：慢指针i=0,快指针j=1，当nums[j] == nums[i]时，j++，i不动

4. 当nums[j] != nums[i]时，nums[++i] = nums[j]。这样就可以将重复元素给覆盖掉了。

5. 优化条件，j - 1 == 1时候不需要上述4的赋值，直接i++即可。

   

```c++
//未优化思路
int removeDuplicates(vector<int>& nums) {
    //首先找出特殊条件，先排除掉
    if(num.size()==0 || num.size()==1){
        return num.size();
    }
    int i = 0;
    int j = 1;
    while(j < nums.size()){
    	if(nums[j] == nums[i]){
            j++;
        }
        else{
            nums[++i] = nums[j++];
        }
    }
    //返回数组长度，i是下标，需要+1
    return i+1;
}

//上述的优化
int removeDuplicates(vector<int>& nums) {
    //首先找出特殊条件，先排除掉
    if(num.size()==0 || num.size()==1){
        return num.size();
    }
    int i = 0;
    int j = 1;
    while(j < nums.size()){
    	if(nums[j] != nums[i]){
            //这里进行优化，是因为如果不存在重复项1,2,3,4,5这种情况，就不需要一直赋值操作，直接i++即可
            if(j - i > 1){
                nums[++i] = nums[j];
            }else{
                ++i;
            }
        }
        j++;
    }
    //返回数组长度，i是下标，需要+1
    return i+1;
}
```

