# 19(213) 打家劫舍Ⅱ

## 描述

你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。


## 示例
```bash

示例 1:

输入: [2,3,2]
输出: 3
解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
示例 2:

输入: [1,2,3,1]
输出: 4
解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。

``` 

## Description

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.


## Example

```bash
Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`


## 解题

### 二维动态规划

#### DP方程分析

`dp[i][j]`表示偷取的最大收益 i表示偷第i家 j=0表示没有偷取第0家 j=1表示偷取了第0家

初始状态 `dp[0][0]=0` `dp[0][1]=nums[0]` `dp[1][0]=nums[1]` `dp[1][1]=nums[0]`

转移方程 `dp[i][0]=max(dp[i-2][0]+nums[i],dp[i-1][0])` `dp[i][1]=max(dp[i-2][1]+nums[i],dp[i-1][1])`

在i=n-1即偷取最后一家的时候需要做些修改 在偷取最后一家的时候 分为偷取过了第0家和未偷取第0家 这两种情况 

if(i==n-1){
    未偷取第0家 则可以偷取最后一家 因此转移方程不变 `dp[i][0]=max(dp[i-2][0]+nums[i],dp[i-1][0])`
    偷取过第0家 则不能偷取最后一家 因此最大收益为上一次的收益 转移方程为 `dp[i][1]=dp[i-1][1]` 
}

终止状态 `maxProfit=max(dp[n-1][0],dp[n-1][1])`

#### 代码

```C++
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n=nums.size();
        if(n==1) return nums[0];
        int dp[n][2];
        dp[0][0]=0;dp[0][1]=nums[0];
        dp[1][0]=nums[1];dp[1][1]=nums[0];
        for(int i=2;i<n;++i){
            if(i==n-1){//偷取最后一家
                dp[i][0]=max(dp[i-2][0]+nums[i],dp[i-1][0]);
                dp[i][1]=dp[i-1][1];
            }
            else{
                dp[i][0]=max(dp[i-2][0]+nums[i],dp[i-1][0]);
                dp[i][1]=max(dp[i-2][1]+nums[i],dp[i-1][1]);
            }
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};
```

```
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：7.9 MB, 在所有 C++ 提交中击败了57.33%的用户
```