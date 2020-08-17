# 23(167) 两数之和Ⅱ-输入有序数组

## 描述


给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

## 示例

```bash

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

``` 


## Description

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.

## Example

```bash

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

```


`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

### 哈希表

代码与`1.两数之和`几乎相同 只在最后插入res的时候给数组序号+1 利用哈希表解题 

```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        unordered_map<int,int> m;
        for(int i=0;i<numbers.size();++i){
            if(m.find(numbers[i])==m.end()) m[target-numbers[i]]=i;
            else{
                res.push_back(m[numbers[i]]+1);
                res.push_back(i+1);
            }
        }
        return res;
    }
};
```

```
执行用时：20 ms, 在所有 C++ 提交中击败了7.41%的用户
内存消耗：9.8 MB, 在所有 C++ 提交中击败了7.89%的用户
```

哈希表可以解决问题 但不免给人一种与第一题相同的错觉 且没有学到新的内容 

回归题目 我们看到题目中给的条件增设了 `numbers数组内元素是升序排列的有序数组` 所以我们应该使用到有序的这个特性

### 双指针二分解题 

```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int i=0,j=numbers.size()-1;
        while(i<j){
            if(numbers[i]+numbers[j]<target) i++;
            else if(numbers[i]+numbers[j]>target) j--;
            else{
                res.push_back(i+1);
                res.push_back(j+1);
                break;
            }
        }
        return res;
    }
};
```

```
执行用时：4ms, 在所有 C++ 提交中击败了99.60%的用户
内存消耗：9.7 MB, 在所有 C++ 提交中击败了13.93%的用户
```

为什么双指针这么快呢 因为双指针满足了一个原理:缩减搜索空间 

双指针`i j`满足的条件: `0=<i<n 0<=j<n`  

假设此时 `numbers[0]+numbers[7]` < `target` 我们应该去寻找和比`target`更大的两个数 由于numbers[7]已经是最大的 因此其余的数与numbers[0]相加得到的和只会更小 换言之: `numbers[0]+numbers[6],numbers[0]+numbers[5] ... numbers[0]+numbers[1]` < `target`必成立

这些不符合条件的解可以一次性排除 相当于i=0的情况全部排除掉 对应`numbers[0]+numbers[7]` > `target` 同理 

无论`numbers[0]+numbers[7]`与`target`的大小关系如何我们都可以排除掉i j代表的一行/一列的搜索空间 经过n步以后 就检查完所有的可能性