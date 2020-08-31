# 35(238) 除自身以外数组的乘积(Medium)

## 描述

给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

## 示例

```bash

输入: [1,2,3,4]
输出: [24,12,8,6]

``` 

提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。

说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

## Description

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

## Example

```bash

Input:  [1,2,3,4]
Output: [24,12,8,6]

```

Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

双指针同时算两边

```bash
nums = [1,2,3,4]
output=[1,1,1,1]
loop: 
i=0 output=[1,1,1,1]   left=1 right=4   更新output[0] and output[3]
i=1 output=[1,1,4,1]   left=2 right=12  更新output[1] and output[2]
i=2 output=[1,12,8,1]  left=6 right=24  更新output[2] and output[1]
i=3 output=[24,12,8,6] End              更新output[3] and output[0]
```

### 代码
```C++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(),1);
        int left=1,right=1;
        for(int i=0;i<nums.size();++i){
            output[i]*=left;
            left*=nums[i];
            output[nums.size()-1-i]*=right;
            right*=nums[nums.size()-1-i];
        }
        return output;
    }
};
```