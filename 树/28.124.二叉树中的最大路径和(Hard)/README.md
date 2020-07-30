# 28(124)  二叉树中的最大路径和(Hard)
## 描述

给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

## 示例

```bash

示例 1:

输入: [1,2,3]

       1
      / \
     2   3

输出: 6
示例 2:

输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42

``` 

## Description

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

## Example

```bash

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`

## 解题

```c++
class Solution {
private: int res=INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
    int dfs(TreeNode* root){
        if(!root) return 0;
        int leftMaxPathSum=max(dfs(root->left),0);
        int rightMaxPathSum=max(dfs(root->right),0);
        res=max(res,root->val+leftMaxPathSum+rightMaxPathSum);
        return root->val+max(leftMaxPathSum,rightMaxPathSum);
    }
};
```

```
执行用时：40 ms, 在所有 C++ 提交中击败了91.40%的用户
内存消耗：28.6 MB, 在所有 C++ 提交中击败了24.10%的用户
```
