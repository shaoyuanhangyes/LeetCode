### 16(109) 有序链表转换二叉搜索树(Medium)

## 描述

给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1


## 示例
```bash

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

```

## Description

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

## Example
```bash

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

```

`Amazon` `FaceBook` `BitDance` `Microsoft` `Cisco` `Adobe` `Google` `IBM` `Lyft` `VMware` `iQiyi` `Bloomberg`
## 解题

```bash
#include<iostream>
#include <vector>
#include <queue>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
};
ListNode* createNodeList(const vector<int> & vec){//后插法创建链表
    ListNode* prev = new ListNode(vec[0]);//prev始终指向表尾指针
    ListNode* prevHead = prev;
    for (int i = 1; i < vec.size(); i ++) {
        ListNode* next_node = new ListNode(vec[i]);
        prev -> next = next_node;
        prev = next_node;
    }
    return prevHead;//prevHead始终指向第一个元素
}
void ShowList(ListNode *l){//遍历输出链表
    ListNode *p=l;
    while(p){
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}
vector<vector<int>> levelOrder(TreeNode* root) {//层序遍历
    vector<vector<int>> res;
    if(!root) return res;
    queue<TreeNode* > Tree;
    Tree.push(root);
    while(!Tree.empty()){
        vector<int> temp;
        int len=Tree.size();
        while(len--){
            TreeNode *pNode=Tree.front();
            Tree.pop();
            temp.push_back(pNode->val);
            if(pNode->left) Tree.push(pNode->left);
            if(pNode->right) Tree.push(pNode->right);
        }
        res.push_back(temp);
    }
    return res;
}
//打印二维数组
void PrintMartrix(vector<vector<int>>& res){
    for(int i=0;i<res.size();++i){
        cout<<"[";
        for(int j=0;j<res[i].size();++j){
            cout<<" "<<res[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
}
/*以上都为整个程序能够正常输出的必要函数*/

class Solution{
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;//链表为空返回NULL
        if(head->next==NULL) return new TreeNode(head->val);//链表只有一个元素返回根结点
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* back=NULL;
        while(fast&&fast->next){
            back=slow;
            slow=slow->next;
            fast=fast->next->next;
        }//back永远指向slow的前一个
        TreeNode* root=new TreeNode(slow->val);
        back->next=NULL;//左半部分断链
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(slow->next);
        return root;
    }
};


int main(){
    vector<int> m1={-10,-3,0,5,9};
    ListNode *l1=createNodeList(m1);
    Solution answer;
    ShowList(l1);
    TreeNode *root=answer.sortedListToBST(l1);
    vector<vector<int>> res=levelOrder(root);
    PrintMartrix(res);
    return 0;
}

```

程序运行后结果为
```bash
-10 -3 0 5 9
[ 0 ]
[ -3  9 ]
[ -10  5 ]
```