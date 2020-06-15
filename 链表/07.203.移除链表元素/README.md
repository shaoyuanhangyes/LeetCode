# 7(203) 移除链表元素

## 描述
删除链表中等于给定值 val 的所有节点。
## 示例
```bash
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
```

## Description
Remove all elements from a linked list of integers that have value val.
## Example
```bash
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
```

`BitDance` `Amazon` `Microsoft` `Alibaba` `Adobe` `Apple` `Google` `Tencent` `Uber` `Paypal` `HuaWei` `Baidu`
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

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *s=new ListNode(-1);
        s->next=head;
        ListNode *q=s;
        while(q->next){
            if(q->next->val==val){
                q->next=q->next->next;
            }
            else{
                q=q->next;
            }
        }
        return s->next;
    }
};

int main(){
    vector<int> nums={3,1,3,1};
    ListNode *l1=createNodeList(nums);
    Solution answer;
    ShowList(answer.removeElements(l1,1));
    return 0;
}
```