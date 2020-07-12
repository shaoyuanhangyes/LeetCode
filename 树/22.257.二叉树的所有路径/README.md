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
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//以层序的方式创建二叉树 len为数组长度 index为元素位置序号
TreeNode* createTree(const vector<int> &nums,int len,int index){
    TreeNode *root=NULL;
    if(index<len&&nums[index]!=-1){//值为null和位置不合法时直接返回空节点
        root = new TreeNode(nums[index]);
        root->left = createTree(nums,len,2*index+1);
        root->right= createTree(nums,len,2*index+2);
    }
    return root;
}

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

int main(){
    vector<int> nums={1,2,3,4,5};
    TreeNode* root=createTree(nums,nums.size(),0);
    vector<string> res;
    Solution answer;
    res=answer.binaryTreePaths(root);
    for(auto x:res) cout<<x<<" ";
    return 0;
}

``` 