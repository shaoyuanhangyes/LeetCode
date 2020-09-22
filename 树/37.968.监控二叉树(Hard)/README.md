# 37(968) 监控二叉树(Hard)
## 描述

给定一个二叉树，我们在树的节点上安装摄像头。

节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。

计算监控树的所有节点所需的最小摄像头数量。


## 示例

```bash 

输入：[0,0,null,0,0]
输出：1
解释：如图所示，一台摄像头足以监控所有节点。

输入：[0,0,null,0,null,0,null,null,0]
输出：2
解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。


```

提示：

给定树的节点数的范围是 [1, 1000]。
每个节点的值都是 0。

## Description

Given a binary tree, we install cameras on the nodes of the tree. 

Each camera at a node can monitor its parent, itself, and its immediate children.

Calculate the minimum number of cameras needed to monitor all nodes of the tree.


## Example

```bash

Input: [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.

Input: [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.

```

Note:

The number of nodes in the given tree will be in the range [1, 1000].
Every node has value 0.


`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`


## 解题


### 代码


```C++
class Solution {
public:
    int minCameraCover(TreeNode* root) {

    }
};

```