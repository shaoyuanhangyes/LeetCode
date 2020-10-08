# 39(437) 路径总和Ⅲ(Medium)

## 描述

给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

## 示例

```bash 

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:

1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11

```

## Description

You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

## Example

```bash

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`


## 解题

### 递归解法

node_pathSum函数负责以root为根的子树共存在多少条符合要求的路径 使用深度递归遍历的思想(先序遍历)

pathSum函数负责控制root是哪一个结点 使用深度递归遍历的思想(先序遍历) 将root是树中每一个结点的情况都考虑到

所以此题递归解法使用了双重dfs递归思想

#### 代码

```C++
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL) return 0;
        int total=0;
        total=node_pathSum(root,sum);
        if(root->left) total+=pathSum(root->left,sum);
        if(root->right) total+=pathSum(root->right,sum);
        return total;
    }
    int node_pathSum(TreeNode* root,int sum){
        if(root==NULL) return 0;
        int res=root->val==sum?1:0;
        sum-=root->val;
        if(root->left) res+=node_pathSum(root->left,sum);
        if(root->right) res+=node_pathSum(root->right,sum);
        return res;
    }
};
```