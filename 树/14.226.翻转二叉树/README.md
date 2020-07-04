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
### 递归解法
```bash
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        root->left=invertTree(root->left);
        root->right=invertTree(root->right);
        /*swap(root->left,root->right)*/
        TreeNode* node=root->left;
        root->left=root->right;
        root->right=node;
        /*交换左右子树*/
        return root;
    }
};
```
### 栈迭代解法
```bash
class Solution {
public:
    TreeNode* invertTree(TreeNode* root){
        if(root==NULL) return NULL;
        stack<TreeNode*> st;
        st.push(root);
        while(st.size()){
            TreeNode* node=st.top();
            st.pop();

            TreeNode* temp=node->left;
            node->left=node->right;
            node->right=temp;

            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        return root;
    }
};
```