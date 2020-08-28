# 32(414) 第三大的数

## 描述

给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。

## 示例

```bash

示例 1:

输入: [3, 2, 1]

输出: 1

解释: 第三大的数是 1.
示例 2:

输入: [1, 2]

输出: 2

解释: 第三大的数不存在, 所以返回最大的数 2 .

示例 3:

输入: [2, 2, 3, 1]

输出: 1

解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
存在两个值为2的数，它们都排第二。

``` 

## Description

Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

## Example

```bash

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.

```


`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

```C++
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long n1=LONG_MIN;long n2=LONG_MIN;long n3=LONG_MIN;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>n1){
                n3=n2;n2=n1;n1=nums[i];
            }
            else if(nums[i]>n2 && nums[i]!=n1){
                n3=n2;n2=nums[i];
            }
            else if(nums[i]>n3 && nums[i]!=n1 && nums[i]!=n2) n3=nums[i];
        }
        return n3==LONG_MIN?n1:n3;
    }
};
```