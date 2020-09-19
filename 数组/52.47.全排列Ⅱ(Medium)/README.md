# 52(47) 全排列Ⅱ(Medium)

## 描述

给定一个可包含重复数字的序列，返回所有不重复的全排列。

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

解题基本上与 [全排列](https://github.com/shaoyuanhangyes/LeetCode/tree/master/%E6%95%B0%E7%BB%84/51.46.%E5%85%A8%E6%8E%92%E5%88%97(Medium)) 相同 不同的地方在于要处理重复数字 额外处理重复数字的代码会在下面讲解中提醒

使用回溯法解决

temp数组存被选中的数字 used数组用来当作标记位 `used[i]=1`时 表示i对应的`nums[i]`已经被temp选中了 只能选之后的数字 `used[i]=0`表示i对应的`nums[i]`还未被选中 `usedNum`用来记录被选中数字的个数有多少 当被选中数字的个数等于数组的长度的时候 意味着temp中存了所有的nums数组中的数字 就可以将temp数组存入二维数组res中

选中数字存入temp后 将used[i]置为1 然后递归执行dfs函数 此时函数变量中usedNum需要加上1位 来表示被选中的数字+1 

递归执行完毕返回时 需要回溯到选择该数字的出发点 即将选中数字的used[i]置0 并删除在temp中的存储 

<b>解决重复数字带来的重复排列问题</b>

当给出的序列不包含重复数字的时候 不需要考虑数组是否有序 因为数组中每一个数都是唯一的 所以有序无序无所谓 

但当给出的序列包含重复数字的时候 将数组变为有序的可以方便我们肉眼观察出重复的数字在哪里 因为重复的数字会紧挨着 这一特点也给出了解决重复数字的办法 

首先将给出的序列排序 `sort(nums.begin(),nums.end());`

接下来就和全排列一样 开始递归执行深搜代码 处理for循环内部变量的时候 需要注意 某个重复的数字只允许有第一次可以参加排列 下一次再遇到重复数字直接跳过处理 所以针对重复数字 需要判断Ⅰ`nums[i-1]==nums[i]` Ⅱ但是仅仅判断这一个是不够的 因为i-1 所以会发生i的上溢出 所以i>0一定要成立 这里也可以理解为i=0的第一次循环是一定会执行的 Ⅲ`!used[i-1]` 即`used[i-1]!=0` 之所以做这样的处理是因为 temp数组将序列送到res存储后 会一步步的清空temp和used数组标记位 所以nums[i-1]被选中过后它的标记位used[i-1]会从1变回0 当`nums[i]==nums[i-1]&&used[i-1]!=0`同时满足的时候意味着重复数字nums[i-1]被选中过当作temp数组的头部 所以跳过这次循环即可  而处理temp数组内部填满元素的时候这个判断永远不成立 所以不用担心内部填满的时候因为重复跳过

最好的理解办法就是在dfs函数处打断点跑一遍代码

### 代码

dfs函数传参变量有点冗杂 要是能使用全局变量就简洁多了

```C++
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        sort(nums.begin(),nums.end());
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
            if(i>0&&nums[i-1]==nums[i]&&!used[i-1]) continue;
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