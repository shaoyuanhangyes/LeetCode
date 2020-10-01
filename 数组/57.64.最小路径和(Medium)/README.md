# 57(64) 最小路径和(Medium)

## 描述

给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

## 示例

```bash

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

``` 

## Description

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

## Example

```bash

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

动态规划解决

dp[i][j]表示从左上角dp[0][0]-右下角dp[i][j]的最小路径和 i为数组的rows j为数组的cols

`dp[0][0]=grid[0][0]`

`dp[i][j]=min(dp[i-1][j]+grid[i][j],dp[i][j-1]+grid[i][j])` or `dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j]`

在进行动态方程的求解的时候 需要先将矩阵的边界路径和设置好 即dp[i][0] and dp[0][j]

`dp[i][0]=dp[i-1][0]+grid[i][0]` `dp[0][j]=dp[0][j-1]+grid[0][j]`

最后返回dp[grid.size()][grid[0].size()]即可

### 代码

```C++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()||grid[0].empty()) return 0;
        int rows=grid.size(),cols=grid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        dp[0][0]=grid[0][0];
        for(int i=1;i<rows;++i){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int j=1;j<cols;++j){
            dp[0][j]=dp[0][j-1]+grid[0][j];
        }
        for(int i=1;i<rows;++i){
            for(int j=1;j<cols;++j){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[rows-1][cols-1];
    }
};
```