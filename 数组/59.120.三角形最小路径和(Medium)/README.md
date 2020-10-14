# 59(120) 三角形最小路径和(Medium)

## 描述

给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。

## 示例

```bash

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

``` 

说明：

如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

## Description

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

## Example

```bash

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

```

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.


`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

`dp[i][j]`表示从`triangle[0][0]---triangle[i][j]`的最小路径和

初始条件 `dp[0][0]=triangle[0][0]`

相邻节点的计算 `dp[i][j]=min(dp[i-1][j-1]+triangle[i][j],dp[i-1][j]+triangle[i][j])` 简化为  `dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j]`

矩阵的边界 左边界: `dp[i][0]=dp[i-1][0]+triangle[i][0]` 右边界: dp[i][i]=dp[i-1][i-1]+triangle[i][i];

其中左边界要在相邻节点计算之前完成 右边界要在相邻节点计算之后完成

`int n=triangle.size()` 随着循环计算 dp[n-1][0] --- dp[n-1][n-1] 中存储了对应元素的最小路径和 

返回二维数组dp的最后一行中的最小值即可 这里使用到了#include<algorithm>中的 *min_element()

`*min_element(dp[n-1].begin(),dp[n-1].end())`就是最后一行中最小的元素

### 代码

```C++
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;++i){
            dp[i][0]=dp[i-1][0]+triangle[i][0];
            for(int j=1;j<i;++j){
                dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
            }
            dp[i][i]=dp[i-1][i-1]+triangle[i][i];
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};
```