# 39(374) 猜数字大小

## 描述

猜数字游戏的规则如下：

每轮游戏，系统都会从 1 到 n 随机选择一个数字。 请你猜选出的是哪个数字。
如果你猜错了，系统会告诉你，你猜测的数字比系统选出的数字是大了还是小了。
你可以通过调用一个预先定义好的接口 guess(int num) 来获取猜测结果，返回值一共有 3 种可能的情况（-1，1 或 0）：

-1 : 你猜测的数字比系统选出的数字大
 1 : 你猜测的数字比系统选出的数字小
 0 : 恭喜！你猜对了！


## 示例

```bash

输入: n = 10, pick = 6
输出: 6 

``` 

## Description


We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!


## Example

```bash

Input: n = 10, pick = 6
Output: 6. 

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题


### 代码

```C++
class Solution {
public:
    int guessNumber(int n) {
        int left=0,right=n;
        int mid=0;
        while(left<=right){
            mid=left+(right-left)/2;
            if(guess(mid)==0) break;
            else if(guess(mid)>0) left=mid+1;
            else right=mid-1;
        }
        return mid;
    }
};
```