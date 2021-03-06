### 18(147) 对链表进行插入排序(Medium)

## 描述

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。

每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。

重复直到所有输入数据插入完为止。

## 示例

```bash

输入: 4->2->1->3
输出: 1->2->3->4

输入: -1->5->3->4->0
输出: -1->0->3->4->5

```

## Description

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

## Example

```bash

Input: 4->2->1->3
Output: 1->2->3->4

Input: -1->5->3->4->0
Output: -1->0->3->4->5

```

`Amazon` `Microsoft` `Adobe` `Alibaba` `Tencent` `Apple` `VMware` `iQiyi` `Bloomberg`
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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* prevHead=new ListNode(-1);
        prevHead->next=head;
        ListNode* now=head->next;//now为进行判断比较大小的基元素
        ListNode* last=head;//last为now前一个结点 用于连接
        ListNode* t=prevHead;//t为head前一个结点 用于连接
        while(now){
            while(head!=now){
                if(now->val>head->val){
                    t=head;
                    head=head->next;
                }
                else{
                    last->next=now->next;
                    now->next=head;
                    t->next=now;
                    now=last;
                    break;
                }
            }
            last=now;
            now=now->next;
            //归位
            t=prevHead;
            head=t->next;
        }
        return prevHead->next;
    }

};
int main(){
    vector<int> m1={6,7,1,4,2};
    ListNode *l1=createNodeList(m1);
    Solution answer;
    l1=answer.insertionSortList(l1);
    ShowList(l1);
    return 0;
}
```

输出结果为
```bash

1 2 4 6 7

```