# 10(95) 不同的二叉搜索树Ⅱ
## 描述

给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 

提示: 0 <= n <= 8

## 示例
```bash

输入：3
输出：
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释：
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

``` 

## Description

Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Constraints: 0 <= n <= 8
## Example

```bash

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

```
`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`
## 解题

ret数组存着每一个二叉搜索树的关系 例如:
```bash
    3                ret[0]->val=3;
   /                 
  2                  ret[0]->left->val=2;
 /
1                    ret[0]->left->left=1;
```
```bash
vector<TreeNode*> createTrees(int start,int end){
        vector<TreeNode*> ret;
        if(start>end){
            ret.push_back(NULL);
            return ret;
        }
        for(int i=start;i<=end;i++){
            auto leftNode=createTrees(start,i-1);
            auto rightNode=createTrees(i+1,end);
            for(auto l:leftNode){
                for(auto r:rightNode){
                    TreeNode* node=new TreeNode(i);
                    node->left=l;
                    node->right=r;
                    ret.push_back(node);
                }
            }
        }
        return ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return vector<TreeNode*>();
        return createTrees(1,n);;
    }
```
