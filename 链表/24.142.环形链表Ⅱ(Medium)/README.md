# 24(142) 环形链表Ⅱ(Medium)

## 描述

给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

## 示例

```bash
示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：

输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：

输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。

```

进阶：
你是否可以不用额外空间解决此题？

## Description

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.

## Example

```bash

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

```

Follow-up:
Can you solve it without using extra space?


`BitDance` `Amazon` `Microsoft` `Adobe` `Google` `FaceBook` `Tencent` `Apple` `Bloomberg` `HuaWei` `Uber` `Cisco` `Yahoo` `Baidu` `DiDi`
    
## 解题

### 思路

利用快慢双指针来判断链表是否是环形链表 若快慢指针可以相遇 意味着链表是环形的 可以得到快慢指针相遇的位置 接下来利用相遇的位置来找到环形链表的起点结点

直接上结论: 链表的第一个结点开始 向后走a个距离到环形链表的起点   快慢指针相遇的节点 向后走a个距离也到环形链表的起点 因此需要再来一个指针temp从第一个结点开始向后遍历 

slow从相遇的位置开始向后遍历 slow与temp相遇的位置 就是环形链表的起点结点 

### 代码
```C++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                ListNode* temp=head;
                while(temp!=slow){
                    temp=temp->next;
                    slow=slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
```

```
执行用时：16 ms, 在所有 C++ 提交中击败了27.21%的用户
内存消耗：7.7 MB, 在所有 C++ 提交中击败了44.67%的用户
```