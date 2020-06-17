# 20(328) 奇偶链表(Medium)

## 描述

给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。


## 示例

```bash

输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL

输入: 2->1->3->5->6->4->7->NULL 
输出: 2->3->6->7->1->5->4->NULL


应当保持奇数节点和偶数节点的相对顺序。
链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推
```

## Description

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

## Example

```bash

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL


The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
The length of the linked list is between [0, 10^4].

```

`Amazon` `Microsoft` `Adobe` `Alibaba` `FaceBook` `Tencent` `Apple` `VMware` `Bloomberg` `HuaWei` `eBay`
## 解题

```bash
#include<iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode* createNodeList(const vector<int> & vec){//后插法创建链表
    ListNode* prev = new ListNode(vec[0]);//prev始终指向表尾指针
    ListNode* prevHead = prev;
    for (int i = 1; i < vec.size(); i ++) {
        ListNode* next_node = new ListNode(vec[i]);
        prev -> next = next_node;
        prev = next_node;
    }
    return prevHead;//prevHead始终指向第一个元素
}
void ShowList(ListNode *l){//遍历输出链表
    ListNode *p=l;
    while(p){
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}
class Solution{
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* odd=head; //odd指向奇数位元素
        ListNode* even=head->next; //even指向偶数位元素
        ListNode* evenHead=new ListNode(-1);
        ListNode* temp=evenHead; //temp始终指向偶链表的尾部
        while(even&&even->next){
            odd->next=even->next;
            temp->next=even;
            temp=temp->next;
            temp->next=NULL;
            odd=odd->next;
            even=odd->next;
        }
        //这个判断情况是 给定的链表元素个数为偶数时 循环判断到even指向最后一个元素odd指向倒数第二个元素的时候循环条件不成立跳出循环时 将even指向的偶数位元素直接连接到偶链表尾部 当链表元素个数为奇数时直接跳出循环就可以了
        if(even!=NULL&&even->next==NULL) temp->next=even;
        odd->next=evenHead->next; //偶链表连接在奇链表之后
        return head;
    }

};
int main(){
    vector<int> m1={1,2,3,4,5};
    ListNode *l1=createNodeList(m1);
    Solution answer;
    l1=answer.oddEvenList(l1);
    ShowList(l1);
    return 0;
}
```