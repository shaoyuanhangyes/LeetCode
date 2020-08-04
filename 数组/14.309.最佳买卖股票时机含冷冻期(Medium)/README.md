# 14(309) 最佳买卖股票时机含冷冻期(Medium)
## 描述

给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。

## 示例
```bash

输入: [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

``` 

## Description

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

## Example
```bash

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]

```
`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

### 动态规划

#### DP方程分析

`dp[i][j]` i表示第i-1天 j=0表示持有股票 j=1表示不持有股票 且处于冷却期 j=2表示不持有股票但不处于冷却期

初始条件: `dp[0][0]=-prices[0]` 

状态转移方程: 
`dp[i][0]=max(dp[i-1][0],dp[i-1][2]-prices[i])` 

`dp[i][1]=dp[i-1][0]+prices[i]` 

`dp[i][2]=max(dp[i-1][1],dp[i-1][2])`

终止条件: `maxProfit=max(dp[n-1][1],dp[n-1][2])`

#### 代码

```C++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int n=prices.size();
        int dp[n][3];
        dp[0][0]=-prices[0];dp[0][1]=0;dp[0][2]=0;
        for(int i=1;i<n;++i){
            dp[i][0]=max(dp[i-1][0],dp[i-1][2]-prices[i]);
            dp[i][1]=dp[i-1][0]+prices[i];
            dp[i][2]=max(dp[i-1][1],dp[i-1][2]);
        }
        return max(dp[n-1][1],dp[n-1][2]);
    }
};
```

```
执行用时：4 ms, 在所有 C++ 提交中击败了88.60%的用户
内存消耗：11.3 MB, 在所有 C++ 提交中击败了58.74%的用户
```