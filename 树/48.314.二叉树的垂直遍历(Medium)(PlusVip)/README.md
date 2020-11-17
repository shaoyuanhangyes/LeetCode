# 48(314) 二叉树的垂直遍历(Medium)

314. Binary Tree Vertical Order Traversal

## 描述

给定一个二叉树，返回其结点 垂直方向（从上到下，逐列）遍历的值。

如果两个结点在同一行和列，那么顺序则为 从左到右。

## 示例

```

示例 1：

输入: [3,9,20,null,null,15,7]

   3
  /\
 /  \
9   20
    /\
   /  \
  15   7 

输出:

[
  [9],
  [3,15],
  [20],
  [7]
]
示例 2:

输入: [3,9,8,4,0,1,7]

     3
    /\
   /  \
  9    8
  /\   /\
 /  \ /  \
4   0 1   7 

输出:

[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
示例 3:

输入: [3,9,8,4,0,1,7,null,null,null,2,5]（注意：0 的右侧子节点为 2，1 的左侧子节点为 5）

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2

输出:

[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]

```

提示：

-10^5 <= Node.val <= 10^5
1 <= Number of Nodes <= 10^4
树中各结点的值均保证唯一。

## Description

Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

## Example

```bash

Examples 1:

Input: [3,9,20,null,null,15,7]

   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7 

Output:

[
  [9],
  [3,15],
  [20],
  [7]
]
Examples 2:

Input: [3,9,8,4,0,1,7]

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7 

Output:

[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
Examples 3:

Input: [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5)

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2

Output:

[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]

```

`Amazon` `Facebook` `Bloomberg` `Google` `Microsoft` `Oracle` `BitDance` `MathWorks` `Cisco` `Adobe` `eBay` `Linkedln`

## 解题

以root根结点为坐标轴原点 向左遍历 坐标值-1 向右遍历 坐标值+1 哈希表m[i]存放坐标值为i的一维数组(数组中存放坐标值相同的树结点值)

利用层序遍历(BFS)访问结点 层序遍历依靠队列来实现 队列中存储pair<TreeNode*,int> first存放树结点 second存放所处的坐标值

将队列中的pair存入map中 因为map是有序的 所以按照坐标值从小到大的顺序排列

最后将哈希表中每个坐标值所对应的一维数组 插入到数组中

### 代码

```C++

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        coordinate.push(cur_coordinate);
        visited.push(root);
        while(!visited.empty()){
            cur=visited.front();
            cur_coordinate=coordinate.front();
            visited.pop();
            coordinate.pop();
            m[cur_coordinate].push_back(cur->val);
            if(cur->left){
                visited.push(cur->left);
                coordinate.push(cur_coordinate-1);
            }
            if(cur->right){
                visited.push(cur->right);
                coordinate.push(cur_coordinate+1);
            }
        }
        for(auto x=m.begin();x!=m.end();++x){
            res.push_back(x->second);
        }
        return res;
    }

private:
    map<int,vector<int>> m;
    queue<TreeNode*> visited;
    queue<int> coordinate;
    int cur_coordinate=0;
    TreeNode* cur=NULL;
};

```