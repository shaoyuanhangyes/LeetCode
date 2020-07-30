# 15(343) 整数拆分(Hard)

## 描述

给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

## 示例
```bash
示例 1:

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
说明: 你可以假设 n 不小于 2 且不大于 58。

``` 

## Description

Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

## Example
```bash

Example 1:

Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
Note: You may assume that n is not less than 2 and not larger than 58.

```
`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

### 动态规划

#### DP方程分析

`dp[i]`表示将正整数i拆分成两个整数的最大乘积 

i>1的时候 假设对i进行拆分出的第一项是j `(1<j<i)` 则有:
` i = i-j + j ` 且i-j不能拆分成多个正整数 此时的乘积为 `j*(i-j)` or `j*dp[i-j]`

所以 dp[i]=`max(j*(i-j),j*dp[i-j])` j从1-i

#### 开始状态

`dp[0]=dp[1]=0` 

#### 终止状态

返回`dp[n]`

```C++
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        for(int i=2;i<dp.size();++i){
            int curMax=0;
            for(int j=1;j<i;++j){
                curMax=max(curMax,max(j*(i-j),j*dp[i-j]));
            }
            dp[i]=curMax;
        }
        return dp[n];
    }
};

```

```bash
执行用时：4 ms, 在所有 C++ 提交中击败了31.28%的用户
内存消耗：6.1 MB, 在所有 C++ 提交中击败了63.16%的用户
```

### 数学思想