# 29(404)  左叶子之和
## 描述

计算给定二叉树的所有左叶子之和。

## 示例

```bash

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

``` 

## Description

Find the sum of all left leaves in a given binary tree.

## Example

```bash

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`

## 解题

### 递归解法

递归判断条件:
 以root为根节点的树的左子树之和=root的左子树的左叶子之和+root的右子树的左叶子之和
 若当前root结点不存在左子树 就返回当前root结点右子树的左叶子之和
 若当前root结点的左子树是一个叶子结点 就返回当前root结点左叶子的值+右子树的左叶子之和
 若当前root结点不存在 返回0
```c++
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return sumOfLeftLeaves(root->right);
        if(!root->left->left&&!root->left->right) return root->left->val+sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
    }
};
```

```
执行用时：4 ms, 在所有 C++ 提交中击败了88.59%的用户
内存消耗：13.4 MB, 在所有 C++ 提交中击败了68.29%的用户
```
