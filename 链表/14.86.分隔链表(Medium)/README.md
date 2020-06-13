### 14(86) 分隔链表

## 描述

给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

## 示例
```bash

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

```

## Description

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

## Example
```bash

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5

```

## 解题

新建两个新的链表r1 r2 
r1存放链表head中<x的结点 r2存放链表head中>x的结点
这里有一个坑 不能直接将p接在r1/r2的后面 否则判断到最后一个元素时如果不满足循环里的if (因为是最后一个元素所以判断完就跳出循环) 循环结束了这个不满足条件的结点会保留在这个链表中
因此每一次if判断大小后都需要新建一个new ListNode(p->val) 因为在定义结构体的时候使用了初始化`ListNode(int x):val(x),next(NULL){}` 所以可以直接给结点赋值x 而这个结点的next默认设置为NULL 正合我意
遍历找出<x的结点加入r1中 >x的结点加入r2中
遍历全部完成后 将r2->next接到r1尾部(q) 返回r1->next就是我们的解
```
执行用时 :4 ms, 在所有 C++ 提交中击败了95.45%的用户
内存消耗 :6.9 MB, 在所有 C++ 提交中击败了100.00%的用户
```
```bash
#include<iostream>
#include <vector>
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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return head;
        ListNode *p=head;
        ListNode *r1=new ListNode(-1);
        ListNode *q=r1;
        ListNode *r2=new ListNode(-1);
        ListNode *c=r2;
        while(p){
            if(p->val<x){
                q->next=new ListNode(p->val);
                q=q->next;
                p=p->next;
            }
            else{
                c->next=new ListNode(p->val);
                c=c->next;
                p=p->next;
            }
        }
        q->next=r2->next;
        delete r2;
        return r1->next;
    }
};
int main(){
    vector<int> nums={1,4,3,2,5,2};
    ListNode *l1=createNodeList(nums);
    Solution answer;
    l1=answer.partition(l1,3);
    ShowList(l1);
    return 0;
}
```