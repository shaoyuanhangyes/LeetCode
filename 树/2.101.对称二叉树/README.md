# 2(101) 对称二叉树

## 描述
给定一个二叉树，检查它是否是镜像对称的。

## 示例
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
```bash
    1
   / \
  2   2
 / \ / \
3  4 4  3
``` 
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的
```bash
    1
   / \
  2   2
   \   \
   3    3
```
## Description
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

## Example
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
```bash
    1
   / \
  2   2
 / \ / \
3  4 4  3
```
But the following [1,2,2,null,3,null,3] is not
```bash
    1
   / \
  2   2
   \   \
   3    3
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
    bool isSymmetric(TreeNode* root) {
        return (!root)?true:dfs(root->left,root->right);
    }
    bool dfs(TreeNode *p,TreeNode *q){
        if(!p||!q) return !p&&!q;// pq都为空 返回true pq有一个为空另一个不为空 返回false
        return (p->val!=q->val)?false:dfs(p->left,q->right)&&dfs(p->right,q->left);
    }
};
int main(){
    vector<int> nums1={1,2,2,3,4,4,3};//示例 -1代表所在位置为空值
    int len1=nums1.size();
    TreeNode *root=levelCreateBinaryTree(nums1,len1,0);
    Solution answer;
    levelOrder(root);
    bool res=answer.isSymmetric(root);
    cout<<res<<endl;
    return 0;
}
```