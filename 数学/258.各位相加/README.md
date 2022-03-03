# 258 各位相加

## 描述

给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。返回这个结果

## 示例

```bash

示例 1:

输入: num = 38
输出: 2 
解释: 各位相加的过程为：
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2
由于 2 是一位数，所以返回 2。
示例 1:

输入: num = 0
输出: 0


``` 

提示：

0 <= num <= 231 - 1

进阶：你可以设计一个时间复杂度为 O(1) 的解决方案吗？

## Description

Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

## Example

```bash

Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
Example 2:

Input: num = 0
Output: 0


```

Constraints:

0 <= num <= 231 - 1


Follow up: Could you do it without any loop/recursion in O(1) runtime?


`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`


## 解题

### 方法一 简单的取余操作 

直接从个位开始向高位开始累加 

#### 代码

```C++
class Solution {
public:
   int addDigits(int num) {
      while (num >= 10) {
         int sum = 0;
         while (num > 0) {
            sum = sum + num % 10;
            num /= 10;
         }
         num = sum;
      }
      return num;
   }
};
```

### 方法二 寻找数学规律

假设一个三位数`xyz` 值为`v1 = 100*x + 10*y + 1*z` 经过一次各位相加后 值为`v2 = x + y + z` 
v1与v2的差值为`v1-v2 = 99*x + 99y` 这个差值可以被9整除  因此每一次循环都缩小了9的倍数 
所以v1与v2满足同余定理(v1和v2对9有相同的余数) 而这个余数就是我们想要求得的 因此直接将`num%9`即可

特殊值问题: 若num为9 那么9%9=0 但答案应该是9才对 所以当num能被9整除的时候 直接取余是无法得到想要的结果的 
因此 需要对num进行偏移 由观察可知 0%9=0  所以可以对num进行-1的偏移 这样就能将被9整除的情况避免掉 
对最后取余的结果再+1回正

#### 代码

```C++
class Solution {
public:
    int addDigits(int num) {
        return (num-1)%9 + 1;
    }
};
```