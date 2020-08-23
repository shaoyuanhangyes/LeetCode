# 29(219) 存在重复元素Ⅱ

## 描述

给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。


## 示例

```bash

示例 1:

输入: nums = [1,2,3,1], k = 3
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1
输出: true
示例 3:

输入: nums = [1,2,3,1,2,3], k = 2
输出: false


``` 

## Description

Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

## Example

```bash

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

### 代码

利用哈希表

```C++
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()<2) return false;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();++i){
            if(m.find(nums[i])!=m.end()){
                int distance=abs(i-m[nums[i]]);
                if(distance<=k) return true;
                m[nums[i]]=i;//距离不满足要求 因此需要更新哈希表中被查找到的这个元素的index
            }
            else m[nums[i]]=i;//哈希表中不存在nums[i]就插入哈希表中
        }
        return false;
    }
};
```

```
执行用时：48 ms, 在所有 C++ 提交中击败了94.89%的用户
内存消耗：16.2 MB, 在所有 C++ 提交中击败了48.99%的用户
```