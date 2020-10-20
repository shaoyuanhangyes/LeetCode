# 42(116) 填充每个节点的下一个右侧节点指针(Medium)

## 描述

给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

## 示例

```

输入 root = [1,2,3,4,5,6,7]

输出 [1,#,2,3,#,4,5,6,7,#]

解释: 你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点
```

提示：

你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

## Description

You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

## Example

```bash

Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`

Constraints:

The number of nodes in the given tree is less than 4096.
-1000 <= node.val <= 1000

## 解题

利用层序遍历迭代填充 层序遍历利用队列确定当前要加入next的节点(cur) pre保留上一次队列输出的节点 pre->next=cur 填充到最后将最后一个遍历节点的next置为NULL

### 代码

```C++
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if(root) que.push(root);
        while(!que.empty()){
            int len=que.size();
            Node* cur;
            Node* pre;
            for(int i=0;i<len;++i){
                if(i==0){
                    cur=que.front();que.pop();
                    pre=cur;
                }
                else{
                    cur=que.front();que.pop();
                    pre->next=cur;
                    pre=cur;
                }
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            cur->next=NULL;
        }
        return root;
    }
};
```