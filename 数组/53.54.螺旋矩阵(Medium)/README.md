# 53(54) 螺旋矩阵(Medium)

## 描述

给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

## 示例

```bash

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

``` 

## Description

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

## Example

```bash

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题


### 代码

```C++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int up=0,down=matrix.size()-1,left=0,right=matrix[0].size()-1;
        while(true){
            for(int i=left;i<=right;++i){
                res.push_back(matrix[up][i]);
            }
            if(++up>down) break;
            for(int i=up;i<=down;++i){
                res.push_back(matrix[i][right]);
            }
            if(--right<left) break;
            for(int i=right;i>=left;--i){
                res.push_back(matrix[down][i]);
            }
            if(--down<up) break;
            for(int i=down;i>=up;--i){
                res.push_back(matrix[i][left]);
            }
            if(++left>right) break;
        }
        return res;
    }
};
```