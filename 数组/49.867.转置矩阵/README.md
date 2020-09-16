# 49(867) 转置矩阵

## 描述


给定一个矩阵 A， 返回 A 的转置矩阵。

矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。

## 示例

```bash

示例 1：

输入：[[1,2,3],[4,5,6],[7,8,9]]
输出：[[1,4,7],[2,5,8],[3,6,9]]
示例 2：

输入：[[1,2,3],[4,5,6]]
输出：[[1,4],[2,5],[3,6]]

``` 

提示：

1 <= A.length <= 1000
1 <= A[0].length <= 1000

## Description

Given a matrix A, return the transpose of A.

The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.

## Example

```bash

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:

Input: [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]

```

Note:

1 <= A.length <= 1000
1 <= A[0].length <= 1000


`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

一次遍历

观察矩阵元素的下标

```
00 01 02       --->  00 01
10 11 12       --->  10 11
               --->  20 21
``` 

转置后的矩阵元素下标是原矩阵对应元素下标的行列互换

原矩阵A的行 `rows=A.size()` A的列 `cols=A[0].size()`

转换后矩阵res的行为cols 列为rows i从`0-rows*cols` 转置 `res[i/rows][i%rows]=A[i%rows][i/rows]`

### 代码

```C++
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int rows=A.size();
        int cols=A[0].size();
        vector<vector<int>> res(cols,vector<int>(rows,0));
        for(int i=0;i<cols*rows;++i){
            res[i/rows][i%rows]=A[i%rows][i/rows];
        }
        return res;
    }
};
```