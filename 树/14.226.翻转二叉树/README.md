# 14(226) 翻转二叉树
## 描述

翻转一棵二叉树。

## 示例
```bash

输入:
     4
   /   \
  2     7
 / \   / \
1   3 6   9

输出:
     4
   /   \
  7     2
 / \   / \
9   6 3   1

``` 
备注:
这个问题是受到 [Max Howell](https://twitter.com/mxcl) 的 [原问题](https://twitter.com/mxcl/status/608682016205344768) 启发的:

```
谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。
```

## Description

Invert a binary tree.

## Example

```bash

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9

Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
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