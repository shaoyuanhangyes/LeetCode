# 12(110) 平衡二叉树
## 描述

给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

## 示例
```bash

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 
``` 

## Description

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

## Example

```bash

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
 Return false.
```
`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`
## 解题

```bash
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int D_Value=abs(maxDepth(root->left)-maxDepth(root->right));//abs()绝对值函数
        return (D_Value<=1)&&isBalanced(root->left)&&isBalanced(root->right);
    }
    int maxDepth(TreeNode* root) {//递归深度优先算法
        if(root==NULL) return 0;
        int l_len=maxDepth(root->left)+1;
        int r_len=maxDepth(root->right)+1;
        return l_len>r_len?l_len:r_len;
    }
};
```