# 1(100) 相同的树

## 描述
给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
## 示例
```bash
输入:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

输出: true

输入:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]

输出: false

输入:       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

输出: false

``` 
## Description

Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

## Example
```bash
Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`
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
    bool isSameTree(TreeNode* p,TreeNode* q){//递归
        if(!p&&!q) return true;//两棵树都为空也是相同的树 
        if(!p||!q) return false;//有一棵树不为空另一颗为空则一定不是相同的树
        return (p->val==q->val)&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        //递归对比各个结点的val值是否相同 如果不同 根据&&与运算符的短路作用 若第一个参与运算的值为false就直接返回false 会提前结束递归直接返回结果 不会造成多余的浪费
    }
};
int main(){
    vector<int> nums1={1,2,3,4,5,-1,7};//示例 数组内元素为-1代表所在位置在二叉树中为null
    int len1=nums1.size();
    TreeNode *root1=levelCreateBinaryTree(nums1,len1,0);//index传参为0是我们认为根结点所在的数组序号为0
    vector<int> nums2={1,2,3,4,-1,-1,7};
    int len2=nums2.size();
    TreeNode *root2=levelCreateBinaryTree(nums2,len2,0);
    Solution answer;
    levelOrder(root1);//层序遍历输出二叉树结点 只是为了方便观察
    levelOrder(root2);
    bool res=answer.isSameTree(root1,root2);//对root1/root2两个二叉树进行对比判断
    cout<<res<<endl;
    return 0;
}
```