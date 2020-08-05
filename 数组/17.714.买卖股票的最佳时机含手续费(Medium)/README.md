# 17(714) 买卖股票的最佳时机含手续费(Medium)

## 描述

给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

## 示例
```bash

输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
输出: 8
解释: 能够达到的最大利润:  
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
注意:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.

``` 

## Description

Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

## Example
```bash

Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Note:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`


## 解题

### 动态规划

#### DP方程分析

`dp[i][j]` i表示第i-1天 j=0表示持有股票 j=1表示不持有股票 

初始条件: `dp[0][0]=-prices[0]`  `dp[0][1]=0`

状态转移方程: 
`dp[i][0]=max(dp[i-1][0],dp[i-1][1]-prices[i])` 

`dp[i][1]=dp[i-1][0]+prices[i]-fee` 


终止条件: `maxProfit=dp[n-1][1]`

#### 代码

```C++
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size()<=1) return 0;
        int n=prices.size();
        int dp[n][2];
        dp[0][0]=-prices[0];
        dp[0][1]=0;//LC的编译器声明数组的时候初值都是随机数 clion初始化是0
        for(int i=1;i<n;++i){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]-prices[i]);
            dp[i][1]=max(dp[i-1][0]+prices[i]-fee,dp[i-1][1]);
        }
        return dp[n-1][1];
    }
};
```

```
执行用时：264 ms, 在所有 C++ 提交中击败了37.28%的用户
内存消耗：52.3 MB, 在所有 C++ 提交中击败了38.94%的用户
```