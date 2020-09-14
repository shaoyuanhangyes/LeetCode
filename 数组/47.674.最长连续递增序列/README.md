# 47(674) 最长连续递增序列

## 描述

给定一个未经排序的整数数组，找到最长且连续的的递增序列，并返回该序列的长度。

## 示例

```bash

示例 1:

输入: [1,3,5,4,7]
输出: 3
解释: 最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。 
示例 2:

输入: [2,2,2,2,2]
输出: 1
解释: 最长连续递增序列是 [2], 长度为1。


``` 

注意：数组长度不会超过10000。

## Description

Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).


## Example

```bash

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1. 

```

Note: Length of the array will not exceed 10,000.

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题


### 代码

```C++
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res=1;
        int temp=1;
        for(int i=0;i+1<nums.size();++i){
            if(nums[i+1]>nums[i]){
                temp++;
            }
            else{
                temp=1;
            }
            res=max(res,temp);
        }
        return res;
    }
};
```