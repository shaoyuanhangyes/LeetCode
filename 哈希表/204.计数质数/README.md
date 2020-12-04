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

遍历的次数还可以继续压缩 倘若一个数x为质数 2x 3x 为合数 此时 2x不仅仅是x的整数倍 还是2的整数倍 早就被标记过了  所以最小未被过滤的就是x^2 可以直接从x^2开始标记  注意整型变量溢出 需要强制类型转换

创建一个数组 全部初始化为1 从2开始筛选 2必定是质数 所以将所有2的倍数对应的数组值变为0 边筛选边计数 这样可以节约一次遍历 

时间复杂度O(nloglogn)

#### 代码

```C++
class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrimes(n,1);
        int count=0;
        for(int i=2;i<n;++i){
            if(isPrimes[i]){
                count++;
                if((long long)i*i<n){
                    for(int j=i*i;j<n;j+=i){
                        isPrimes[j]=0;
                    }
                }
            }
        }
        return count;
    }
};
```

### 方法三 线性筛

埃氏筛依旧可以进行优化 比如45 在3将它标记为合数后 5又将它标记为合数 针对多次标记我们可以进行优化 目标为每个合数只会被标记一次 这样时间复杂度就会降低到O(n) 因此这个筛选方法才会被叫做线性筛

相较于埃氏筛 新初始化一个数组Primes 用于存放质数 在遍历过程中将质数添加到这个数组中 最终返回这个数组的元素个数

线性筛的核心在于避免多次标记合数 具体操作为针对正在遍历到的数i 我们从已知的质数数组中从小到大取出质数Primes[j] 将i*Primes[j] 把通过这样得到的一系列数全部都标记成合数 直到某个质数Primes[j]能够被i整除才停止

举例说明 i=15 将2*15 3*15 此时3能够被15整除 停止此轮标记 因为若不停止 会继续标记4*15 5*15... 其中5*15=75 3也能被75整除 所以75之后一定是会被3标记到的 并需要5来标记 这样的及时停止 可以帮助我们减少标记的次数 

#### 代码

```C++
class Solution {
public:
    int countPrimes(int n) {
        vector<int> Primes;
        vector<int> isPrimes(n,1);
        for(int i=2;i<n;++i){
            if(isPrimes[i]) Primes.push_back(i);
            for(int j=0;j<Primes.size()&&i*Primes[j]<n;++j){
                isPrimes[i*Primes[j]]=0;
                if(i%Primes[j]==0) break;
            }
        }
        return Primes.size();
    }
};
```