# 16(70) 爬楼梯

## 描述

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

## 示例
```bash

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶

示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

``` 

## Description

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

## Example
```bash

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45

```
`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

### 动态规划

#### 状态分析

1个台阶 f(1)=1种方法 1
2个台阶 f(2)=2种方法 1+1/2
3个台阶 f(3)=3种方法 1+1+1/1+2/2+1
4个台阶 f(4)=5种方法 1+1+1+1/1+1+2/1+2+1/2+1+1/2+2
......
n个台阶 f(n)=f(n-1)+f(n-2)种方法 

初始状态 `stairs[0]=1` `stairs[1]=1` 以此类推 `stairs[2]=stairs[0]+stairs[1]` ...... 正确
终止状态 `stairs[n]`为所求

#### DP代码
```C++
class Solution {
public:
    int climbStairs(int n) {
        vector<int> stairs(n+1,1);
        for(int i=2;i<=n;++i){
            stairs[i]=stairs[i-1]+stairs[i-2];
        }
        return stairs[n];
    }
};
```

```
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：6.3 MB, 在所有 C++ 提交中击败了12.51%的用户
```