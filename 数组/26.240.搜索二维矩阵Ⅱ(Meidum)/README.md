# 26(240) 搜索二维矩阵Ⅱ(Medium)

## 描述

编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。

## 示例

```bash

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。

``` 

## Description

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

## Example

```bash

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

### 双指针缩小领域

观察矩阵 发现从矩阵的右上角开始 它下面的元素都比它大 它左面的元素都比他小 

因此可以从此处为搜索的起点 值比target小就向左移动 值比target大就向下移动

这样就可以缩短搜索的范围 

同理起点选择左下角的元素也可以

### 代码
```C++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int rows=matrix.size();
        int cols=matrix[0].size();
        int l=0,r=cols-1;
        while(l<rows&&r>=0){
            if(matrix[l][r]==target) return true;
            else if(matrix[l][r]>=target) --r;
            else ++l;
        }
        return false;
    }
};
```

```
执行用时：148 ms, 在所有 C++ 提交中击败了57.42%的用户
内存消耗：10.7 MB, 在所有 C++ 提交中击败了58.68%的用户
```

