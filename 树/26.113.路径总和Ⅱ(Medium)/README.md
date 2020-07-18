# 26(113) 路径总和Ⅱ(Medium)
## 描述

给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

## 示例

```bash

给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

``` 

## Description

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

## Example

```bash

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`

## 解题

```bash
class Solution{
public:
    vector<vector<int>> pathSum(TreeNode* root,int sum){
        vector<vector<int>> res;
        vector<int> temp;
        if(root==NULL) return res;
        stack<TreeNode*> st;
        TreeNode* prev=NULL;
        while(!st.empty()||root){
            while(root){
                st.push(root);
                sum-=root->val;
                temp.push_back(root->val);
                root=root->left;
            }
            root=st.top();
            if(!root->left&&!root->right&&sum==0){
                res.push_back(temp);
            }
            if(!root->right||root->right==prev){
                st.pop();
                sum+=root->val;
                temp.pop_back();
                prev=root;
                root=NULL;//回到root重新获取栈顶元素
            }
            else root=root->right;
        }
        return res;
    }
};
```