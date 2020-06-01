# 4(102) 二叉树的层次遍历
## 描述
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）
## 示例
给定二叉树 [3,9,20,null,null,15,7]，
```bash
    3
   / \
  9  20
    /  \
   15   7
``` 
返回其层次遍历结果：
```bash
[
  [3],
  [9,20],
  [15,7]
]
```

## Description
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

## Example
return its level order traversal as:
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
  [3],
  [9,20],
  [15,7]
]
```
## 解题
```bash
#include <iostream>
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
};
int main(){
    vector<int> nums={0,1,2,3,4,5,6,7,8};//示例 值为-1代表所在位置为空值
    int len=nums.size();
    TreeNode *root=levelCreateBinaryTree(nums,len,0);
    Solution answer;
    vector<vector<int>> res=answer.levelOrder(root);
    PrintMartrix(res);
    return 0;
}
```