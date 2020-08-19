# 25(74) 搜索二维矩阵(Medium)

## 描述

编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。


## 示例

```bash

示例 1:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
输出: true
示例 2:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
输出: false


``` 

## Description

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

## Example

```bash

Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

### 双指针缩小领域

```C++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int rows=matrix.size();
        int cols=matrix[0].size();
        if(rows>0&&cols>0){
            int l=0,r=cols-1;
            while(l<rows && r>=0){
                if(matrix[l][r]<target) l++;
                else if(matrix[l][r]>target) r--;
                else return true;
            }
        }
        return false;
    }
};
```

```
执行用时：8 ms, 在所有 C++ 提交中击败了85.55%的用户
内存消耗：7.7 MB, 在所有 C++ 提交中击败了42.28%的用户
```

### 二分查找

```C++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {//二分法
        if(matrix.empty()) return false;
        int l=0,r=matrix.size()*matrix[0].size()-1;
        int n=matrix[0].size();
        while(l<=r){
            int mid=(l+r)/2;
            if(matrix[mid/n][mid%n]==target) return true;
            else if(matrix[mid/n][mid%n]>target) r=mid-1;
            else l=mid+1;
        }
        return false;
    }
};
```

```
执行用时：8 ms, 在所有 C++ 提交中击败了85.55%的用户
内存消耗：7.6 MB, 在所有 C++ 提交中击败了68.49%的用户
```