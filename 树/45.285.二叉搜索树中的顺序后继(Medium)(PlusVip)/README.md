# 45(285) 二叉搜索树中的顺序后继(Medium)

285. Inorder Successor in BST

## 描述

给你一个二叉搜索树和其中的某一个结点，请你找出该结点在树中顺序后继的节点。

结点 p 的后继是值比 p.val 大的结点中键值最小的结点。

## 示例

```

示例 1:

输入: root = [2,1,3], p = 1
输出: 2
解析: 这里 1 的顺序后继是 2。请注意 p 和返回值都应是 TreeNode 类型。

示例 2:

输入: root = [5,3,6,2,4,null,null,1], p = 6
输出: null
解析: 因为给出的结点没有顺序后继，所以答案就返回 null 了。

```

注意:

假如给出的结点在该树中没有顺序后继的话，请返回 null
我们保证树中每个结点的值是唯一的

## Description

Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

The successor of a node p is the node with the smallest key greater than p.val.

## Example

```bash

Example 1:

Input: root = [2,1,3], p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.

Example 2:

Input: root = [5,3,6,2,4,null,null,1], p = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.

```

Note:

If the given node has no in-order successor in the tree, return null.
It's guaranteed that the values of the tree are unique.

`Google` `Adobe` `VMware` `Cisco` `Facebook` `Amazon` `Microsoft` `IBM` `Bloomberg` `Apple` `Alibaba`

## 解题

顺序后继 就是中序遍历序列

### 代码

```C++

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res=NULL;
        while(root){
            if(p->val < root->val){
                res=root;
                root=root->left;
            }        
            else{
                root=root->right;
            }
        }
        return res;
    }
};

```