# 4(1447) 最简分数(Medium)

## 描述

给你一个整数 n ，请你返回所有 0 到 1 之间（不包括 0 和 1）满足分母小于等于  n 的 最简 分数 。分数可以以 任意 顺序返回。

## 示例

```bash

示例 1：

输入：n = 2
输出：["1/2"]
解释："1/2" 是唯一一个分母小于等于 2 的最简分数。
示例 2：

输入：n = 3
输出：["1/2","1/3","2/3"]
示例 3：

输入：n = 4
输出：["1/2","1/3","1/4","2/3","3/4"]
解释："2/4" 不是最简分数，因为它可以化简为 "1/2" 。
示例 4：

输入：n = 1
输出：[]

``` 

提示：

1 <= n <= 100

## Description

Given an integer n, return a list of all simplified fractions between 0 and 1 (exclusive) such that the denominator is less-than-or-equal-to n. You can return the answer in any order.

## Example

```bash

Example 1:

Input: n = 2
Output: ["1/2"]
Explanation: "1/2" is the only unique fraction with a denominator less-than-or-equal-to 2.
Example 2:

Input: n = 3
Output: ["1/2","1/3","2/3"]
Example 3:

Input: n = 4
Output: ["1/2","1/3","1/4","2/3","3/4"]
Explanation: "2/4" is not a simplified fraction because it can be simplified to "1/2".

```

Constraints:

1 <= n <= 100


`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

使用gcd算法(Greatest Common Divisor 即最大公约数)来实现 虽然gcd算法可以直接调用 但此题解法的精妙之处就在于手动模拟实现gcd算法 采用的是欧几里得算法即辗转相除法

欧几里得算法

```C++
int mygcd(int a, int b) {
    return b == 0 ? a : mygcd(b, a % b);
}
```

通过`mygcd`函数判断分母j分子j的最大公约数是否为1 若最大公约数为1 则说明分子分母互质 无法化简 加入结果数组res中 若最大公约数不为1 则说明分子分母可以化简 舍弃

### 代码

```C++

class Solution {
  public:
   vector<string> simplifiedFractions(int n) {
      vector<string> res;
      for (int i = 2; i <= n; ++i) {
         for (int j = 1; j < i; ++j) {
            if (mygcd(i, j) == 1)
               res.push_back(to_string(j) + "/" + to_string(i));
         }
      }
      return res;
   }
   int mygcd(int a, int b) {
      return b == 0 ? a : mygcd(b, a % b);
   }
};

```