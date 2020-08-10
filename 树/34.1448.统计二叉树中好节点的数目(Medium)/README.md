# 34(1448) 统计二叉树中好节点的数目(Meidum)
## 描述

给你一棵根为 root 的二叉树，请你返回二叉树中好节点的数目。

「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。

## 示例
```bash 

示例 1:

输入：root = [3,1,4,3,null,1,5]
输出：4
解释：图中蓝色节点为好节点。
根节点 (3) 永远是个好节点。
节点 4 -> (3,4) 是路径中的最大值。
节点 5 -> (3,4,5) 是路径中的最大值。
节点 3 -> (3,1,3) 是路径中的最大值。

示例 2:

输入：root = [3,3,null,4,2]
输出：3
解释：节点 2 -> (3, 3, 2) 不是好节点，因为 "3" 比它大。


示例 3:

输入：root = [1]
输出：1
解释：根节点是好节点。

``` 

提示：

二叉树中节点数目范围是 [1, 10^5] 。
每个节点权值的范围是 [-10^4, 10^4] 。

## Description


Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.


## Example

```bash
Example 1:



Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
Example 2:



Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
Example 3:

Input: root = [1]
Output: 1
Explanation: Root is considered as good.

```

Constraints:

The number of nodes in the binary tree is in the range [1, 10^5].
Each node's value is between [-10^4, 10^4].


`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`

## 解题

全局变量count计数 传参的beacon记录路径上最大的值 比beacon就表明是好节点 并且将beacon变为最大的值

### 代码

```C++
class Solution {
public:
    int count=0;
    void dfs(TreeNode* root,int beacon){
        if(!root) return;
        if(root->val>=beacon){
            beacon=root->val;
            count++;
        }
        if(root->left) dfs(root->left,beacon);
        if(root->right) dfs(root->right,beacon);
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        dfs(root,root->val);
        return count;
    }
};
```

```
执行用时：216 ms, 在所有 C++ 提交中击败了91.73%的用户
内存消耗：86.2 MB, 在所有 C++ 提交中击败了93.26%的用户
```