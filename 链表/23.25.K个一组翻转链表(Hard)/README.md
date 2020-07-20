# 23(25) K 个一组翻转链表(Hard)

## 描述

给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

## 示例

```bash

给你这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

```
说明: 你的算法只能使用常数的额外空间。你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
## Description

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

## Example

```bash

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

```
Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.

`BitDance` `Amazon` `Microsoft` `Adobe` `Google` `FaceBook` `Tencent` `Apple` `Bloomberg` `HuaWei` `Uber` `Cisco` `Yahoo` `Baidu` `DiDi`
    
## 解题

利用双指针ListNode* front,back解决问题
front永远指向链表头部的前一个元素 back永远指向链表尾部的后一个元素
```
链表L [1->2->3->4->5] 首先呢为链表L添加一个头结点prevHead=-1 [-1->1->2->3->4->5]
假设k=2 即每次要翻转2个元素 第一次翻转需要翻转`1->2` 所以 front指向-1 back指向3 翻转完毕后 链表变为[-1->2->1->3->4->5] 
第二次翻转需要翻转`3->4` 所以 front指向1 back指向5 翻转完毕后 链表变为[-1->2->1->4->3->5] 以此类推 直到back==NULL退出翻转

back依靠k的大小进行遍历 而front则依靠临时结点temp调整位置 temp永远指向需要翻转的链表的第一个元素 翻转过后 这个第一个元素就变成了最后一个 同时也是下一个需要翻转的链表第一个元素的前一个 第一次翻转需要翻转`1->2` 所以 front指向-1 back指向3 temp指向1 翻转完毕后 链表变为[-1->2->1->3->4->5] temp依旧指向1 然后front=temp front调整到了指向1的位置 第二次翻转需要翻转`3->4` 1现在是3的前一个元素 以此类推 直到back==NULL退出翻转
```

```C++
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prevHead=new ListNode(-1);
        prevHead->next=head;
        ListNode* front=prevHead;
        ListNode* back=head;
        while(back!=NULL){
            int i=0;
            while(i++<k&&back!=NULL){
                back=back->next;
            }
            if(i!=k+1) break;//back中途停了下来
            ListNode* temp=front->next;
            front->next=reverseNList(temp,k);
            front=temp;
        }
        return prevHead->next;
    }
    ListNode* last=NULL;
    ListNode* reverseNList(ListNode* head,int n){//反转链表前n个元素
        if(!head||!head->next||n==1){
            last=head->next;
            return head;
        }
        ListNode* res=reverseNList(head->next,n-1);
        head->next->next=head;
        head->next=last;
        return res;
    }
};
```

```
执行用时：28 ms, 在所有 C++ 提交中击败了60.75%的用户
内存消耗：9.1 MB, 在所有 C++ 提交中击败了100.00%的用户
```