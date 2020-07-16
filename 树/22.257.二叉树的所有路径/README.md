# 22(257) 二叉树的所有路径
## 描述

给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

## 示例
```bash

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

``` 

## Description

Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

## Example

```bash

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`

## 解题

```bash
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        stack<pair<TreeNode*,string>> st;
        TreeNode* node=root;
        string str;
        while(!st.empty()||node){
            while(node){
                if(node==root) str+=to_string(node->val);
                else str=str+"->"+to_string(node->val);
                st.push(pair<TreeNode*,string>(node,str));
                node=node->left;
            }
            node=st.top().first;
            str=st.top().second;
            st.pop();
            if(!node->left&&!node->right) res.push_back(str);
            node=node->right;
        }
        return res;
    }
};
``` 