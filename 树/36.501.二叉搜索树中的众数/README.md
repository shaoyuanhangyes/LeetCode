# 36(501) 二叉搜索树中的众数

## 描述

给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：

结点左子树中所含结点的值小于等于当前结点的值
结点右子树中所含结点的值大于等于当前结点的值
左子树和右子树都是二叉搜索树


## 示例

```bash 

例如：
给定 BST [1,null,2,2],

   1
    \
     2
    /
   2
返回[2].

```

提示：如果众数超过1个，不需考虑输出顺序

进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）

## Description



Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.


## Example

```bash

Given BST [1,null,2,2],

   1
    \
     2
    /
   2
 

return [2].

```

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `Mi` `HuaWei` `VMware`

## 解题

不使用额外空间帮助查找众数 即空间复杂度O(1) 因此需要Morris中序遍历二叉搜索树

### Morris中序遍历代码
```C++
vector<int> Morris_inOrder(TreeNode* root){
    vector<int> res;
    if(!root) return res;
    TreeNode* cur=root;
    TreeNode* mostright=NULL;
    while(cur!=NULL){
        mostright=cur->left;
        if(mostright!=NULL){
            while(mostright->right!=NULL&&mostright->right!=cur) mostright=mostright->right;
            if(mostright->right==NULL){
                mostright->right=cur;
                cur=cur->left;
                continue;
            }
            else{
                mostright->right=NULL;
                res.push_back(cur->val);
            }
        }
        else res.push_back(cur->val);
        cur=cur->right;
    }
    return res;
}
```

只需要在Morris中序遍历序列上进行判断众数即可

### 判断众数的代码片段

使用双指针判断众数 cur向右移动前 pre保存cur移动前的值 

通过比较pre和cur的值是否相等来决定count的值

TreeNode* cur=root;
TreeNode* pre=NULL;
int count=0,maxCount=0;

```C++
    if(pre&&pre->val==cur->val) count++;
    else count=1;
    if(count>maxCount){
        maxCount=count;
        res.clear();
        res.push_back(cur->val);
    }
    else if(count==maxCount) res.push_back(cur->val);
```

### 解题代码

```C++
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        TreeNode* cur=root;
        TreeNode* mostright=NULL;
        TreeNode* pre=NULL;
        int count=0,maxCount=0;
        while(cur!=NULL){
            mostright=cur->left;
            if(mostright!=NULL){
                while(mostright->right!=NULL&&mostright->right!=cur) mostright=mostright->right;
                if(mostright->right==NULL){
                    mostright->right=cur;
                    cur=cur->left;
                    continue;
                }
                else{
                    if(pre&&pre->val==cur->val) count++;
                    else count=1;
                    if(count>maxCount){
                        maxCount=count;
                        res.clear();
                        res.push_back(cur->val);
                    }
                    else if(count==maxCount) res.push_back(cur->val);
                    mostright->right=NULL;
                }
            }
            else{//左子树为空
                if(pre&&pre->val==cur->val) count++;
                else count=1;
                if(count>maxCount){
                    maxCount=count;
                    res.clear();
                    res.push_back(cur->val);
                }
                else if(count==maxCount) res.push_back(cur->val);
            }
            pre=cur;
            cur=cur->right;
        }
        return res;
    }
};
```