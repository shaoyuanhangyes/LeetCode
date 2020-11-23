# 51(1660) 纠正二叉树(Medium)

1660. Correct a Binary Tree

## 描述

你有一棵二叉树，这棵二叉树有个小问题，其中有且只有一个无效节点，它的右子节点错误地指向了与其在同一层且在其右侧的一个其他节点。

给定一棵这样的问题二叉树的根节点 root ，将该无效节点及其所有子节点移除（除被错误指向的节点外），然后返回新二叉树的根结点。

自定义测试用例：

测试用例的输入由三行组成：

```
TreeNode root
int fromNode （在 correctBinaryTree 中不可见）
int toNode （在 correctBinaryTree 中不可见）
当以 root 为根的二叉树被解析后，值为 fromNode 的节点 TreeNode 将其右子节点指向值为 toNode 的节点 TreeNode 。然后， root 传入 correctBinaryTree 的参数中。
```

## 示例

```

示例 1

输入: root = [1,2,3], fromNode = 2, toNode = 3
输出: [1,null,3]
解释: 值为 2 的节点是无效的，所以移除之。

示例 2:

输入: root = [8,3,1,7,null,9,4,2,null,null,null,5,6], fromNode = 7, toNode = 4
输出: [8,3,1,null,null,9,4,null,null,5,6]
解释: 值为 7 的节点是无效的，所以移除这个节点及其子节点 2。

```

提示:

树中节点个数的范围是 [3, 104] 。
-109 <= Node.val <= 109
所有的 Node.val 都是互不相同的。
fromNode != toNode
fromNode 和 toNode 将出现在树中的同一层。
toNode 在 fromNode 的右侧。
fromNode.right 在测试用例的树中建立后为 null 。

## Description


You have a binary tree with a small defect. There is exactly one invalid node where its right child incorrectly points to another node at the same depth but to the invalid node's right.

Given the root of the binary tree with this defect, root, return the root of the binary tree after removing this invalid node and every node underneath it (minus the node it incorrectly points to).

Custom testing:

```
The test input is read as 3 lines:

TreeNode root
int fromNode (not available to correctBinaryTree)
int toNode (not available to correctBinaryTree)
```

After the binary tree rooted at root is parsed, the TreeNode with value of fromNode will have its right child pointer pointing to the TreeNode with a value of toNode. Then, root is passed to correctBinaryTree.


## Example

```bash

Example 1:

Input: root = [1,2,3], fromNode = 2, toNode = 3
Output: [1,null,3]
Explanation: The node with value 2 is invalid, so remove it.

Example 2:

Input: root = [8,3,1,7,null,9,4,2,null,null,null,5,6], fromNode = 7, toNode = 4
Output: [8,3,1,null,null,9,4,null,null,5,6]
Explanation: The node with value 7 is invalid, so remove it and the node underneath it, node 2.

```

Constraints:

The number of nodes in the tree is in the range [3, 104].
-109 <= Node.val <= 109
All Node.val are unique.
fromNode != toNode
fromNode and toNode will exist in the tree and will be on the same depth.
toNode is to the right of fromNode.
fromNode.right is null in the initial tree from the test data.

`Google`

## 解题

队列存一对pair值 `当前结点node,node的父结点`
进行层次遍历(BFS) 将每一层的结点存入map中 

然后遍历这个层局部map 若发现某一个结点的右结点也存在这个map中 就说明有结点是坏结点 

所以我们要删除这个坏结点node 已知node的父结点是parent 当parent->left=node时 说明坏结点的right直接指向父结点的右结点 直接将parent->left置空就可以 
当parent->left不为node时 说明node不是parent的左结点 那么node就是parent的右结点 所以将parent->right置空即可

### 代码

```C++

class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        if(!root) return NULL;
        queue<pair<TreeNode*,TreeNode*>> st;
        st.push({root,NULL});
        TreeNode* node=NULL;TreeNode* parent=NULL;
        while(!st.empty()){
            int len=st.size();
            unordered_map<TreeNode*,TreeNode*> m;
            while(len--){
                node=st.front().first;parent=st.front().second;
                st.pop();
                m[node]=parent;
                if(node->left) st.push({node->left, node});
                if(node->right) st.push({node->right, node});
            }
            for(auto x:m){
                node=x.first;
                if(m.count(node->right)){
                    parent=x.second;
                    if(parent->left==node) parent->left=NULL;
                    else parent->right=NULL;
                    return root;
                }
            }
        }
        return root;
    }
};

```