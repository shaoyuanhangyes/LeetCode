# 6(94) 二叉树的中序遍历
## 描述
给定一个二叉树，返回它的中序遍历
## 示例
给定二叉树 [3,9,20,null,null,15,7]，
```bash
输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
``` 
递归算法很简单，你可以通过迭代算法完成吗？

## Description
Given a binary tree, return the inorder traversal of its nodes' values.
## Example
Given binary tree [3,9,20,null,null,15,7]
```bash
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
```
Follow up: Recursive solution is trivial, could you do it iteratively?

## 解题
### 解法一 递归算法
```bash
vector<int> res;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {//递归算法
        if(root!=NULL){
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);
        }
        return res;
    }
};

int main(){
    vector<int> nums={0,1,2,3,4,5,6,7,8};//示例 -1代表所在位置为空值
    int len=nums.size();
    TreeNode *root=levelCreateBinaryTree(nums,len,0);
    Solution answer;
    res=answer.inorderTraversal(root);
    for(auto x:res) cout<<x<<" ";
    return 0;
}

输出的中序遍历序列为: 7 3 8 1 4 0 5 2 6
```
中序遍历递归算法的时间复杂度 O(n) 空间复杂度 最坏情况O(n) 平均情况O(logn)
### 解法二 迭代
```bash
class Solution {
public:
   vector<int> inorderTraversal(TreeNode* root) {//迭代算法
      vector<int> res;
      stack<TreeNode *> st;
      TreeNode *node=root;
      while(!st.empty()||node){
         while(node){
            st.push(node);
            node=node->left;
         }
         node=st.top();
         st.pop();
         res.push_back(node->val);
         node=node->right;
      }
      return res;
    }
};

int main(){
    vector<int> nums={0,1,2,3,4,5,6,7,8};//示例 -1代表所在位置为空值
    int len=nums.size();
    TreeNode *root=levelCreateBinaryTree(nums,len,0);
    Solution answer;
    res=answer.inorderTraversal(root);
    for(auto x:res) cout<<x<<" ";
    return 0;
}
```
中序遍历基于栈的迭代算法的时间复杂度O(n) 空间复杂度O(n)