# 22(119) 杨辉三角Ⅱ

## 描述

给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行

在杨辉三角中，每个数是它左上方和右上方的数的和。

## 示例

```bash
输入: 3
输出: [1,3,3,1]

``` 
进阶：

你可以优化你的算法到 O(k) 空间复杂度吗？

## Description

Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.

## Example

```bash

Input: 3
Output: [1,3,3,1]
```

Follow up:

Could you optimize your algorithm to use only O(k) extra space?

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

杨辉三角 国外称帕斯卡三角 (Pascal's Triangle) 

### 直接解法

在118.杨辉三角的代码直接输出第`rowIndex`行

```C++
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        for(int i=0;i<=rowIndex;++i){
            vector<int> temp(i+1,1);
            res.push_back(temp);
        }
        for(int i=0;i<=rowIndex;++i){
            for(int j=1;j<i;++j){
                res[i][j]=res[i-1][j-1]+res[i-1][j];
            }
        }
        return res[rowIndex];
    }
};
```

### 进阶解法

从后向前累加

```bash
[1]         0
[1,1]       1
 1+1
  =2
[1,2,1]     2
   2+1
    =3
 1+2
  =3   
[1,3,3,1]   3

    ...
    以此类推 
```

```C++
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for(int i=0;i<=rowIndex;++i){
            for(int j=i;j>1;j--){
                res[j-1]+=res[j-2];
            }
            res.push_back(1);
        }
        return res;
    }
};
```

```
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：6.5 MB, 在所有 C++ 提交中击败了61.72%的用户
```