### 17(143) 重排链表(Medium)

## 描述

给定一个单链表 L：L0→L1→…→Ln-1→Ln 
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换

## 示例
```bash

给定链表 1->2->3->4, 重新排列为 1->4->2->3.

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

```

## Description

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.


## Example
```bash

Given 1->2->3->4, reorder it to 1->4->2->3.

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

```

`Amazon` `FaceBook` `BitDance` `Microsoft` `eBay` `Alibaba` `Tencent` `Cisco` `Adobe` `Google` `Uber` `HuaWei` `Mi`
## 解题

### 第一次提交的通过的屎一样的代码

```C++
    void reorderList(ListNode *head){
        if(head==NULL||head->next==NULL) return;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* back=head;
        while(fast&&fast->next){
            back=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        back->next=NULL;
        ListNode* reve=reverse(slow);
        ListNode* p=head;
        ListNode* q=reve;
        while(p&&q){
            ListNode* temp=new ListNode(q->val);
            temp->next=p->next;
            p->next=temp;
            q=q->next;
            p=p->next->next;
        }
        if(!p){
            ListNode *temp=head;
            while(temp->next) temp=temp->next;
            temp->next=q;
        }
    }
    ListNode* reverse(ListNode* head){
        if(head==NULL||head->next==NULL) return head;
        ListNode* res=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return res;
    }
```
新声明了太多的指针 空间浪费 最后还要判断q比p长的情况 
对reordList进行了修改 
### 新提交的代码

修改的问题: 上面的代码是将back之后的链表反转并断链 这样会出现两种情况 链表内元素个数为偶数时 两个链表一样长 元素个数为奇数时 反转的链表势必会比正序的链表长度大1  while循环就会设计的很复杂
对代码进行修改 舍弃掉back 直接对 slow->next进行反转 这样 元素为偶数时 两个链表元素相等 元素为奇数时 反转的链表比正序的链表元素小 这样就无序考虑正序链表遍历的时候会溢出的问题
两个链表相连接 使用一个临时指针temp保存反转链表后续的节点 然后将rL指向的节点连接到两个元素之间  再移动head到rl->next 最后将临时指针temp的信息传递给rL进行下一次循环

```C++
void reorderList(ListNode *head){
        if(head==NULL||head->next==NULL) return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* rL=reverse(slow->next);//反转
        slow->next=NULL;
        while(rL){
            ListNode* temp=rL->next;
            rL->next=head->next;
            head->next=rL;
            head=rL->next;
            rL=temp;
        }
    }
```