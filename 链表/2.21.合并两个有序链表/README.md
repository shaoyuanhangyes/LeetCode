# 2(83) 合并两个有序链表
## 描述
将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
## 示例
```bash
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
``` 

## Description
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

## Example
```bash
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

```
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *prev = new ListNode(-1);
        ListNode *preHead=prev;
        while(l1&&l2){
            if(l1->val < l2->val){
                prev->next=l1;
                l1=l1->next;
            }
            else{
                prev->next=l2;
                l2=l2->next;
            }
            prev=prev->next;
        }
        if(!l1) prev->next=l2;
        else prev->next=l1;
        return preHead->next;//prevHead存的-1
    }
};
int main(){
    vector<int> m1={1,4,9};
    vector<int> m2={2,3,5,6};
    ListNode *l1=createNodeList(m1);
    ListNode *l2=createNodeList(m2);
    Solution answer;
    ListNode *l3=answer.mergeTwoLists(l1,l2);
    ShowList(l3);
    return 0;
}

```