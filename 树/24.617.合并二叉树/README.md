# 24(617) 合并二叉树
## 描述

给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

## 示例
```bash

输入: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
输出: 
合并后的树:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7

``` 

注意: 合并必须从两个树的根节点开始。

## Description

Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

## Example

```bash

Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7

```

Note: The merging process must start from the root nodes of both trees.


`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`

## 解题

### 递归解法
合并结点到t1上
```bash
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1) return t2;
        if(!t2) return t1;
        t1->val+=t2->val;
        t1->left=mergeTrees(t1->left,t2->left);
        t1->right=mergeTrees(t1->right,t2->right);
        return t1;
    }
};
``` 


### 迭代解法

```bash
TreeNode* mergeTrees(TreeNode* t1,TreeNode* t2){
        if(!t1) return t2;
        stack<pair<TreeNode*,TreeNode*>> st;
        if(t1&&t2) st.push({t1,t2});
        while(!st.empty()){
            pair<TreeNode*,TreeNode*> temp=st.top();
            st.pop();
            temp.first->val=temp.first->val+temp.second->val;
            if(temp.first->left||temp.second->left) {
                if(!temp.second->left) temp.second->left=new TreeNode(0);
                if(!temp.first->left)  temp.first->left=new TreeNode(0);
                st.push({temp.first->left, temp.second->left});
            }
            if(temp.first->right||temp.second->right) {
                if(!temp.second->right) temp.second->right=new TreeNode(0);
                if(!temp.first->right)  temp.first->right=new TreeNode(0);
                st.push({temp.first->right,temp.second->right});
            }
        }
        return t1;
    }
```