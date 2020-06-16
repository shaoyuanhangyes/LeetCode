# 19(148) 排序链表(Medium)

## 描述

在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

## 示例

```bash

输入: 4->2->1->3
输出: 1->2->3->4

输入: -1->5->3->4->0
输出: -1->0->3->4->5

```

## Description

Sort a linked list in O(n log n) time using constant space complexity.

## Example

```bash

Input: 4->2->1->3
Output: 1->2->3->4

Input: -1->5->3->4->0
Output: -1->0->3->4->5

```

`Amazon` `Microsoft` `Adobe` `Alibaba` `FaceBook` `Tencent` `Apple` `VMware` `iQiyi` `Uber``Bloomberg`
## 解题

### 递归归并排序 
空间复杂度不符合要求 只作为一种解法 

要注意的坑: 首先要探查到链表的中间节点 然后分割 一定会用到快慢双指针 但是快指针走到链表尾部的时候 慢指针指向的元素的确为逻辑上链表元素的中间结点 但当链表元素数量为偶数时 eg:`1 2 3 4` slow会指向3 因此需要作出微调 使用指针back保存slow移动前的位置 然后再对back->next=NULL断链 这样就将链表分割了
将链表分割后对左右部分进行递归 然后对 左右部分进行比较大小
新建一个指针p p指向left&right元素比较后较小的那一个 然后较小的left&right向后移 判断完成后p向后移 直到left&right有一个判断尽 循环结束后一定会有一个元素未连接到链表中 若left为NULL 则right指向的需要给连接到链表中 若right为NULL 则left指向的需要给连接到链表中

```bash
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* back=slow;
        while(fast&&fast->next){
            back=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp=back->next;
        back->next=NULL;
        ListNode* left=sortList(head);
        ListNode* right=sortList(temp);
        ListNode* p=new ListNode(-1);
        ListNode* h=p;
        while(left&&right){
            if(left->val>right->val){
                p->next=right;
                right=right->next;
            }
            else{
                p->next=left;
                left=left->next;
            }
            p=p->next;
        }
        p->next=left?left:right;
        return h->next;
    }
};

```
### 迭代解法

```bash

```