# 33(687) 最长同值路径
## 描述

给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。

注意：两个节点之间的路径长度由它们之间的边数表示

## 示例
```bash 

示例 1:

输入:

              5
             / \
            4   5
           / \   \
          1   1   5

输出: 2

示例 2:

输入:

              1
             / \
            4   5
           / \   \
          4   4   5
输出: 2

``` 

注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。

## Description

Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

The length of path between two nodes is represented by the number of edges between them.


## Example

```bash
Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output: 2

 

Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output: 2

```

Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.


`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`

## 解题

### 变量释义

`maxPath` 是最长同值路径 全局变量 不停的刷新

`left` `right` 每次递归都初始化为0 最终表示当前root的左子树的最长同值路径 and 右子树的最长同值路径

`left_path` 记录着当前root的左子树已经有了left_path个同值路径 

`right_path` 记录着当前root的右子树已经有了right_path个同值路径

`left` `right`根据当前root结点的值和左右子树的值是否相等来进行刷新 若相等 `left right`就在相应的`_path`上加一

### 代码

```C++
class Solution {
public:
    int maxPath=INT_MIN;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left_path=dfs(root->left);
        int right_path=dfs(root->right);
        int left=0;int right=0;
        if(root->left!=NULL&&root->left->val==root->val) left+=left_path+1;
        if(root->right!=NULL&&root->right->val==root->val) right+=right_path+1;
        maxPath=max(maxPath,left+right);
        return max(left,right);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return maxPath;
    }
};
```

```
执行用时：32 ms, 在所有 C++ 提交中击败了63.23%的用户
内存消耗：29.6 MB, 在所有 C++ 提交中击败了19.29%的用户
```