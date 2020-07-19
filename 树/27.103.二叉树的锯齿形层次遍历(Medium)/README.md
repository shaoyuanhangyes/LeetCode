# 27(103) 二叉树的锯齿形层次遍历(Medium)
## 描述

给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）

## 示例

```bash

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

``` 

## Description

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

## Example

```bash

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`

## 解题

```c++
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> st;
        st.push(root);
        int sign=0;
        while(!st.empty()){
            sign++;
            vector<int> temp;
            int len=st.size();
            while(len--){
                root=st.front();st.pop();
                temp.push_back(root->val);
                if(root->left) st.push(root->left);
                if(root->right) st.push(root->right);
            }
            if(sign%2==0) reverse(temp.begin(),temp.end());
            res.push_back(temp);
        }
        return res;
    }
};
```
