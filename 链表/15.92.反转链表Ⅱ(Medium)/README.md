### 15(92) 反转链表Ⅱ

## 描述

反转从位置 m 到 n 的链表。请使用一趟扫描完成反转

## 示例
```bash

1 ≤ m ≤ n ≤ 链表长度

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

```

## Description

Reverse a linked list from position m to n. Do it in one-pass.

## Example
```bash

Note: 1 ≤ m ≤ n ≤ length of list.

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL

```

`Amazon` `FaceBook` `BitDance` `Microsoft` `vivo` `Alibaba` `Tencent` `Apple` `Adobe` `Google` `Uber` `iQiyi` `HuaWei` `Baidu`
## 解题

### 第一次提交的屎一样的代码 但是通过了
```bash
ListNode* reverseBetween(ListNode* head, int m, int n) {//1<=m<=n<=len
        if(head==NULL||head->next==NULL) return head;
        ListNode* prev=new ListNode(-1);
        prev->next=head;
        ListNode* slow=prev;
        ListNode* fast=prev;
        ListNode* front=prev;
        int l=m-1;
        while(l--) front=front->next;
        while(m--) slow=slow->next;
        while(n--) fast=fast->next;
        ListNode* back=fast->next;
        fast->next=NULL;
        ListNode* res=reverseList(slow);
        front->next=res;
        ListNode* p=res;
        while(p->next){
            p=p->next;
        }
        p->next=back;
        return prev->next;
    }
    ListNode* reverseList(ListNode* head){
        if(head==NULL||head->next==NULL) return head;
        ListNode* res=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return res;
    }
```
### 使用递归解决

#### 反转整个链表
```C++
ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* res=reverseList(head->next);//以{1,2,3,4,5}为例
        head->next->next=head;//reverse递归传参 到5返回5结点 res指向5 回到4这一层 head指向4 head->next->next=head是4->next->next
        //是4->next->next=4即5->next=4
        head->next=NULL;//然后4->next=NULL断链 再将5-4返回给上一层连上3 在连上2 1 反转成功
        return res;
    }
```
### 反转链表的前N个元素

```C++
ListNode* last=NULL;
ListNode* reverseN(ListNode* head,int n){
    if(head==NULL||head->next==NULL||n==1) {
        last=head->next; //last: 4->5->NULL last记录反转的前N个元素断开的位置 1 2 3 4 5 n=2 last就指向3 方便反转后再连接
        return head;
    }
    ListNode* res=reverseN(head->next,n-1);
    head->next->next=head; 
    head->next=last;
    return res;
}
```
### 反转链表中m位置到n位置的元素

将问题简化为反转链表的前N个元素 即递归终止条件为m=1 
```bash
ListNode* reverseBetween(ListNode* head,int m,int n){
    if(m==1) return reverseN(head,n);
    head->next=reverseBetween(head->next,m-1,n-1);
    return head;
}
```