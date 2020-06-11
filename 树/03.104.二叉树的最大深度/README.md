# 3(104) 二叉树的最大深度
## 描述
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。
## 示例
给定二叉树 [3,9,20,null,null,15,7]，
```bash
    3
   / \
  9  20
    /  \
   15   7
``` 
返回它的最大深度 3 

## Description
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

## Example
Given binary tree [3,9,20,null,null,15,7]
```bash
    3
   / \
  9  20
    /  \
   15   7
```

## 解题
```bash
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>//sort()
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
};
TreeNode* levelCreateBinaryTree(const vector<int> &nums,int len,int index){//层序创建二叉树index为位置序号
    TreeNode *root=NULL;
    if(index<len&&nums[index]!=-1){
        root = new TreeNode(nums[index]);
        root->left = levelCreateBinaryTree(nums,len,2*index+1);
        root->right= levelCreateBinaryTree(nums,len,2*index+2);
    }
    return root;
}
void levelOrder(TreeNode *root){//层序遍历 依靠队列来实现
    queue<TreeNode* > Tree;
    Tree.push(root);
    while(!Tree.empty()){
        TreeNode *pNode = Tree.front();
        Tree.pop();
        cout<<pNode->val<<" ";
        if(pNode->left!=NULL) Tree.push(pNode->left);
        if(pNode->right!=NULL) Tree.push(pNode->right);
    }
    cout<<endl;
}
class Solution {
public:
    int maxDepth(TreeNode* root) {//递归深度优先算法
        if(root==NULL) return 0;
        int l_len=maxDepth(root->left)+1;
        int r_len=maxDepth(root->right)+1;
        return l_len>r_len?l_len:r_len;
    }
};
int main(){
    vector<int> nums={0,1,2,3,4,5,6,7,8};//示例 -1代表所在位置为空值
    int len=nums.size();
    TreeNode *root=levelCreateBinaryTree(nums,len,0);
    Solution answer;
    levelOrder(root);
    cout<<answer.maxDepth(root)<<endl;
    return 0;
}
```