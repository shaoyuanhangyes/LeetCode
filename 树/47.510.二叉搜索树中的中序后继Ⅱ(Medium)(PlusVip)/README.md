# 47(510) 二叉搜索树中的中序后继Ⅱ(Medium)

510. Inorder Successor in BST II

## 描述

给定一棵二叉搜索树和其中的一个节点 node ，找到该节点在树中的中序后继。

如果节点没有中序后继，请返回 null 。

一个结点 node 的中序后继是键值比 node.val大所有的结点中键值最小的那个。

你可以直接访问结点，但无法直接访问树。每个节点都会有其父节点的引用。节点定义如下：

```c++
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
```

进阶：

你能否在不访问任何结点的值的情况下解决问题?


## 示例

```

示例 1:

输入: tree = [2,1,3], node = 1
输出: 2
解析: 1 的中序后继结点是 2 。注意节点和返回值都是 Node 类型的。

示例 2:

输入: tree = [5,3,6,2,4,null,null,1], node = 6
输出: null
解析: 该结点没有中序后继，因此返回 null 。

示例 3:

输入: tree = [15,6,18,3,7,17,20,2,4,null,13,null,null,null,null,null,null,null,null,9], node = 15
输出: 17

示例 4:

输入: tree = [15,6,18,3,7,17,20,2,4,null,13,null,null,null,null,null,null,null,null,9], node = 13
输出: 15

```

提示：

-10^5 <= Node.val <= 10^5
1 <= Number of Nodes <= 10^4
树中各结点的值均保证唯一。

## Description

Given a node in a binary search tree, find the in-order successor of that node in the BST.

If that node has no in-order successor, return null.

The successor of a node is the node with the smallest key greater than node.val.

You will have direct access to the node but not to the root of the tree. Each node will have a reference to its parent node. Below is the definition for Node:

```C++
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
```

Follow up:

Could you solve it without looking up any of the node's values?

## Example

```bash

Example 1:

Input: tree = [2,1,3], node = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both the node and the return value is of Node type.

Example 2:

Input: tree = [5,3,6,2,4,null,null,1], node = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.

Example 3:

Input: tree = [15,6,18,3,7,17,20,2,4,null,13,null,null,null,null,null,null,null,null,9], node = 15
Output: 17

Example 4:

Input: tree = [15,6,18,3,7,17,20,2,4,null,13,null,null,null,null,null,null,null,null,9], node = 13
Output: 15

Example 5:

Input: tree = [0], node = 0
Output: null

```

Constraints:

-10^5 <= Node.val <= 10^5
1 <= Number of Nodes <= 10^4
All Nodes will have unique values.

`Microsoft` `VMware` `Dell` `eBay` `Red` `Facebook` `Bloomberg`

## 解题


### 代码

```C++

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        
    }
};

```