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

哈希表+深度遍历思想

哈希表m存储{TreeNode* root, int sumval} root为当前结点 sumval为root的值和root的孩子结点的值的和

深度遍历所有结点后 哈希表m中就存储了所有结点的结点和 首先判断根结点的结点和是否为偶数 若为奇数 则一定不能划分

(这里用到了位运算&  n&1) &运算法则为相同位的两个数字都为1 结果为1 否则结果为0 因为奇数的二进制最低位一定是1 例如十进制5的二进制为0101 十进制11的二进制为1011 所以一个数n对1进行&位运算 等价为 判断n是否为奇数 n为奇数 n&1=1 n为偶数 n&1=0

根结点的结点和为偶数后 开始从哈希表m中寻找是否存在一个数val=根结点和/2 并且这个数对应的结点node不能是根结点root 

因为有这两种特殊情况
```bash
    0       0
   / \       \
  -1  1       0
```

这两种情况下 根结点和为0 0/2=0 但左面的树明显不能划分 右面的树却可以划分 因此需要判断从哈希表中找到的等于根结点和一半的值val所对应的结点不能是根结点

### 代码

```C++

class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        int sumVal= dfs_sum(root);
        if((sumVal&1)==0){
            for(auto x:m){
                TreeNode* node=x.first;
                int val=x.second;
                if((x.second==sumVal/2)&&(node!=root)) return true;
            }
        }
        return false;
    }
    int dfs_sum(TreeNode* root){
        if(!root) return 0;
        int nodeVal= root->val + dfs_sum(root->left) + dfs_sum(root->right);
        m[root]=nodeVal;
        return nodeVal;
    }
private:
    unordered_map<TreeNode*,int> m;
};

```