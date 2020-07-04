# 13(111) 二叉树的最小深度
## 描述

给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点

## 示例
```bash

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7

返回它的最小深度  2.
``` 

## Description

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

## Example

```bash

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7

return its minimum depth = 2.
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
    int minDepth(TreeNode* root) {//递归深度优先算法
        if(root==NULL) return 0;
        int l_left=minDepth(root->left);
        int l_right=minDepth(root->right);
        if(!l_left||!l_right) return l_left+l_right+1;
        return l_left<l_right?l_left+1:l_right+1;
    }
};

int main(){
    vector<int> nums={3,9,20,-1,-1,15,7};//值为-1表示该结点为null
    TreeNode* root=createTree(nums,nums.size(),0);
    Solution answer;
    cout<<"二叉树的最小深度为"<<answer.minDepth(root);
    return 0;
}
```
#### 代码剖析 
```
if(!l_left||!l_right) return l_left+l_right+1;
```
若根结点root既无左孩子又无右孩子 则不进行if判断
若根结点root只有左孩子没有右孩子或只有右孩子没有左孩子 进入if判断 只有左孩子没有右孩子的时候`l_left+1=左孩子最小深度 l_right=0` 只有右孩子没有左孩子的时候`l_right+1=右孩子最小深度 l_left=0`
若根结点同时拥有左孩子右孩子 不进行if判断 交给下面的return来判断左子树和右子树的最小深度

### 利用层序遍历的迭代解法

```bash
int minDepth(TreeNode* root){
        if(root==NULL) return 0;
        queue<TreeNode*> st;
        st.push(root);
        int depth=0;//设置计数器depth记录
        while(!st.empty()){
            int len=st.size();
            depth++;
            while(len--){
                TreeNode* node=st.front();
                st.pop();
                if(!node->left&&!node->right) return depth;//若左右子树均不存在 直接返回深度
                if(node->left) st.push(node->left);
                if(node->right) st.push(node->right);
            }
        }
        return depth;
    }
```