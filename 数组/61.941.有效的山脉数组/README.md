# 61(941) 有效的山脉数组

## 描述

给定一个整数数组 A，如果它是有效的山脉数组就返回 true，否则返回 false。

让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组：

A.length >= 3
在 0 < i < A.length - 1 条件下，存在 i 使得：
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]

## 示例

```bash

示例 1：

输入：[2,1]
输出：false
示例 2：

输入：[3,5,5]
输出：false
示例 3：

输入：[0,3,2,1]
输出：true

``` 

提示：

0 <= A.length <= 10000
0 <= A[i] <= 10000 

## Description

Given an array A of integers, return true if and only if it is a valid mountain array.

Recall that A is a mountain array if and only if:

A.length >= 3
There exists some i with 0 < i < A.length - 1 such that:
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]

## Example

```bash

Example 1:

Input: [2,1]
Output: false
Example 2:

Input: [3,5,5]
Output: false
Example 3:

Input: [0,3,2,1]
Output: true

```

Note:

0 <= A.length <= 10000
0 <= A[i] <= 10000 


`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题



### 代码

```C++
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<3) return false;
        int left=0,right=A.size()-1;
        while(left<A.size()-1&&A[left]<A[left+1]){
            left++;
        }
        while(right>0&&A[right]<A[right-1]){
            right--;
        }
        if(left==right&&left>0&&right<A.size()-1) return true;
        else return false;
    }
};
```