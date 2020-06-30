# 9(145) 二叉树的后序遍历(Hard)
## 描述

给定一个二叉树，返回它的 后序 遍历

## 示例
```bash
输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]
``` 
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
## Description

Given a binary tree, return the postorder traversal of its nodes' values.

## Example

```bash

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]

```
Follow up: Recursive solution is trivial, could you do it iteratively?

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`

## 解题

### 递归解法
```bash
class Solution {
public:
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root){
        if(root!=NULL){
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            res.push_back(root->val);
        }
        return res;
    }
};
```
### 迭代解法1 标记位
prev记录已经输出到res数组中的上一个结点 防止出现某一结点有右孩子 右孩子输出后 根据栈回到右孩子的父结点 然后又判断是否有右孩子的死循环 当判断到node->right==prev成立 即父结点的右孩子上一次被访问过 就输出这个父结点
```bash
vector<int> postorderTraversal(TreeNode* root){
    vector<int> res;
    stack<TreeNode* > st;
    TreeNode* node=root;
    TreeNode* prev=NULL;
    while(!st.empty()||node){
        while(node){
            st.push(node);
            node=node->left;
        }
        node=st.top();
        if(node->right==NULL||node->right==prev){
            res.push_back(node->val);
            st.pop();
            prev=node;
            node=NULL;
        }
        else node=node->right;
    }
    return res;
}
```
### 迭代解法2 修改前序遍历
前序遍历迭代代码为
```bash
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> res;
	stack<TreeNode* > st;
	TreeNode* node=root;
	while(!st.empty()||node){
	    while(node){
	    st.push(node);
	        res.push_back(node->val);//根
	        node=node->left;//左
	    }
	    node=st.top();
	    st.pop();
	    node=node->right;//右
	}
	return res;
}
```

前序遍历的序列为 `根 左 右`
通过修改代码使其变为`根 右 左`的序列 然后全部翻转为`左 右 根`
代码修改为
```bash
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> res;
	stack<TreeNode* > st;
	TreeNode* node=root;
	while(!st.empty()||node){
	    while(node){
	        st.push(node);
	        res.push_back(node->val);//根
	        node=node->right;//右
	    }
	    node=st.top();
	    st.pop();
	    node=node->left;//左
	}
	reverse(res.begin(),res.end());//#include <algorithm>
	return res;
}
```