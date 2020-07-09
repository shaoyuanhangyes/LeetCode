# 20(222) 完全二叉树的节点个数(Medium)
## 描述

给出一个完全二叉树，求出该树的节点个数。

说明：

完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。


## 示例

```bash

输入: 
     1
   /   \
  2     3
 / \   /
4  5  6

输出: 6
``` 

## Description

Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

## Example

```bash
Input: 
     1
   /   \
  2     3
 / \   /
4  5  6

Output: 6

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`

## 解题

利用栈进行深度优先遍历 count计数器记录入栈的次数就是元素的个数
```bash
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        TreeNode* node=root;
        stack<TreeNode*> st;
        int count=0;
        while(!st.empty()||node){
            while(node){
                count++;
                st.push(node);
                node=node->left;
            }
            node=st.top();
            st.pop();
            node=node->right;
        }
        return count;
    }
};
```