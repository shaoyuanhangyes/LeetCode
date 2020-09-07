# 42(877) 石子游戏(Medium)

## 描述

亚历克斯和李用几堆石子在做游戏。偶数堆石子排成一行，每堆都有正整数颗石子 piles[i] 。

游戏以谁手中的石子最多来决出胜负。石子的总数是奇数，所以没有平局。

亚历克斯和李轮流进行，亚历克斯先开始。 每回合，玩家从行的开始或结束处取走整堆石头。 这种情况一直持续到没有更多的石子堆为止，此时手中石子最多的玩家获胜。

假设亚历克斯和李都发挥出最佳水平，当亚历克斯赢得比赛时返回 true ，当李赢得比赛时返回 false 。

## 示例

```bash

输入：[5,3,4,5]
输出：true
解释：
亚历克斯先开始，只能拿前 5 颗或后 5 颗石子 。
假设他取了前 5 颗，这一行就变成了 [3,4,5] 。
如果李拿走前 3 颗，那么剩下的是 [4,5]，亚历克斯拿走后 5 颗赢得 10 分。
如果李拿走后 5 颗，那么剩下的是 [3,4]，亚历克斯拿走后 4 颗赢得 9 分。
这表明，取前 5 颗石子对亚历克斯来说是一个胜利的举动，所以我们返回 true 。

``` 

提示：

2 <= piles.length <= 500
piles.length 是偶数。
1 <= piles[i] <= 500
sum(piles) 是奇数。

## Description

Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.

Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.

## Example

```bash

Input: piles = [5,3,4,5]
Output: true

Explanation: 
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.

```

Constraints:

2 <= piles.length <= 500
piles.length is even.
1 <= piles[i] <= 500
sum(piles) is odd.

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

### 方法一 动态规划

`dp[i][j]`表示剩下区间[i-j]的石子中 最佳取石子方式下的得分差值(最大分数) 并且取石子只能取i或j位置的石子 所以dp[i][j]的取值为piles[i]-dp[i+1][j] and piles[j]-dp[i][j-1]的较大值 (假如第一个人拿了i位置的石子 第二个人就只能从区间[i+1 - j]选择 同理 第一个人选择了j位置的石子 第二个人就只能从区间[i - j-1]选择) 假如只剩下i这一堆石子 那么只能拿这一堆 所以`dp[i][i]=piles[i]`

所以`dp[i][j]=max(piles[i]-dp[i+1][j],piles[j]-dp[i][j-1]);` 

在外层循环中使用k表示区间i-j的差值 假设数组长度为4 先计算出dp[0][1] dp[1][2] dp[2][3] 再计算dp[0][2] dp[1][3] 最后计算dp[0][3] 最后判断dp[0][3]是否大于0

```C++
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<int> temp(piles.size(),0);
        vector<vector<int>> dp(piles.size(),temp);
        for(int i=0;i<piles.size();++i){
            dp[i][i]=piles[i];
        }
        for(int k=1;k<piles.size();++k){
            for(int i=0,j=i+k;j<piles.size();++i,++j){
                dp[i][j]=max(piles[i]-dp[i+1][j],piles[j]-dp[i][j-1]);
            }
        }
        return dp[0][piles.size()-1];
    }
};
```

### 方法二 数学推导

因为`piles.size()`一定是偶数 所以 可以将piles数组内元素 按照 一 二 一 二的原则分为第一组和第二组  那么数组元素第一个元素一定是第一组的 最后一个元素一定是第二组的 取石子只能从两端开始取

所以Alex先手取石子的时候 可以选择属于第一组的也可以选择属于第二组的 假设Alex选择了第一组的 剩余的数组元素的两端都是第二组元素 所以Lee只能选择属于第二组元素的石子 Lee选择后 数组变成了首位元素和末位元素分别属于不同组的情况 Alex又可以有两种选择 我们假设他就一直选第一组的 这样Lee就只能拿第二组的 因此我们只要确保Alex选择的那一组元素的总和一定大于Lee选择的另一组元素的总和即可 

所以 先手必胜

```C++
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
```