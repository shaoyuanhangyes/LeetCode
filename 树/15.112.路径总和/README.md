# 15(112) 路径总和
## 描述

给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。
## 示例
```bash
给定如下二叉树，以及目标和 sum = 22，
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
``` 

## Description

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

## Example

```bash
Given the below binary tree and sum = 22,
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
```
`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`
## 解题

### 递归解法

```bash
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL) return false;
        sum-=root->val;
        if(root->left==NULL&&root->right==NULL) return sum==0;
        return hasPathSum(root->left,sum)||hasPathSum(root->right,sum);
    }
};
int main(){
    vector<int> nums={5,4,8,11,-1,13,4,7,2,-1,-1,-1,-1,-1,1};
    TreeNode* root=createTree(nums,nums.size(),0);
    Solution answer;
    cout<<answer.hasPathSum(root,22);
    return 0;
}

```

### 迭代解法

使用pair存储{树结点,差值} 并将pair压入栈中
然后判断是否是叶子结点 

```bash
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL) return false;
        stack<pair<TreeNode*,int>> stp;
        stp.push({root,sum});
        while(!stp.empty()){
            pair<TreeNode*,int> temp=stp.top();
            stp.pop();
            TreeNode* node=temp.first;
            int delta=temp.second-node->val;
            if(node->left==NULL&&node->right==NULL){
                if(delta==0) return true;
            }
            if(node->left) stp.push({node->left,delta});
            if(node->right) stp.push({node->right,delta});
        }
        return false;
    }
};
```