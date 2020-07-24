# 13(188) 买卖股票的最佳时机Ⅳ(Hard)

## 描述


给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 <b>k</b>笔交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。



## 示例
```bash
示例 1:

输入: [2,4,1], k = 2
输出: 2
解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
示例 2:

输入: [3,2,6,5,0,3], k = 2
输出: 7
解释: 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。

``` 

## Description
Say you have an array for which the i-th element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

## Example
```bash
Example 1:

Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

```
`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

### 二维动态规划

首先看k的取值 若`k>prices.size()/2` 此题就变成了无限次购买股票 但无限次购买股票也有利润上限 这个上限就可以用贪心算法求得 解法与[买卖股票的最佳时机Ⅱ](https://github.com/shaoyuanhangyes/LeetCode/tree/master/%E6%95%B0%E7%BB%84/11.122.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA%E2%85%A1)一模一样 

若`k<prices.size()/2` 创建dp方程

#### DP方程分析

`dp[i][j]` i表示第k次交易 j=0表示买入股票 j=1表示卖出股票 数组初始化完成后 设置起始条件
`dp[i][0]` 表示第i次买入 `dp[i][0]=max(dp[i][0],dp[i-1][1]-price)`
`dp[i][1]` 表示第i次卖出 `dp[i][1]=max(dp[i][1],dp[i][0]+price)`

#### 开始状态

`dp[0][0]`表示第一次买入 所以dp[0][0]=-prices[i] 这里用了c++11的循环形式 所以改写成了`dp[0][0]=-price`
`dp[0][1]`表示第一次卖出 所以`dp[0][1]=max(dp[0][1],dp[0][0]+price)`

#### 终止状态

最后返回 `dp[k-1][1]` 即第k次的卖出就是所得的最终利润
```C++

class Solution {
public:
    int maxProfit_infinite(vector<int>& prices){//解决k相当于无限次 跟Ⅱ一样
        int max_profit=0;
        for(int i=1;i<prices.size();++i){
            if(prices[i]>prices[i-1]) max_profit+=prices[i]-prices[i-1];
        }
        return max_profit;
    }
    int maxProfit(int k,vector<int>& prices){
        if(prices.size()<=1||k<1) return 0;
        int len=prices.size();
        if(k>len/2) return maxProfit_infinite(prices);
        int dp[k][2];
        for(int i=0;i<k;++i) {
            dp[i][0]=INT_MIN;dp[i][1]=INT_MIN;//全部初始化为INT_MIN
        }
        for(int price:prices){
            dp[0][0]=max(dp[0][0],-price);
            dp[0][1]=max(dp[0][1],dp[0][0]+price);
            for(int i=1;i<k;++i){
                dp[i][0]=max(dp[i][0],dp[i-1][1]-price);
                dp[i][1]=max(dp[i][1],dp[i][0]+price);
            }
        }
        return dp[k-1][1];
    }
};

```

```bash
执行用时：12 ms, 在所有 C++ 提交中击败了83.81%的用户
内存消耗：11.7 MB, 在所有 C++ 提交中击败了60.00%的用户
```