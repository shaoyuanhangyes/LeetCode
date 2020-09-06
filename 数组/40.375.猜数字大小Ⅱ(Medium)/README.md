# 40(375) 猜数字大小Ⅱ(Medium)

## 描述

我们正在玩一个猜数游戏，游戏规则如下：

我从 1 到 n 之间选择一个数字，你来猜我选了哪个数字。

每次你猜错了，我都会告诉你，我选的数字比你的大了或者小了。

然而，当你猜了数字 x 并且猜错了的时候，你需要支付金额为 x 的现金。直到你猜到我选的数字，你才算赢得了这个游戏。

## 示例

```bash

n = 10, 我选择了8.

第一轮: 你猜我选择的数字是5，我会告诉你，我的数字更大一些，然后你需要支付5块。
第二轮: 你猜是7，我告诉你，我的数字更大一些，你支付7块。
第三轮: 你猜是9，我告诉你，我的数字更小一些，你支付9块。

游戏结束。8 就是我选的数字。

你最终要支付 5 + 7 + 9 = 21 块钱。

``` 

给定 n ≥ 1，计算你至少需要拥有多少现金才能确保你能赢得这个游戏。

## Description

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay `$x`. You win the game when you guess the number I picked.


## Example

```bash

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

```

Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.


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