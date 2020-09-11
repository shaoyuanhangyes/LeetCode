# 45(1510) 石子游戏Ⅳ(Hard)

## 描述

Alice 和 Bob 两个人轮流玩一个游戏，Alice 先手。

一开始，有 n 个石子堆在一起。每个人轮流操作，正在操作的玩家可以从石子堆里拿走 任意 非零 平方数 个石子。

如果石子堆里没有石子了，则无法操作的玩家输掉游戏。

给你正整数 n ，且已知两个人都采取最优策略。如果 Alice 会赢得比赛，那么返回 True ，否则返回 False 。

## 示例

```bash

示例 1：

输入：n = 1
输出：true
解释：Alice 拿走 1 个石子并赢得胜利，因为 Bob 无法进行任何操作。
示例 2：

输入：n = 2
输出：false
解释：Alice 只能拿走 1 个石子，然后 Bob 拿走最后一个石子并赢得胜利（2 -> 1 -> 0）。
示例 3：

输入：n = 4
输出：true
解释：n 已经是一个平方数，Alice 可以一次全拿掉 4 个石子并赢得胜利（4 -> 0）。
示例 4：

输入：n = 7
输出：false
解释：当 Bob 采取最优策略时，Alice 无法赢得比赛。
如果 Alice 一开始拿走 4 个石子， Bob 会拿走 1 个石子，然后 Alice 只能拿走 1 个石子，Bob 拿走最后一个石子并赢得胜利（7 -> 3 -> 2 -> 1 -> 0）。
如果 Alice 一开始拿走 1 个石子， Bob 会拿走 4 个石子，然后 Alice 只能拿走 1 个石子，Bob 拿走最后一个石子并赢得胜利（7 -> 6 -> 2 -> 1 -> 0）。
示例 5：

输入：n = 17
输出：false
解释：如果 Bob 采取最优策略，Alice 无法赢得胜利。

``` 

提示：

1 <= n <= 10^5

## Description

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are n stones in a pile.  On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.

Given a positive integer n. Return True if and only if Alice wins the game otherwise return False, assuming both players play optimally.

## Example

```bash

Example 1:

Input: n = 1
Output: true
Explanation: Alice can remove 1 stone winning the game because Bob doesn't have any moves.
Example 2:

Input: n = 2
Output: false
Explanation: Alice can only remove 1 stone, after that Bob removes the last one winning the game (2 -> 1 -> 0).
Example 3:

Input: n = 4
Output: true
Explanation: n is already a perfect square, Alice can win with one move, removing 4 stones (4 -> 0).
Example 4:

Input: n = 7
Output: false
Explanation: Alice can't win the game if Bob plays optimally.
If Alice starts removing 4 stones, Bob will remove 1 stone then Alice should remove only 1 stone and finally Bob removes the last one (7 -> 3 -> 2 -> 1 -> 0). 
If Alice starts removing 1 stone, Bob will remove 4 stones then Alice only can remove 1 stone and finally Bob removes the last one (7 -> 6 -> 2 -> 1 -> 0).
Example 5:

Input: n = 17
Output: false
Explanation: Alice can't win the game if Bob plays optimally.

```

Constraints:

1 <= n <= 10^5

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

dp[i]表示还剩下i个石子的时候 Alice是否会赢得比赛 k表示每一次拿取k^2个石子 所以dp[i-k*k]表示剩下i个石子的时 Alice拿走了`k*k`个 然后剩余`i-k*k`个石子的时候 Bob能否赢得比赛 当`dp[i-k*k]`存在k使得`dp[i-k*k]=false` 就可以推出`dp[i]=true`

返回`dp[n]`即可

```bash
           true  : if(dp[i-k*k]=false) 存在任何一个k使得dp[i-k*k]=false  dp[i]=true
        /  
dp[i]=
        \  
           false : 不存在k使得dp[i-k*k]=false dp[i]=false

```

### 代码

```C++
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1,false);
        for(int i=1;i<=n;++i){
            for(int k=1;k*k<=i;++k){
                if(dp[i-k*k]== false){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
```