# 16(98) 验证二叉搜索树(Medium)
## 描述

给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

## 示例
```bash
输入:
    2
   / \
  1   3
输出: true

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

``` 

## Description

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

## Example

```bash
    2
   / \
  1   3

Input: [2,1,3]
Output: true

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`

## 解题

利用二叉搜索树的性质 二叉搜索树的中序遍历序列一定是增序 这里有一个测试用例的坑 就是设置的最小值key 必须将类型设置为long long的参数`LLONG_MIN`(#define LLONG_MIN (-9223372036854775807ll - 1)  limits.h)
将出栈的结点值与key相比较 如果比key大 就将此值赋予key 然后继续操作

```bash
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node=root;
        long long key=LLONG_MIN;
        while(!st.empty()||node){
            while(node){
                st.push(node);
                node=node->left;
            }
            node=st.top();
            st.pop();
            if(node->val<=key) return false;
            key=node->val;
            node=node->right;
        }
        return true;
    }
};
```