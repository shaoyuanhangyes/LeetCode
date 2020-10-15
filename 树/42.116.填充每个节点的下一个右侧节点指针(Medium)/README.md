# 42(116) 填充每个节点的下一个右侧节点指针(Medium)

## 描述

给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

## 示例

```

输入 root = [1,2,3,4,5,6,7]

输出 [1,#,2,3,#,4,5,6,7,#]

解释: 
```


## Description

Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

## Example

```bash

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`


## 解题

普通解法: 利用二叉搜索树的中序遍历是有序序列的特点 每次遍历检查相邻元素的差值是否是最小

### 代码

```C++
class Solution{
public:
    int getMinimumDifference(TreeNode* root){
        TreeNode* node=root;
        TreeNode* pre=NULL;
        stack<TreeNode*> st;
        while(!st.empty()||node){
            while(node){
                st.push(node);
                node=node->left;
            }
            node=st.top();st.pop();
            if(pre!=NULL){
                res=min(res,node->val-pre->val);
            }
            pre=node;
            node=node->right;
        }
        return res;
    }
private:
    int res=INT_MAX;
};
```