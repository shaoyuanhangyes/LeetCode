# 12(123) 买卖股票的最佳时机Ⅲ
## 描述


给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 <b>两笔</b> 交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

## 示例
```bash
输入: [3,3,5,0,0,3,1,4]
输出: 6
解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3:

输入: [7,6,4,3,1] 
输出: 0 
解释: 在这个情况下, 没有交易完成, 所以最大利润为 0。

``` 

## Description
Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

## Example
```bash
Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
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

```
`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

### 三维动态规划
`dp[i][j][k]` i表示索引为i的位置 j=0表示现金 j=1表示股票 k有0 1 2取值 分别表示购买了0 1 2次股票
所以`dp[i][j][k]`表示索引为i的那天 用户手上持股状态为j所获得的最大利润

#### DP方程分析

不持有股票:
 未卖出过 `dp[i][0][0]=dp[i-1][0][0]`
 卖出一次 昨天未持有股票`dp[i-1][0][1]` or 昨天持有股票 今天第一次将股票卖出`dp[i-1][1][0]+prices[i]` 所以 `dp[i][0][1]=max(dp[i-1][0][1],dp[i-1][1][0]+prices[i]);`
 卖出两次 昨天未持有股票`dp[i-1][0][2]` or 昨天持有股票 已经卖出过一次 今天第二次将股票卖出 `dp[i-1][1][1]+prices[i]` 所以 `dp[i][0][2]=max(dp[i-1][0][2],dp[i-1][1][1]+prices[i]);`

持有股票: 
 未卖出 `dp[i][1][0]=dp[i-1][1][0]` or 昨天未持有 今天买入 `dp[i-1][0][0]-prices[i]` 所以 `dp[i][1][0]=max(dp[i-1][1][0],dp[i-1][0][0]-prices[i]);`
 卖出一次 昨天持有股票 但之前卖出一次 `dp[i-1][1][1]` or 昨天未持有 之前已卖出一次 今天第二次买入 `dp[i-1][0][1]-prices[i]` 所以 `dp[i][1][1]=max(dp[i-1][1][1],dp[i-1][0][1]-prices[i]);`
 卖出两次 昨天持有股票 但之前卖出二次 根据题目 最多交易次数二次 所以 `dp[i-1][1][2]`不存在

#### 开始状态

第一天若持有股票 不管卖出次数是否存在 值都为`dp[0][1][?]=-prices[0]`
第一天不持有股票 不管卖出次数是否存在 `dp[0][1][?]=0`

#### 状态中止 

获取最大收益的时候 一定是不持有股票 可能卖出过一次 可能卖出过两次
所以 `max_profit=max(dp[len-1][0][2],dp[len-1][0][1]);`
```C++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int len=prices.size();
        int dp[len][2][3];
        dp[0][0][0]=dp[0][0][1]=dp[0][0][2]=0;
        dp[0][1][0]=dp[0][1][1]=dp[0][1][2]=-prices[0];
        for(int i=1;i<len;++i){
            dp[i][0][0]=0;
            dp[i][0][1]=max(dp[i-1][0][1],dp[i-1][1][0]+prices[i]);
            dp[i][0][2]=max(dp[i-1][0][2],dp[i-1][1][1]+prices[i]);
            dp[i][1][0]=max(dp[i-1][1][0],dp[i-1][0][0]-prices[i]);
            dp[i][1][1]=max(dp[i-1][1][1],dp[i-1][0][1]-prices[i]);
            dp[i][1][2]=0;
        }
        return max(dp[len-1][0][2],dp[len-1][0][1]);
    }
};
```