# 30(637)  左叶子之和
## 描述

给定一个非空二叉树, 返回一个由每层节点平均值组成的数组

## 示例

```bash

输入：
    3
   / \
  9  20
    /  \
   15   7
输出：[3, 14.5, 11]
解释：
第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 。
 

提示：

节点值的范围在32位有符号整数范围内。

``` 

## Description

Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

## Example

```bash

Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`

## 解题

按照层序遍历的思想 在遍历每一层的时候存储元素和 和值除以这一层的元素数量就是平均值 最后存入res数组
```C++
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(!root) return res;
        TreeNode* node=root;
        queue<TreeNode*> st;
        st.push(node);
        while(!st.empty()){
            int len=st.size();
            int temp=len;
            double sum=0;//必须是double类型 
            while(len--){
                node=st.front();st.pop();
                sum+=node->val;
                if(node->left) st.push(node->left);
                if(node->right) st.push(node->right);
            }
            res.push_back(sum/temp);
        }
        return res;
    }
};
```

```
执行用时：20 ms, 在所有 C++ 提交中击败了97.60%的用户
内存消耗：22.7 MB, 在所有 C++ 提交中击败了32.76%的用户
```