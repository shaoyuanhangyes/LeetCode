# 21(119) 杨辉三角
## 描述

给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

在杨辉三角中，每个数是它左上方和右上方的数的和。

## 示例

```bash

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

``` 

## Description

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.


## Example

```bash

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

杨辉三角 国外称帕斯卡三角 (Pascal's Triangle) 

```C++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0;i<numRows;++i){
            vector<int> temp(i+1,1);
            res.push_back(temp);
        }
        for(int i=0;i<numRows;++i){
            for(int j=1;j<i;++j){
                res[i][j]=res[i-1][j-1]+res[i-1][j];
            }
        }
        return res;
    }
};
```
