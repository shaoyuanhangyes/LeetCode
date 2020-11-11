# 44(255) 验证前序遍历序列二叉搜索树(Medium)

255. Verify Preorder Sequence in Binary Search Tree

## 描述

给定一个整数数组，你需要验证它是否是一个二叉搜索树正确的先序遍历序列。

你可以假定该序列中的数都是不相同的。

## 示例

```

参考以下这颗二叉搜索树：

     5
    / \
   2   6
  / \
 1   3
示例 1：

输入: [5,2,6,1,3]
输出: false
示例 2：

输入: [5,2,1,3,6]
输出: true

```

进阶挑战：

您能否使用恒定的空间复杂度来完成此题？

## Description

Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

## Example

```bash

Consider the following binary search tree: 

     5
    / \
   2   6
  / \
 1   3
Example 1:

Input: [5,2,6,1,3]
Output: false
Example 2:

Input: [5,2,1,3,6]
Output: true

```

Follow up:

Could you do it using only constant space complexity?

`Mathworks` `Alibaba` `Pony.ai` `Amazon` `Facebook` `Uber` `VMware` `eBay` `Bloomberg`

## 解题

```
       5
      / \
     2   6
    / \
   1   3
```

在只有左子树的时候 前序遍历的序列是单调递减的 即`[5 2 1]` 但加入3的时候 `[5 2 1 3]`变的不单调 说明3是某一个结点的右子树 如何找到这个某一个结点呢 

我们使用一个单调栈 将`[5 2 1]`按先序遍历的顺序压入栈中 然后将3和栈顶元素比较 若大于栈顶元素 就将栈顶元素出栈 再比较 直到栈顶元素大于3 此时 最后一个出栈的元素就是3的父结点

所以 1 2 出栈 单调栈变为`[5 3]` 即 3是2的右子树  

接下来是 6和栈顶元素比较 所以3 5 出栈 栈为空 即 6是5的右子树 

以上是由二叉搜索树分析前序遍历的序列  接下来我们从序列出发 剖析一下如何判断

序列1. `[5,2,1,3,6]` 因为是前序遍历 所以 递减的部分为左子树 5 2 1 递减后开始递增的部分是某个结点的右子树 3 6 这个是一个合法的二叉搜索树的前序遍历

序列2. `[5,2,6,1,3]` 递减部分为左子树 5 2 递减后开始递增的部分是某个结点的右子树 6 但是突然出现了一只打断递增的数 1 不符合二叉搜索树前序遍历序列的特点 所以是错误的

### 代码

```C++

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.empty()) return true;
        stack<int> st;
        int min=INT_MIN;
        for(int x:preorder){
            if(x<min) return false;
            while(!st.empty()&&x>st.top()){
                min=st.top();
                st.pop();
            }
            st.push(x);
        }
        return true;
    }
};

```

```

```