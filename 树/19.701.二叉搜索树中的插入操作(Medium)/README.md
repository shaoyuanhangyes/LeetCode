# 19(701) 二叉搜索树中的插入操作(Medium)
## 描述

给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 保证原始二叉搜索树中不存在新值。

注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回任意有效的结果。

## 示例

```bash

例如, 

给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和 插入的值: 5
你可以返回这个二叉搜索树:

         4
       /   \
      2     7
     / \   /
    1   3 5
或者这个树也是有效的:

         5
       /   \
      2     7
     / \   
    1   3
         \
          4

``` 

## Description

Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

## Example

```bash
For example, 

Given the tree:
        4
       / \
      2   7
     / \
    1   3
And the value to insert: 5
You can return this binary search tree:

         4
       /   \
      2     7
     / \   /
    1   3 5
This tree is also valid:

         5
       /   \
      2     7
     / \   
    1   3
         \
          4

```
Constraints:

The number of nodes in the given tree will be between 0 and 10^4.
Each node will have a unique integer value from 0 to -10^8, inclusive.
-10^8 <= val <= 10^8
It's guaranteed that val does not exist in the original BST.

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`

## 解题

### 递归解法
```bash

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        if(val<root->val) root->left=insertIntoBST(root->left,val);
        if(val>root->val) root->right=insertIntoBST(root->right,val);
        return root;
    }
};

```
#### 复杂度分析
1. 时间复杂度: O(H) H为Tree的高度 平均情况<math xmlns="http://www.w3.org/1998/Math/MathML" display="inline-block"><mi>l</mi><mi>o</mi><msub><mi>g</mi><mn>2</mn></msub><mi>N</mi></math> 最坏情况O(N)
2. 空间复杂度: 平均情况下O(H) 最坏情况O(N) 是在递归过程中堆栈使用的空间

复杂度中`最坏的情况`就是二叉树高度为二叉树结点数量的时候 即
```
        5
       /   
      2     
     /   
    1  
   /
  4 
```
要插入的元素需要遍历到最深才能插入

### 迭代解法

```bash
TreeNode* insertIntoBST(TreeNode* root,int val){
        TreeNode* node=root;
        while(node!=NULL){
            if(val>node->val){
                if(node->right==NULL){
                    node->right=new TreeNode(val);
                    return root;
                }
                else node=node->right;
            }
            else{
                if(node->left==NULL){
                    node->left=new TreeNode(val);
                    return root;
                }
                else node=node->left;
            }
        }
        return new TreeNode(val);
    }
```

#### 复杂度分析

1. 时间复杂度: O(H) H为Tree的高度 平均情况<math xmlns="http://www.w3.org/1998/Math/MathML" display="inline-block"><mi>l</mi><mi>o</mi><msub><mi>g</mi><mn>2</mn></msub><mi>N</mi></math> 最坏情况O(N)
2. 空间复杂度: O(1)