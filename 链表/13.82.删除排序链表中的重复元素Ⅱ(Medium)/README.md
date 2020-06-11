### 13(82) 删除排序链表中的重复元素Ⅱ

## 描述

给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

## 示例
```bash

输入: 1->2->3->3->4->4->5
输出: 1->2->5

输入: 1->1->1->2->3
输出: 2->3

```

## Description

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

## Example
```bash

Input: 1->2->3->3->4->4->5
Output: 1->2->5

Input: 1->1->1->2->3
Output: 2->3

```

## 解题
为处理第一个结点就是重复结点 为链表head添加一个头结点prev
指针a指向prev 指针b指向prev->next
判断a->next->val 与 b->next->val的值是否相等 
若 a->next->val!=b->next->val a和b都向后移动一格
若 a->next->val==b->next->val 就将b向后移动到a->next->val!=b->next->val的位置 也就是值相等的最后一个元素的位置 
然后将b向后移动一格 a->next指向b 这样就删除掉了中间一直相等的元素
就这样一直循环判断 直到b到链表表尾
```bash
#include<iostream>
#include <vector>
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *prev=new ListNode(-1);
        prev->next=head;
        ListNode *a=prev;
        ListNode *b=prev->next;
        while(b&&b->next){
            if(a->next->val!=b->next->val){
                b=b->next;
                a=a->next;
            }
            else{
               while(b&&b->next&&a->next->val==b->next->val){
                   b=b->next;
               }
               b=b->next;
               a->next=b;
            }
        }
        return prev->next;
    }
};
int main(){
    vector<int> nums={1,1,1,2,2,3,4,5,5,6};
    ListNode *l1=createNodeList(nums);
    Solution answer;
    l1=answer.deleteDuplicates(l1);
    ShowList(l1);
    return 0;
}
```