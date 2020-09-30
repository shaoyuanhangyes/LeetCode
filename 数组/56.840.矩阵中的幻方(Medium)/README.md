# 56(840) 矩阵中的幻方(Medium)

## 描述

3 x 3 的幻方是一个填充有从 1 到 9 的不同数字的 3 x 3 矩阵，其中每行，每列以及两条对角线上的各数之和都相等。

给定一个由整数组成的 grid，其中有多少个 3 × 3 的 “幻方” 子矩阵？（每个子矩阵都是连续的）。

## 示例

```bash

示例 1:

输入: [[4,3,8,4],
      [9,5,1,9],
      [2,7,6,2]]
输出: 1
解释: 
下面的子矩阵是一个 3 x 3 的幻方：
438
951
276

而这一个不是：
384
519
762

总的来说，在本示例所给定的矩阵中只有一个 3 x 3 的幻方子矩阵。

``` 

提示:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
0 <= grid[i][j] <= 15

## Description

A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).

## Example

```bash

Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:

438
951
276

while this one is not:

384
519
762

In total, there is only one magic square inside the given grid.

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

题目的中文翻译和提示简直不能看

要想满足每行每列对角线上的各数之和都相等 则这个3X3子矩阵的中间元素必定是数字5

### 代码

```C++
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int di[8]={-1,-1,-1,0,1,1,1,0};
        int dj[8]={-1,0,1,1,1,0,-1,-1};
        int count=0;
        for(int i=1;i<grid.size()-1;++i){
            for(int j=1;j<grid[0].size()-1;++j){
                if(grid[i][j]==5){
                    vector<int> around;
                    for(int k=0;k<8;k++){
                        around.push_back(grid[i+di[k]][j+dj[k]]);
                    }
                    count+=IsMagic(around);
                }
            }
        }
        return count;
    }
    bool IsMagic(vector<int>& v){
        for(int i=0;i<8;i+=2){
            if(m[i]==v[0]) return v==vector<int>(m.begin()+i,m.begin()+i+8)||v==vector<int>(m.rbegin()+7-i,m.rbegin()+15-i);
        }
        return false;
    }

private:
    vector<int> m={8,1,6,7,2,9,4,3,8,1,6,7,2,9,4,3};
};
```