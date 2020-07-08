# 18(106) 从中序与后序遍历序列构造二叉树(Medium)
## 描述

根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

## 示例
```bash
例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

``` 

## Description

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

## Example

```bash
For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty()) return NULL;
        TreeNode* root=new TreeNode(postorder[postorder.size()-1]);//后序遍历的最后一个序列为根结点
        vector<int> inorder_left,inorder_right,postorder_left,postorder_right;
        int i;
        for(i=0;i<inorder.size();++i){
            if(inorder[i]==root->val) break;
            inorder_left.push_back(inorder[i]);
        }//中序遍历根结点的左子树存入inorder_left
        for(++i;i<inorder.size();++i){
            inorder_right.push_back(inorder[i]);
        }//中序遍历根结点的右子树存入inorder_right
        for(int j=0;j<postorder.size()-1;++j){
            //遍历postorder数组中除了最后一个根结点的部分 从 0-size()-1
            //将inorder_left.size()数量的元素存入postorder_left中 为后序遍历左子树
            if(j<inorder_left.size()) postorder_left.push_back(postorder[j]);
            //剩余元素存入postorder_right中 为后序遍历右子树
            else postorder_right.push_back(postorder[j]);
        }
        root->left=buildTree(inorder_left,postorder_left);
        root->right=buildTree(inorder_right,postorder_right);
        return root;
    }
};

```