# 60(1207) 独一无二的出现次数

## 描述

给你一个整数数组 `arr`，请你帮忙统计数组中每个数的出现次数。

如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false

## 示例

```bash

示例 1：

输入：arr = [1,2,2,1,1,3]
输出：true
解释：在该数组中，1 出现了 3 次，2 出现了 2 次，3 只出现了 1 次。没有两个数的出现次数相同。
示例 2：

输入：arr = [1,2]
输出：false
示例 3：

输入：arr = [-3,0,1,-3,1,1,1,-3,10,0]
输出：true

``` 

提示：

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000

## Description

Given an array of integers `arr`, write a function that returns true if and only if the number of occurrences of each value in the array is unique.


## Example

```bash

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true

```

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000


`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

```
arr = 1 2 2 1 1 3
      0 1 2 3 
count 0 3 2 1
judge 0 1 1 1
```
`count[i]`表示i在arr中出现的次数frequence
judge统计frequence是否出现过 1为出现过 0为未出现

### 代码

```C++
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> count(2001,0);
        vector<int> judge(1001,0);
        for(int i=0;i<arr.size();++i){
            count[arr[i]+1000]++;
        }
        for(int i=0;i<count.size();++i){
            if(count[i]){
                if(judge[count[i]]==0) judge[count[i]]=true;
                else return false;
            }
        }
        return true;
    }
};
```