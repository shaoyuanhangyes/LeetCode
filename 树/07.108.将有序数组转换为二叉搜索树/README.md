# 7(108) 将有序数组转换为二叉搜索树
## 描述

将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

## 示例
```bash
给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

``` 

## Description

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

## Example

```bash

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

```
`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`
## 解题
二叉搜索树 BST(Binary Search Tree) 又称为二叉查找树 二叉排序树
二叉搜索树或者是一棵空的树 或者是具有以下特征的树:
1. 若左子树非空 则左子树上所有的结点key_val均小于根节点的key_val
2. 若右子树非空 则右子树上所有的结点key_val均大于根节点的key_val
3. 左右子树本身也是二叉搜索树

因此 对二叉搜索树进行中序遍历 得到的一定是一个递增的有序序列

```bash
#include <iostream>// SortedArray to BST
#include <vector>
#include <queue>
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
void PrintMartrix(vector<vector<int>>& res){//打印二维数组
    for(int i=0;i<res.size();++i){
        cout<<"[";
        for(int j=0;j<res[i].size();++j){
            cout<<" "<<res[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
}
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode* > Tree;
        Tree.push(root);
        while(!Tree.empty()){
            vector<int> temp;
            int len=Tree.size();
            while(len--){
                TreeNode *pNode=Tree.front();
                Tree.pop();
                temp.push_back(pNode->val);
                if(pNode->left) Tree.push(pNode->left);
                if(pNode->right) Tree.push(pNode->right);
            }
            res.push_back(temp);
        }
        return res;
    }

    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {//递归算法
        if(root!=NULL){
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);
        }
        return res;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	if(nums.size()==0) return NULL;
		if(nums.size()==1) return new TreeNode(nums[0]);
		int mid=nums.size()/2;
		TreeNode* node=new TreeNode(nums[mid]);
		vector<int>::const_iterator first;
		vector<int>::const_iterator last;
		first=nums.begin();
		last=nums.begin()+mid;
		vector<int> v_temp(first,last);
		node->left=sortedArrayToBST(v_temp);
		if(mid==nums.size()-1) node->right=NULL;
		else{
		    first=nums.begin()+mid+1;
		    last=nums.end();
		    vector<int> v_temp(first,last);
		    node->right=sortedArrayToBST(v_temp);
		}
		return node;
    }
};
int main(){
    vector<int> nums={0,1,2,3,4,5};//示例 值为-1代表所在位置为空值
    int len=nums.size();
    Solution answer;
    TreeNode *root=answer.sortedArrayToBST(nums);
    vector<vector<int>> res=answer.levelOrder(root);
    PrintMartrix(res);//打印层序遍历的二维数组
    vector<int> print=answer.inorderTraversal(root);
    for(auto x:print) cout<<x<<" ";//打印中序遍历的序列
    return 0;
}

```