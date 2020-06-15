# 5(141) 环形链表
## 描述
给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。


## 示例
```bash
输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。

输入：head = [1], pos = -1
输出：false
解释：链表中没有环。
```
你能用 O(1)（即，常量）内存解决此问题吗？
## Description
Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.


## Example
```bash
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

```
`BitDance` `Amazon` `Microsoft` `Alibaba` `FaceBook` `Google` `Tencent` `Adobe` `Yahoo` `Linkedln` `Uber` `iQiyi` `Baidu`
## 解题
```bash
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head;//慢指针 一次只移动一格
        ListNode *fast=head;//快指针 一次移动二格
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;//若快慢指针能够相遇 则说明链表有环
        }
        return false;//快指针到了链表尾部 说明链表无环
    }
    
};
```