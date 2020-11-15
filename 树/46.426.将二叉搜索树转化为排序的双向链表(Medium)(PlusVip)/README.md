# 46(426) 将二叉搜索树转化为排序的双向链表(Medium)

426. Convert Binary Search Tree to Sorted Doubly Linked List

## 描述

将一个 二叉搜索树 就地转化为一个 已排序的双向循环链表 。

对于双向循环列表，你可以将左右孩子指针作为双向循环链表的前驱和后继指针，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。

特别地，我们希望可以 就地 完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中最小元素的指针。

## 示例

```

示例 1：

输入：root = [4,2,5,1,3] 

输出：[1,2,3,4,5]

示例 2：

输入：root = [2,1,3]
输出：[1,2,3]

示例 3：

输入：root = []
输出：[]
解释：输入是空树，所以输出也是空链表。

示例 4：

输入：root = [1]
输出：[1]

```

提示：

-1000 <= Node.val <= 1000
Node.left.val < Node.val < Node.right.val
Node.val 的所有值都是独一无二的
0 <= Number of Nodes <= 2000

## Description

Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

You can think of the left and right pointers as synonymous to the predecessor and successor pointers in a doubly-linked list. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

We want to do the transformation in place. After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. You should return the pointer to the smallest element of the linked list.

## Example

```bash

Example 1:

Input: root = [4,2,5,1,3]
Output: [1,2,3,4,5]

Example 2:

Input: root = [2,1,3]
Output: [1,2,3]

Example 3:

Input: root = []
Output: []
Explanation: Input is an empty tree. Output is also an empty Linked List.

Example 4:

Input: root = [1]
Output: [1]


```

Constraints:

-1000 <= Node.val <= 1000
Node.left.val < Node.val < Node.right.val
All values of Node.val are unique.
0 <= Number of Nodes <= 2000

`Google` `Adobe` `VMware` `Cisco` `Facebook` `Amazon` `Microsoft` `IBM` `Bloomberg` `Apple` `Alibaba`

## 解题

利用二叉搜索树的中序遍历来创建双向链表

利用全局变量 head表示链表的第一个结点 tail表示链表的最后一个结点 初值都为NULL

之后按照中序遍历的序列进行连接 中序遍历采用递归形式 

当tail为空的时候 意味着这个链表为空 所以 第一个结点就是当前结点 最后一个结点也是当前结点

当tail不为空的时候 意味着这个链表中存在元素 只需要将当前结点连接到链表中即可 `tail->right=root` `root->left=tail` 这样就连接到了链表中 然后当前结点就变为了新的tail

中序遍历连接之后 链表的头尾还未双向连接 所以`head->left=tail` `tail->right=head` 这样双向链表之间的所有元素都连接了

### 代码

```C++

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        head=NULL;tail=NULL;
        inorder(root);
        head->left=tail;
        tail->right=head;
        return head;
    }

private:
    Node* head;
    Node* tail;
    void inorder(Node* root){
        if(!root) return ;
        inorder(root->left);

        if(!tail) head=root;
        else{
            tail->right=root;
            root->left=tail;
        }
        tail=root;

        inorder(root->right);
    }
};

```