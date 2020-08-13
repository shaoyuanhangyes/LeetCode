# 36(501) 二叉搜索树中的众数
## 描述

给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：

结点左子树中所含结点的值小于等于当前结点的值
结点右子树中所含结点的值大于等于当前结点的值
左子树和右子树都是二叉搜索树


## 示例

```bash 

例如：
给定 BST [1,null,2,2],

   1
    \
     2
    /
   2
返回[2].

```

提示：如果众数超过1个，不需考虑输出顺序

进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）

## Description



Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.


## Example

```bash

Given BST [1,null,2,2],

   1
    \
     2
    /
   2
 

return [2].

```

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`

## 解题

强调二叉搜索树 BST的中序遍历序列是从小到大排列的 此题就应该用到这个特性

累加树中每个节点的值是原来的节点值加上所有大于它的节点值之和 

因此联系到BST的中序遍历序列 累加树的中序遍历序列就是BST的中序遍历序列从后向前相加 

因此此题考查的是BST的逆中序遍历 期间加了一个相加赋值的一块代码

### 代码

#### 递归解法

```C++
class Solution {
public:
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
        if(root!=NULL){
            convertBST(root->right);
            root->val+=sum;
            sum=root->val;
            convertBST(root->left);
        }
        return root;
    }
};

```

```
执行用时：72 ms, 在所有 C++ 提交中击败了52.11%的用户
内存消耗：33.3 MB, 在所有 C++ 提交中击败了70.38%的用户
```

#### 迭代解法

```C++
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* node=root;
        stack<TreeNode*> st;
        int sum=0;
        while(!st.empty()||node){
            while(node){
                st.push(node);
                node=node->right;
            }
            node=st.top();st.pop();
            node->val+=sum;
            sum=node->val;
            node=node->left;
        }
        return root;
    }
};
```

```
执行用时：76 ms, 在所有 C++ 提交中击败了36.85%的用户
内存消耗：33.6 MB, 在所有 C++ 提交中击败了18.85%的用户
```