# 5(5) 最长回文子串(Medium)

## 描述

给你一个字符串 s，找到 s 中最长的回文子串

## 示例

```bash

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"

``` 

提示：

1 <= s.length <= 1000
s 仅由数字和英文字母组成

## Description

Given a string s, return the longest palindromic substring in s.

## Example

```bash

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"

```

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.


`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

### 解法一 动态规划

字符串长度为1时 显然是回文串 `S(i,i) = true`
字符串长度为2时 只要两个字符相同 就是回文串 `S(i,i+1) = S[i]==s[i+1]`
字符串长度大于2时 `S(i,j) = S(i+1,j-1)&&S[i]==S[j]` 
```bash
# S(i,j)表示字符串S从第i位到第j位组成的串是回文串 
# S[i]表示字符串第i位的字符
```

求得的回文串长度最大值为 `j-i+1`

#### 代码

```C++
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;
        int maxLen = 1;
        int begin = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        for (int L = 2; L <= n; ++L) {
            for (int i = 0; i < n; ++i) {
                int j = L + i - 1;  // j-i+1=L
                if (j >= n) break;
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};
```
时间复杂度 O(n^2) n为字符串的长度
空间复杂度 O(n^2) 