# 49(545) 二叉树的边界(Medium)

545. Boundary of Binary Tree

## 描述

给定一棵二叉树，以逆时针顺序从根开始返回其边界。边界按顺序包括左边界、叶子结点和右边界而不包括重复的结点。 (结点的值可能重复)

左边界的定义是从根到最左侧结点的路径。右边界的定义是从根到最右侧结点的路径。若根没有左子树或右子树，则根自身就是左边界或右边界。注意该定义只对输入的二叉树有效，而对子树无效。

最左侧结点的定义是：在左子树存在时总是优先访问，如果不存在左子树则访问右子树。重复以上操作，首先抵达的结点就是最左侧结点。

最右侧结点的定义方式相同，只是将左替换成右。

## 示例

```

示例 1

输入:
  1
   \
    2
   / \
  3   4

输出:
[1, 3, 4, 2]

解析:
根不存在左子树，故根自身即为左边界。
叶子结点是3和4。
右边界是1，2，4。注意逆时针顺序输出需要你输出时调整右边界顺序。
以逆时针顺序无重复地排列边界，得到答案[1,3,4,2]。
 

示例 2

输入:
    ____1_____
   /          \
  2            3
 / \          / 
4   5        6   
   / \      / \
  7   8    9  10  
       
输出:
[1,2,4,7,8,9,10,6,3]

解析:
左边界是结点1,2,4。(根据定义，4是最左侧结点)
叶子结点是结点4,7,8,9,10。
右边界是结点1,3,6,10。(10是最右侧结点)
以逆时针顺序无重复地排列边界，得到答案 [1,2,4,7,8,9,10,6,3]。

```



## Description

A binary tree boundary is the set of nodes (no duplicates) denoting the union of the left boundary, leaves, and right boundary.

The left boundary is the set of nodes on the path from the root to the left-most node. The right boundary is the set of nodes on the path from the root to the right-most node.

The left-most node is the leaf node you reach when you always travel to the left subtree if it exists and the right subtree if it doesn't. The right-most node is defined in the same way except with left and right exchanged. Note that the root may be the left-most and/or right-most node.

Given the root of a binary tree, return the values of its boundary in a counter-clockwise direction starting from the root.


## Example

```bash

Example 1:

Input: root = [1,null,2,3,4]
Output: [1,3,4,2]
Explanation:
The left boundary is the nodes [1,2,3].
The right boundary is the nodes [1,2,4].
The leaves are nodes [3,4].
Unioning the sets together gives [1,2,3,4], which is [1,3,4,2] in counter-clockwise order.
Example 2:


Input: root = [1,2,3,4,5,6,null,null,null,7,8,9,10]
Output: [1,2,4,7,8,9,10,6,3]
Explanation:
The left boundary are node 1,2,4. (4 is the left-most node according to definition)
The left boundary is nodes [1,2,4].
The right boundary is nodes [1,3,6,10].
The leaves are nodes [4,7,8,9,10].
Unioning the sets together gives [1,2,3,4,6,7,8,9,10], which is [1,2,4,7,8,9,10,6,3] in counter-clockwise order.

```

Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000


`Amazon` `Facebook` `Bloomberg` `Google` `Microsoft` `Oracle` `BitDance` `MathWorks` `Cisco` `Apple` `eBay` `NVDIA`
`Visa` `Adobe` `Linkedln` `Yahoo`

## 解题

根据题意 找到最左侧结点和最右侧结点 

最左侧结点根据先序遍历 若当前结点root存在左子树 则对左子树进行先序遍历 然后对右子树直接寻找叶结点 若不存在左子树 则对右子树进行先序遍历

最右侧结点根据后序遍历 若当前结点root存在右子树 则对左子树直接寻找叶结点 然后对右子树进行后序遍历 若不存在右子树 则对左子树进行后序遍历

### 代码

```C++

class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        res.push_back(root->val);
        dfs(root->left,-1,res);
        dfs(root->right,1,res);
        return res;
    }
    void dfs(TreeNode* root,int direction,vector<int>& res){
        if(root==NULL) return;
        if(direction==0){//寻找叶子结点
            if(root->left==NULL&&root->right==NULL) res.push_back(root->val);
            else{
                dfs(root->left,0,res);
                dfs(root->right,0,res);
            }
            return;
        }
        if(direction==-1){//向左先序遍历
            res.push_back(root->val);
            if(root->left){
                dfs(root->left,direction,res);
                dfs(root->right,0,res);
            }
            else dfs(root->right,direction,res);
        }
        if(direction==1){//向右后序遍历
            if(root->right){
                dfs(root->left,0,res);
                dfs(root->right,direction,res);
            }
            else dfs(root->left,direction,res);
            res.push_back(root->val);
        }
    }
};

```