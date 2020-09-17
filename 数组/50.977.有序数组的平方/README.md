# 50(977) 有序数组的平方

## 描述

给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

## 示例

```bash

示例 1：

输入：[-4,-1,0,3,10]
输出：[0,1,9,16,100]
示例 2：

输入：[-7,-3,2,3,11]
输出：[4,9,9,49,121]

``` 

提示：

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A 已按非递减顺序排序。

## Description

Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

## Example

```bash

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]

```

Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.


`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

双指针解决问题

从A数组的左右两端比较绝对值的大小 将较大的平方值放置在res数组的尾部 然后向前移动放置的位置

### 代码

```C++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());
        int left=0,right=A.size()-1;
        int i=right;
        while(i>=0){
            if(-A[left]<A[right]){
                res[i]=A[right]*A[right];
                right--;
            }
            else {
                res[i]=A[left]*A[left];
                left++;
            }
            --i;
        }
        return res;
    }
};
```