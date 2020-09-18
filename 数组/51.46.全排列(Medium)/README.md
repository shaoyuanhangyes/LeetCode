# 51(46) 全排列

## 描述

给定一个 没有重复 数字的序列，返回其所有可能的全排列。给定一个 没有重复 数字的序列，返回其所有可能的全排列。

## 示例

```bash

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

``` 

## Description

Given a collection of distinct integers, return all possible permutations.

## Example

```bash

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

回溯法解决

temp数组存被选中的数字 used数组用来当作标记位 `used[i]=1`时 表示i对应的`nums[i]`已经被temp选中了 只能选之后的数字 `used[i]=0`表示i对应的`nums[i]`还未被选中 `usedNum`用来记录被选中数字的个数有多少 当被选中数字的个数等于数组的长度的时候 意味着temp中存了所有的nums数组中的数字 就可以将temp数组存入二维数组res中

选中数字存入temp后 将used[i]置为1 然后递归执行dfs函数 此时函数变量中usedNum需要加上1位 来表示被选中的数字+1 

递归执行完毕返回时 需要回溯到选择该数字的出发点 即将选中数字的used[i]置0 并删除在temp中的存储 

### 代码

dfs函数传参变量有点冗杂 要是能使用全局变量就简洁多了

```C++
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        vector<int> temp;
        vector<int> used(nums.size(),0);
        int usedNum=0;
        dfs(res,nums,temp,used,usedNum);
        return res;
    }
    void dfs(vector<vector<int>>& res,vector<int>& nums,vector<int>& temp,vector<int>& used,int usedNum){
        if(usedNum==nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(used[i]==0){
                used[i]=1;
                temp.push_back(nums[i]);
                dfs(res,nums,temp,used,usedNum+1);
                used[i]=0;
                temp.pop_back();
            }
        }
        return;
    }
};
```