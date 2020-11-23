# 50(663) 均匀树划分(Medium)

663. Equal Tree Partition

## 描述

给定一棵有 n 个结点的二叉树，你的任务是检查是否可以通过去掉树上的一条边将树分成两棵，且这两棵树结点之和相等。

## 示例

```

样例 1:

输入:     
    5
   / \
  10 10
    /  \
   2   3

输出: True
解释: 
    5
   / 
  10
      
和: 15

   10
  /  \
 2    3

和: 15
 

样例 2:

输入:     
    1
   / \
  2  10
    /  \
   2   20

输出: False
解释: 无法通过移除一条树边将这棵树划分成结点之和相等的两棵子树。

```

注释 :

树上结点的权值范围 [-100000, 100000]。
1 <= n <= 10000

## Description

Given a binary tree with n nodes, your task is to check if it's possible to partition the tree to two trees which have the equal sum of values after removing exactly one edge on the original tree.

## Example

```bash

Example 1:
Input:     
    5
   / \
  10 10
    /  \
   2   3

Output: True
Explanation: 
    5
   / 
  10
      
Sum: 15

   10
  /  \
 2    3

Sum: 15
Example 2:
Input:     
    1
   / \
  2  10
    /  \
   2   20

Output: False
Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.

```

Note:
The range of tree node value is in the range of [-100000, 100000].
1 <= n <= 10000

`Microsoft` `Oracle` `Apple` `eBay` `FaceBook` `Snapchat`

## 解题



### 代码

```C++

class Solution {
public:
    bool checkEqualTree(TreeNode* root) {

    }
};

```