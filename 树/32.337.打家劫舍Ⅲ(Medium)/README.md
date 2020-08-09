# 32(337) 打家劫舍Ⅲ(Medium)
## 描述

在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

## 示例
```bash 
示例 1:

输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

输出: 7 
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
示例 2:

输入: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.

``` 

## Description

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

## Example

```bash

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`

## 解题

### 动态规划

利用无序map来记录偷取值的和 `unordered_map<TreeNode*,int> f,g;`

`f[root]` 表示选择了root的偷取值最大的和 `g[root]` 表示未选择root的偷取值最大的和

因此 `f[root]=root->val+g[root->left]+g[root->right];` 因为选择了root root的左孩子右孩子就无法被选中 因此left和right是g

`g[root]=max(f[root->left],g[root->left])+max(f[root->right]+g[root->right]);` 因为root未被选中 root的左孩子右孩子不一定会被选中(depanding on sum count) 
而g只需要存未选择root的最大值的和就可以了 因此不必考虑左孩子右孩子是否被选中 只需要存最大值即可 

### 代码

```C++
class Solution {
public:
    unordered_map<TreeNode*,int> f,g;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        dfs(root->right);
        f[root]=root->val+g[root->left]+g[root->right];
        g[root]=max(f[root->left],g[root->left])+max(f[root->right],g[root->right]);
    }
    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root],g[root]);
    }
};
```

```
执行用时：32 ms, 在所有 C++ 提交中击败了63.23%的用户
内存消耗：29.6 MB, 在所有 C++ 提交中击败了19.29%的用户
```