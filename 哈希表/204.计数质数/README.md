# 204 计数质数

## 描述

统计所有小于非负整数 n 的质数的数量。

## 示例

```bash

示例 1：

输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

示例 2：

输入：n = 0
输出：0

示例 3：

输入：n = 1
输出：0
``` 

提示：

0 <= n <= 5 * 106

## Description
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

## Example

Count the number of prime numbers less than a non-negative number, n.

```bash

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:

Input: n = 0
Output: 0

Example 3:

Input: n = 1
Output: 0
```

Constraints:

0 <= n <= 5 * 106

`Google` `Microsoft` `Amazon` `BitDance` `Apple` `HuaWei` `Oracle` `Tencent` `Facebook` `Intel` `Adobe` `eBay` `Uber` `Baidu` `Alibaba` `Thunder`

## 解题

### 方法一 枚举法

枚举所有的数字来判断是否为质数 使用计数器来记录质数的个数 

在判断是否为质数的过程中 可以进行一些优化 首先 枚举从2开始 除2之外的所有偶数都为质数 所以可以只判断奇数 需要遍历的空间就被压缩了 时间复杂度为$O(\sqrt n)$

检查单个数是否为质数的时间复杂度为$O(\sqrt n)$ 检查n个数 时间复杂度变为$O(n\sqrt n)$

cpp代码通过的结果为勉强通过 go等其他语言就会超时 毕竟时间复杂度太庞大了  

#### 代码
```C++
class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        for(int i=2;i<n;++i){
            count+=isPrimes(i);
        }
        return count;
    }
private:
    bool isPrimes(int n){
        for(int i=2;i*i<=n;++i){
            if(n%i==0) return false;
        }
        return true;
    }
};
```

### 方法二 埃氏筛

枚举没有考虑到数与数的关联性，因此难以再继续优化时间复杂度

希腊数学家Eratosthenes提出，称为厄拉多塞筛法，简称埃氏筛。

若一个数x为质数 那么2x 3x ...等x的整数倍都不是质数 以这个数之间的关联为突破点

初始化一个数组isPrime[n]容纳n个数 数组中存放对应数组坐标的数i是否为质数 若是质数 则存1 若为合数 则存0 从[2,n)遍历所有的数 若某个数为质数 则将其所有整数倍都标记为合数

遍历的次数还可以继续压缩 倘若一个数x为质数 2x 3x 为合数 此时 2x不仅仅是x的整数倍 还是2的整数倍 早就被标记过了  所以可以直接从x*x开始标记  注意整型变量溢出

#### 代码

```C++
class Solution {
public:
    int countPrimes(int n) {

    }
};
```