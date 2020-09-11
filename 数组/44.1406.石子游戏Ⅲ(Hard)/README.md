# 44(1406) 石子游戏Ⅲ(Hard)

## 描述

Alice 和 Bob 用几堆石子在做游戏。几堆石子排成一行，每堆石子都对应一个得分，由数组 stoneValue 给出。

Alice 和 Bob 轮流取石子，Alice 总是先开始。在每个玩家的回合中，该玩家可以拿走剩下石子中的的前 1、2 或 3 堆石子 。比赛一直持续到所有石头都被拿走。

每个玩家的最终得分为他所拿到的每堆石子的对应得分之和。每个玩家的初始分数都是 0 。比赛的目标是决出最高分，得分最高的选手将会赢得比赛，比赛也可能会出现平局。

假设 Alice 和 Bob 都采取 最优策略 。如果 Alice 赢了就返回 "Alice" ，Bob 赢了就返回 "Bob"，平局（分数相同）返回 "Tie" 。

## 示例

```bash

示例 1：

输入：values = [1,2,3,7]
输出："Bob"
解释：Alice 总是会输，她的最佳选择是拿走前三堆，得分变成 6 。但是 Bob 的得分为 7，Bob 获胜。
示例 2：

输入：values = [1,2,3,-9]
输出："Alice"
解释：Alice 要想获胜就必须在第一个回合拿走前三堆石子，给 Bob 留下负分。
如果 Alice 只拿走第一堆，那么她的得分为 1，接下来 Bob 拿走第二、三堆，得分为 5 。之后 Alice 只能拿到分数 -9 的石子堆，输掉比赛。
如果 Alice 拿走前两堆，那么她的得分为 3，接下来 Bob 拿走第三堆，得分为 3 。之后 Alice 只能拿到分数 -9 的石子堆，同样会输掉比赛。
注意，他们都应该采取 最优策略 ，所以在这里 Alice 将选择能够使她获胜的方案。
示例 3：

输入：values = [1,2,3,6]
输出："Tie"
解释：Alice 无法赢得比赛。如果她决定选择前三堆，她可以以平局结束比赛，否则她就会输。
示例 4：

输入：values = [1,2,3,-1,-2,-3,7]
输出："Alice"
示例 5：

输入：values = [-1,-2,-3]
输出："Tie"

``` 

提示：

1 <= values.length <= 50000
-1000 <= values[i] <= 1000

## Description

Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2 or 3 stones from the first remaining stones in the row.

The score of each player is the sum of values of the stones taken. The score of each player is 0 initially.

The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

Assume Alice and Bob play optimally.

Return "Alice" if Alice will win, "Bob" if Bob will win or "Tie" if they end the game with the same score.

## Example

```bash

Example 1:

Input: values = [1,2,3,7]
Output: "Bob"
Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.
Example 2:

Input: values = [1,2,3,-9]
Output: "Alice"
Explanation: Alice must choose all the three piles at the first move to win and leave Bob with negative score.
If Alice chooses one pile her score will be 1 and the next move Bob's score becomes 5. The next move Alice will take the pile with value = -9 and lose.
If Alice chooses two piles her score will be 3 and the next move Bob's score becomes 3. The next move Alice will take the pile with value = -9 and also lose.
Remember that both play optimally so here Alice will choose the scenario that makes her win.
Example 3:

Input: values = [1,2,3,6]
Output: "Tie"
Explanation: Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise she will lose.
Example 4:

Input: values = [1,2,3,-1,-2,-3,7]
Output: "Alice"
Example 5:

Input: values = [-1,-2,-3]
Output: "Tie"

```

Constraints:

1 <= values.length <= 50000
-1000 <= values[i] <= 1000

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

dp[i]表示剩下i个石子的时候  Alice能拿到的最多石子数量 

dp[i]=max(dp[i],sum-dp[i+j]) sum为剩余i个石子的总和

所以dp[0]表示石子全部拿完后 Alice能拿到的最多石子数量 Bob能拿到的石子数量就是sum-dp[0]

最后比较Alice拿到的dp[0] and Bob拿到的Sum-dp[0] 谁的值大返回谁 平就返回"Tie"
### 代码

```C++
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size()+3,0);
        int sum=0;
        for(int i=stoneValue.size()-1;i>=0;--i){
            dp[i]=INT_MIN;
            sum+=stoneValue[i];
            for(int j=1;j<=3;++j){
                dp[i]=max(dp[i],sum-dp[i+j]);
            }
        }
        if(dp[0]>sum-dp[0]) return "Alice";
        else if(dp[0]<sum-dp[0]) return "Bob";
        else return "Tie";
    }
};
```