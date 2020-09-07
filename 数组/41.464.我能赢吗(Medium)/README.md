# 41(464) 我能赢吗(Medium)

## 描述

在 "100 game" 这个游戏中，两名玩家轮流选择从 1 到 10 的任意整数，累计整数和，先使得累计整数和达到或超过 100 的玩家，即为胜者。

如果我们将游戏规则改为 “玩家不能重复使用整数” 呢？

例如，两个玩家可以轮流从公共整数池中抽取从 1 到 15 的整数（不放回），直到累计整数和 >= 100。

给定一个整数 maxChoosableInteger （整数池中可选择的最大数）和另一个整数 desiredTotal（累计和），判断先出手的玩家是否能稳赢（假设两位玩家游戏时都表现最佳）？

你可以假设 maxChoosableInteger 不会大于 20， desiredTotal 不会大于 300。

## 示例

```bash

输入：
maxChoosableInteger = 10
desiredTotal = 11

输出：
false

解释：
无论第一个玩家选择哪个整数，他都会失败。
第一个玩家可以选择从 1 到 10 的整数。
如果第一个玩家选择 1，那么第二个玩家只能选择从 2 到 10 的整数。
第二个玩家可以通过选择整数 10（那么累积和为 11 >= desiredTotal），从而取得胜利.
同样地，第一个玩家选择任意其他整数，第二个玩家都会赢。


``` 

## Description

In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.

Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise return false. Assume both players play optimally.

## Example

```bash

Example 1:

Input: maxChoosableInteger = 10, desiredTotal = 11
Output: false
Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.

Example 2:

Input: maxChoosableInteger = 10, desiredTotal = 0
Output: true

Example 3:

Input: maxChoosableInteger = 10, desiredTotal = 1
Output: true

```

Constraints:

1 <= maxChoosableInteger <= 20
0 <= desiredTotal <= 300


`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

根据题意 求的是最坏情况下的最优解 也是极小化极大算法问题(Minimax) 要求局部最大值 全局最小值

既然是求最优解 那必须要考虑到所有的情况 因此使用动态规划求解

### 思路

`dp[i][j]`是指最终答案在区间`[i-j]`时的最小花费

使用几个例子证明一下: 

dp[1][1]=0 因为在只有1的时候猜1必然猜中 cost=0
dp[1][2]=1 在1 2之间进行猜测 答案是1的时候 猜1 cost=0/猜2 cost=2 ;答案是2的时候 猜1 cost=1/猜2 cost=0 所以dp[1][2]=min(max(0,2),max(1,0))=1
dp[1][3]=2 在1 2 3之间进行猜测 答案是1的时候 猜1 cost=0/猜2 cost=2/猜3 cost=3+dp[1][2] 答案是2的时候 猜1 cost=1+dp[2][3]/猜2 cost=0/猜3 cost=3+dp[1][2] 所以dp[1][3]=min(max(0,2,3+dp[1][2]),max(1+dp[2][3],0),3+dp[1][2])=2
···以此类推
最终求得`dp[1][n]`

通过观察得知 dp[i][i]的值都是0 因此在代码的二维数组中 初始化为INT_MAX 然后将区间端点值相同的即`dp[i][i]`全部置0

通过循环求区间`[i-j]`的最小花费 j从2向n推进 i在每次j的取值基础上从j-1向1推进

```
<i j · · · · · n
<- i j · · · · n
<- - i j · · · n
<- - - i j · · n
<- - - - i j · n
<- - - - - i j n
```

在每次i-j推进中使用 `k` 来分割i-j区间 使其变成`[i - k-1]` k `[k+1 - j]` 求得非两端处的`dp[i][j]=min(k+max(dp[i][k-1],dp[k+1][j]),dp[i][j])`

最后再把端点处的情况单独拿出来处理 即分割点是i or j 若分割点是i 则`dp[i][j]=min(dp[i][j],i+dp[i+1][j])` 若分割点是 则`dp[i][j]=min(dp[i][j],dp[i][j-1]+j)`

最后返回 `dp[1][n]`
#### 代码

```C++
class Solution{
public:
    int getMoneyAmount(int n){
        vector<int> temp(n+1,INT_MAX);
        vector<vector<int>> dp(n+1,temp);
        for(int i=0;i<=n;++i){
            dp[i][i]=0;
        }
        for(int j=2;j<=n;++j){
            for(int i=j-1;i>=1;--i){
                for(int k=i+1;k<=j-1;k++){
                    dp[i][j]=min(k+max(dp[i][k-1],dp[k+1][j]),dp[i][j]);
                }
                dp[i][j]=min(dp[i][j],i+dp[i+1][j]);
                dp[i][j]=min(dp[i][j],dp[i][j-1]+j);
            }
        }
        return dp[1][n];
    }
};
```