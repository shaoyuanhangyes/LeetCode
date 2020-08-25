# 30(268) 缺失数字

## 描述

给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。


## 示例

```bash

示例 1:

输入: [3,0,1]
输出: 2
示例 2:

输入: [9,6,4,2,3,5,7,0,1]
输出: 8

``` 
说明:
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?

## Description

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

## Example

```bash

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8

```

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

使用位运算中的异或来解决问题

异或 xor ^ 运算性质为两个相同的数异或结果为0 一个数与0异或 结果是它自己 并且异或运算满足交换律

假设数组为 `[3,0,1]` 将数组元素的值与所在位置下标index逐个异或 即 `(0^3)^(1^0)^(2^1) = (0^0)^(1^1)^2^3` 再将这个结果与数组的长度进行异或 即 `(0^0)^(1^1)^2^(3^3)` 观察得只有2(缺失的那个数字) 是落单的 并且 这串异或的结果为 `0^2=2` 即结果就是缺失的数字

### 代码


```C++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res=nums.size();
        for(int i=0;i<nums.size();++i){
            res^=i^nums[i];
        }
        return res;
    }
};
```