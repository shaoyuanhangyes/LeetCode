# 6(19) 删除链表的倒数第N个节点
## 描述
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点
## 示例
```bash
给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
```
给定的 n 保证是有效的。
你能尝试使用一趟扫描实现吗？
## Description
Given a linked list, remove the n-th node from the end of list and return its head.

## Example
```bash
Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
```
Given n will always be valid.
Could you do this in one pass?
## 解题
### 常规方法(两趟遍历)
先遍历一趟求表长len 再将指针遍历到需要删除的倒数第n个元素的前一个上 直接删除他的后续节点
```bash
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p=head;
        int len=0;
        while(p){
            len++;
            p=p->next;
        }
        p=head;
        if(n==len) return head->next;
        for(int i=0;i<len-n-1;i++){//将p指向要删除结点的前一个
            p=p->next;
        }
        p->next=p->next->next;
        return head;
    }
```
题目进阶要求是遍历一趟
### 进阶方法
```bash

```