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

`BitDance` `Amazon` `Microsoft` `Alibaba` `Apple` `Google` `Tencent` `Adobe` `Uber` `Paypal` `HuaWei` `Baidu`
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
方法为快慢双指针
分别定义指针first second指向链表第一个元素 
first先向后移动n个位置 然后判断first指针位置是否合法
### 进阶方法
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first=head;
        ListNode *second=head;
        while(n--){
            first=first->next;
        }
        if(first!=NULL){
            while(first->next){
                first=first->next;
                second=second->next;
            }
            second->next=second->next->next;
            return head;
        }
        else return head->next;
    }
};
int main(){
    vector<int> nums={6,5,4,3,2,1};
    ListNode *l1=createNodeList(nums);
    Solution answer;
    ShowList(answer.removeNthFromEnd(l1,7));
    return 0;
}
```