# 21(445) 两数相加Ⅱ(Medium)

## 描述

给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

进阶: 如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转

## 示例

```bash
输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 8 -> 0 -> 7
```

## Description

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

## Example

```bash

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Google` `FaceBook` `Tencent` `Apple` `Bloomberg` `HuaWei` `Uber` `Cisco` `Yahoo` `Baidu` `DiDi`
    
## 解题

利用栈进行迭代 栈空了还要继续求和的时候就赋予0继续进行求和
```c++
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1,s2;
        while(l1){
            s1.push(l1);
            l1=l1->next;
        }
        while(l2){
            s2.push(l2);
            l2=l2->next;
        }
        int sum=0;
        int carry=0;
        ListNode* res=new ListNode(-1);
        ListNode* temp=NULL;
        while(!s1.empty()||!s2.empty()||carry!=0){
            if(s1.empty()) l1=new ListNode(0);
            else {
                l1=s1.top();s1.pop();
            }
            if(s2.empty()) l2=new ListNode(0);
            else{
                l2=s2.top();s2.pop();
            }
            sum=(l1->val+l2->val+carry)%10;
            carry=(l1->val+l2->val+carry)/10;
            temp=new ListNode(sum);
            temp->next=res->next;
            res->next=temp;
        }
        return res->next;
    }
};
```