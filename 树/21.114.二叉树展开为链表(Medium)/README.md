# 21(114) 二叉树展开为链表(Medium)
## 描述

给定一个二叉树，原地将它展开为一个单链表。

## 示例

```bash
例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

``` 

## Description

Given a binary tree, flatten it to a linked list in-place.

## Example

```bash
For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`

## 解题

```bash

class Solution {
public:
    void flatten(TreeNode* root){
        while(root){
            if(root->left==NULL) root=root->right;
            else{
                TreeNode* node=root->left;
                while(node->right!=NULL){
                    node=node->right;
                }
                node->right=root->right;
                root->right=root->left;
                root->left=NULL;
                root=root->right;
            }
        }
    }
};

```