# 46(1563) 石子游戏Ⅴ(Hard)

## 描述

几块石子 排成一行 ，每块石子都有一个关联值，关联值为整数，由数组 stoneValue 给出

游戏中的每一轮：Alice 会将这行石子分成两个 非空行（即，左侧行和右侧行）；Bob 负责计算每一行的值，即此行中所有石子的值的总和。Bob 会丢弃值最大的行，Alice 的得分为剩下那行的值（每轮累加）。如果两行的值相等，Bob 让 Alice 决定丢弃哪一行。下一轮从剩下的那一行开始

只 剩下一块石子 时，游戏结束。Alice 的分数最初为 0 

返回 Alice 能够获得的最大分数 

## 示例

```bash

示例 1：

输入：stoneValue = [6,2,3,4,5,5]
输出：18
解释：在第一轮中，Alice 将行划分为 [6，2，3]，[4，5，5] 。左行的值是 11 ，右行的值是 14 。Bob 丢弃了右行，Alice 的分数现在是 11 。
在第二轮中，Alice 将行分成 [6]，[2，3] 。这一次 Bob 扔掉了左行，Alice 的分数变成了 16（11 + 5）。
最后一轮 Alice 只能将行分成 [2]，[3] 。Bob 扔掉右行，Alice 的分数现在是 18（16 + 2）。游戏结束，因为这行只剩下一块石头了。
示例 2：

输入：stoneValue = [7,7,7,7,7,7,7]
输出：28
示例 3：

输入：stoneValue = [4]
输出：0

``` 

提示：

1 <= stoneValue.length <= 500
1 <= stoneValue[i] <= 10^6

## Description

There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.

The game ends when there is only one stone remaining. Alice's is initially zero.

Return the maximum score that Alice can obtain.

## Example

```bash

Example 1:

Input: stoneValue = [6,2,3,4,5,5]
Output: 18
Explanation: In the first round, Alice divides the row to [6,2,3], [4,5,5]. The left row has the value 11 and the right row has value 14. Bob throws away the right row and Alice's score is now 11.
In the second round Alice divides the row to [6], [2,3]. This time Bob throws away the left row and Alice's score becomes 16 (11 + 5).
The last round Alice has only one choice to divide the row which is [2], [3]. Bob throws away the right row and Alice's score is now 18 (16 + 2). The game ends because only one stone is remaining in the row.
Example 2:

Input: stoneValue = [7,7,7,7,7,7,7]
Output: 28
Example 3:

Input: stoneValue = [4]
Output: 0

```

Constraints:

1 <= stoneValue.length <= 500
1 <= stoneValue[i] <= 10^6

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

dp[i][j] 表示数组stoneValue从序号i到序号j的最优解

sum[p] 表示 前p个元素的值 Therefore `1<=p<=stoneValue.size()` 



### 代码

```C++
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        if(stoneValue.size()<=1) return 0;
        vector<int> sum(stoneValue.size()+1,0);
        vector<vector<int>> dp(stoneValue.size(),sum);
        for(int i=1;i<=stoneValue.size();++i){
            sum[i]=sum[i-1]+stoneValue[i-1];
        }
        for(int count=2;count<=stoneValue.size();++count){
            for(int i=0;i+count-1<stoneValue.size();++i){
                int j=i+count-1;
                if(count==2) dp[i][j]=min(stoneValue[i],stoneValue[j]);
                if(count>2){
                    for(int k=i+1;k<=j;++k){
                        if(sum[k]-sum[i] > sum[j+1]-sum[k]) {
                            dp[i][j]=max(dp[i][j],dp[k][j]+sum[j+1]-sum[k]);
                        }
                        else if(sum[k]-sum[i] < sum[j+1]-sum[k]) {
                            dp[i][j]=max(dp[i][j],dp[i][k-1]+sum[k]-sum[i]);
                        }
                        else{
                            dp[i][j]=max(dp[i][j],dp[k][j]+sum[j+1]-sum[k]);
                            dp[i][j]=max(dp[i][j],dp[i][k-1]+sum[k]-sum[i]);
                        }
                    }
                }
            }
        }
        return dp[0][stoneValue.size()-1];
    }
};
```