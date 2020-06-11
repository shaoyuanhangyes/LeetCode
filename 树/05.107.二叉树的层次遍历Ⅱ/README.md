# 5(107) 二叉树的层次遍历Ⅱ
## 描述
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
## 示例
给定二叉树 [3,9,20,null,null,15,7]，
```bash
    3
   / \
  9  20
    /  \
   15   7
``` 
返回其自底向上的层次遍历为：
```bash
[
  [15,7],
  [9,20],
  [3]
]
```

## Description
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).


## Example
Given binary tree [3,9,20,null,null,15,7]
```bash
    3
   / \
  9  20
    /  \
   15   7
```
return its bottom-up level order traversal as:
```bash
[
  [15,7],
  [9,20],
  [3]
]
```

## 解题
此题目是[4.102.二叉树的层次遍历](https://github.com/shaoyuanhangyes/LeetCode/tree/master/%E6%A0%91/4.102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E6%AC%A1%E9%81%8D%E5%8E%86)的一种变形
即 层次遍历后输出的数组是逆序的
因此只是在102题目的代码中修改了输出数组的顺序 很多题解都是在102题目的基础上在最后输出数组的时候使用了`reverse(res.begin(),res.end())`调换了数组内元素的顺序
但本人的代码是使用了`stack<vector<int>>`来接收每次层序遍历输出的数组元素 然后再使用一次while循环将stack栈顶的元素添加到二维数组res中 

```bash
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        stack<vector<int>> st;
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
            st.push(temp);
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
int main(){
    vector<int> nums={0,1,2,3,4,5,6,7,8};//示例 -1代表所在位置为空值
    int len=nums.size();
    TreeNode *root=levelCreateBinaryTree(nums,len,0);
    Solution answer;
    vector<vector<int>> res=answer.levelOrderBottom(root);
    PrintMartrix(res);
    return 0;
}
```