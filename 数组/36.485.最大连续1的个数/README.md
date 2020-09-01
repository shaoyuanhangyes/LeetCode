# 36(485) 最大连续1的个数

## 描述

给定一个二进制数组， 计算其中最大连续1的个数。

## 示例

```bash

输入: [1,1,0,1,1,1]
输出: 3
解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.

``` 

注意：

输入的数组只包含 0 和1。
输入数组的长度是正整数，且不超过 10,000。

## Description

Given a binary array, find the maximum number of consecutive 1s in this array.

## Example

```bash

Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.

```

Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

注意数组中遇不到0的情况 这样count就一直增长下去 所以最后要返回`max_contiune` and `count`的最大值

### 代码

```C++
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.empty()) return 0;
        int max_continue=0;
        int count=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0) {
                max_continue=count>max_continue?count:max_continue;
                count=0;
            }
            if(nums[i]==1){
                count++;
            }
        }
        return max(max_continue,count);
    }
};
```