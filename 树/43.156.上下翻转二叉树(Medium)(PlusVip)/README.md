# 43(156) 上下翻转二叉树(Medium)

156. Binary Tree Upside Down

## 描述

给定一个二叉树，其中所有的右节点要么是具有兄弟节点（拥有相同父节点的左节点）的叶节点，要么为空，将此二叉树上下翻转并将它变成一棵树， 原来的右节点将转换成左叶节点。返回新的根。

## 示例

```
输入: [1,2,3,4,5]

    1
   / \
  2   3
 / \
4   5

输出: 返回二叉树的根 [4,5,2,#,#,3,1]

   4
  / \
 5   2
    / \
   3   1  

```

## Description

Given the root of a binary tree, turn the tree upside down and return the new root.

You can turn a binary tree upside down with the following steps:

The original left child becomes the new root.
The original root becomes the new right child.
The original right child becomes the new left child.

The mentioned steps are done level by level, it is guaranteed that every node in the given tree has either 0 or 2 children.

## Example

```bash

Example 1:

Input: root = [1,2,3,4,5]
Output: [4,5,2,null,null,3,1]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]

```

Constraints:

The number of nodes in the tree will be in the range [0, 10].
1 <= Node.val <= 10
Every node has either 0 or 2 children.

`Linkedln` `Google` `Microsoft` `Amazon` `Facebook` `Uber` `Yahoo`

## 解题

题目很晦涩难懂 首先先来剖析一下题意

1. 给出的二叉树中所有结点的右子树 要么是叶子结点 要么是NULL
2. 翻转的规则为:原树的最左的结点成为新根 原树的根成为新根的右结点 原树的根的右结点成为新根的左结点 

(太拗口了!!!! 上图解!)

```bash
    1
   / \
  2   3


原树的最左的结点成为新根 所以2是新根
原树的根成为新根的右结点 所以1是2的右结点
原树的根的右结点成为新根的左结点 所以3是2的右结点

    2
   / \
  3   1
```

(与其叫上下翻转不如说顺时针旋转....)

题意剖析完毕 接下来举例分析不同情况

情况1 root={} 直接返回空树

情况2 root={1} 只有根结点 直接返回根结点

情况3 题目给的例子 root={1,2,3,4,5}

```bash
    1         1        4
   / \       /        / \ 
  2   3     2 — 3    5   2
 / \       /            / \
4   5     4 — 5        3   1
```

本质就是 对三个结点的连接关系进行修改 

情况分析完毕 开始代码构思

因为最左的结点会成为新根 所以很自然想到dfs找到最左的结点 每一层的三个结点都需要改变连接关系 所以可以使用递归思想

三个结点改变连接关系的核心代码:

```C++
root->left->right=root;//原树的根成为新根的右结点
root->left->left=root->right;//原树的根的右结点成为新根的左结点
root->left=NULL;//原根成为了右结点 一定没有孩子结点 所以断链
root->right=NULL;
```

### 代码

```C++

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root==NULL||(root->left==NULL&&root->right==NULL)) return root;
        TreeNode* newroot=upsideDownBinaryTree(root->left);
        root->left->right=root;
        root->left->left=root->right;
        root->left=NULL;
        root->right=NULL;
        return newroot;
    }
};

```

```
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：9.7 MB, 在所有 C++ 提交中击败了17.56%的用户
```