# 17(105) 从前序与中序遍历序列构造二叉树(Medium)
## 描述

根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

## 示例
```bash
例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]

返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
``` 

## Description

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.


## Example

```bash
For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`

## 解题

### 递归解法
```bash

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;
        TreeNode* root=new TreeNode(preorder[0]);
        vector<int> preorder_left, inorder_left, preorder_right, inorder_right;
        int i;
        for(i=0;i<inorder.size();++i){
            if(inorder[i]==root->val) break;
            inorder_left.push_back(inorder[i]);
        }//中序遍历根结点的左子树存入inorder_left
        for(++i;i<inorder.size();++i){
            inorder_right.push_back(inorder[i]);
        }//中序遍历根结点的右子树存入inorder_right
        for(int j=1;j<preorder.size();++j){
            //根据中序遍历左子树的长度来确定前序遍历左子树存入preorder_left
            if(j<=inorder_left.size()) preorder_left.push_back(preorder[j]);
                //前序遍历剩下的为右子树 存入前序遍历右子树序列preorder_right
            else preorder_right.push_back(preorder[j]);
        }
        root->left=buildTree(preorder_left,inorder_left);
        root->right=buildTree(preorder_right,inorder_right);
        return root;
   }
};

```