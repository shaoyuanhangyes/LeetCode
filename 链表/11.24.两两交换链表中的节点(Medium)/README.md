# 11(24) 两两交换链表中的结点

## 描述

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

## 示例
```bash
给定 1->2->3->4, 你应该返回 2->1->4->3.
```

## Description
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

## Example
```bash
Given 1->2->3->4, you should return the list as 2->1->4->3.
```
`BitDance` `Amazon` `Microsoft` `Alibaba` `Google` `Apple` `FaceBook` `HuaWei` `Adobe` `Uber` `Mi` `iQiyi` `Baidu` `eBay` `NetEase`
## 解题
```bash
#include<iostream>
#include <vector>
#include <stack>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode* createNodeList(const vector<int> & vec){//创建链表
    ListNode* prev = new ListNode(vec[0]);
    ListNode* prevHead = prev;
    for (int i = 1; i < vec.size(); i ++) {
        ListNode* next_node = new ListNode(vec[i]);
        prev -> next = next_node;
        prev = next_node;
    }
    return prevHead;
}
void ShowList(ListNode *l){//遍历链表并显示
    ListNode *p=l;
    while(p){
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}
class Solution{
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *p=head->next;
        p->next=swapPairs(p->next);
        head->next=p->next;
        p->next=head;
        return p;
    }
};
int main(){
    vector<int> nums={6,5,5,6};
    ListNode *l1=createNodeList(nums);
    Solution answer;
    l1=answer.swapPairs(l1);
    ShowList(l1);
    return 0;
}
```