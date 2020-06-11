# 12(61) 旋转链表

## 描述

给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

## 示例
```bash

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL

解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL


输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL

解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL

```

## Description

Given a linked list, rotate the list to the right by k places, where k is non-negative.

## Example
```bash

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL

Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL


Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL

```

## 解题
解题思路为 先用指针p遍历链表求得表长len 顺便将遍历指针p始终放置在链表尾部 与第一个结点head相连 成为环形链表
再计算移动k个位置的余数remain=k%len
若k能整除len 则直接断开之前表尾结点与第一个结点的连接 
若不能整除 则等同于链表中每个结点像右移动remain个位置
新建一个指针q始终指向第一个结点
这里有一个陷阱 题目中描述的是每个结点向右移动k个位置=指针向左移动remain个位置 但是单链表结点只能向后(右)移动 但我们已经将链表设置成了环形链表 因此我们可以将指针p q向后(右)移动len-remain个位置
移动完成后 将p->next=NULL 断开链表 返回q
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode *p=head;
        int len=1;//记录链表长度
        while(p->next){
            len++;
            p=p->next;
        }
        p->next=head;
        int remain=k%len;//记录余数
        if(remain==0){
            p->next=NULL;
            return head;
        }
        ListNode *q=head;
        for(int i=0;i<len-remain;i++){//移动节点的次数为 表长-余数
            q=q->next;
            p=p->next;
        }
        p->next=NULL;
        return q;
    }
};
int main(){
    vector<int> nums={0,1,2};
    ListNode *l1=createNodeList(nums);
    Solution answer;
    l1=answer.rotateRight(l1,4);
    ShowList(l1);
    return 0;
}
```