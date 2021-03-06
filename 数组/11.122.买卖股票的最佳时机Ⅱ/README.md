# 11(122) 买卖股票的最佳时机Ⅱ
## 描述

给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

## 示例
```bash
示例 1:

输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 

提示：

1 <= prices.length <= 3 * 10 ^ 4
0 <= prices[i] <= 10 ^ 4

``` 

## Description
Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

## Example
```bash
Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 

Constraints:

1 <= prices.length <= 3 * 10 ^ 4
0 <= prices[i] <= 10 ^ 4

```
`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题


### 贪心算法

只要后一天相比前一天能赚钱 贪心者就购入卖出 只注重眼前的利益
哪怕股票的价格为`[1,2,3,4,5]` 第一天买入第五天卖出 赚取`$4` 贪心者也会 第一天买入第二天卖出 第二天买入第三天卖出......第四天买入 第五天卖出 所赚取的资金为`(2-1)+(3-2)+(4-3)+(5-4)=4` 所赚取的收益是相同的
贪心算法的核心就是max_profit只加正数
```bash
class Solution {
public:
    int maxProfit(vector<int>& prices){//贪心算法
        if(prices.size()<=1) return 0;
        int max_profit=0;
        for(int i=1;i<prices.size();++i){
            max_profit+=max(prices[i]-prices[i-1],0);
        }
        return max_profit;
    }
};
```

### 动态规划1

状态转移方程 `if(prices[i]>prices[i-1]) dp[i]=dp[i-1]+prices[i]-prices[i-1] else dp[i]=dp[i-1]` 最后`dp[i]`就是累加的利润 也就是`max_profit`
```C++
class Solution {
public:
    int maxProfit(vector<int>& prices){//动态规划
        int max_profit=0;
        for(int i=1;i<prices.size();++i){
            if(prices[i]>prices[i-1]) max_profit+=prices[i]-prices[i-1];
        }
        return max_profit;
    }
};
```

### 动态规划2

#### step1 定义状态
`dp[i][j]` 
第一维i表示处于索引为i的那天能获得的最大值(考虑了之前天数的)利润 
第二维j表示处于索引为i的那天 是持有股票还是持有现金 0表示持有现金(cash) 1表示持有股票(stock) 持有现金意味着未购买股票 持有股票意味着未售出股票 

#### step2 状态转移方程
状态从持有现金即`dp[0][0]`开始 最后一天也就是`dp[len-1][0]`也是持有现金 每一天状态可以转移 也可以维持不动
状态的转移为`cash->stock->cash->stock......->cash`
```C++
dp[i][0]=max(dp[i-1][0],prices[i]+dp[i-1][1]);
dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
/*调换顺序也可以*/
```
#### step3 确定开始

第一天 若什么都不做 `dp[0][0]=0` 若买入股票 暂时收益为负 即`dp[0][1]=-prices[i]`

#### step4 确定终止
输出`dp[len-1][0]` 因为一定有`dp[len-1][0]>dp[len-1][1]`

```C++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int len=prices.size();
        vector<vector<int>> dp(len,vector<int> (2));
        //第二维的0表示cash 1表示stock
        dp[0][0]=0;dp[0][1]=-prices[0];
        for(int i=1;i<len;++i){
            dp[i][0]=max(dp[i-1][0],prices[i]+dp[i-1][1]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
        }
        return dp[len-1][0];
    }
};
```