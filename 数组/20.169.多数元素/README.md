# 20(169) 多数元素
## 描述

给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

## 示例
```bash
示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2
``` 

## Description

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

## Example
```bash
Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

```
`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

### 利用哈希表

```C++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        int majority=0,count=0;
        for(int i=0;i<nums.size();++i){
            m[nums[i]]++;
            if(m[nums[i]]>count){
                majority=nums[i];
                count=m[nums[i]];
            }
        }
        return majority;
    }
};
```

```
执行用时：40 ms
内存消耗：9 MB
```

### 利用排序

因为众数的条件是 指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素 

所以对于一个有序的数组 数组的index为[n/2]的位置的数一定是这个数组的众数

eg: `nums={1,2,3,3}` `nums[nums.size()/2]=nums[2]=3` `nums={1,2,2}` `nums[nums.size()/2]=nums[1]=2`

```C++
class Solution {
public:
    int majorityElement(vector<int>& nums){
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};
```

```
执行用时：60 ms
内存消耗：8.8 MB
```