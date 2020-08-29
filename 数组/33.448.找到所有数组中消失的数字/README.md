# 33(448) 找到所有数组中消失的数字

## 描述

给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

找到所有在 [1, n] 范围之间没有出现在数组中的数字。

您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。


## 示例

```bash

输入:
[4,3,2,7,8,2,3,1]

输出:
[5,6]

``` 

## Description

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

## Example

```bash

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

### 思路

由于数组内元素 均大于等于1 小于等于数组长度 因此要找到在这个数组中出现次数为0的数 这个数也是大于等于1小于等于数组长度的 

方法就是 第一次循环 对数组中出现的数字 减一操作后对数组长度取余 得到的结果将他赋值给index 然后对nums[index]上的值 加上数组长度用来做标记 

第二次循环 检测数组中是否有值不大于数组长度的值 若有 则所在元素的下标加1 就是数组内缺失的数字

```bash
nums=[4,3,2,7,8,2,3,1] nums.size()=8;
first loop: index=(nums[i]-1)%nums.size();nums[index]+=nums.size();
nums=[4+8,3+8,2+8,7+8,8,2,3+8,1+8]
second loop: if(nums[i]<=8) res.push_back(i+1)
nums[4]=8 nums[5]=2 res=[4+1,5+1]=[5,6]
Therefore,5 and 6 are disappeared numbers;
```

### 代码
```C++
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        if(nums.empty()) return res;
        for(int i=0;i<nums.size();++i){
            int index=(nums[i]-1)%nums.size();
            nums[index]=nums[index]+nums.size();
        }
        for(int i=0;i<nums.size();++i){
            if(nums[i]<=nums.size()) res.push_back(i+1);
        }
        return res;
    }
};
```