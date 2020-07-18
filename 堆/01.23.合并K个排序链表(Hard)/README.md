# 01(23) 合并K个排序链表

## 描述

合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

## 示例

```bash

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

```

## Description

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

## Example

```bash

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Google` `FaceBook` `Tencent` `Apple` `Bloomberg` `HuaWei` `Uber` `Cisco` `Yahoo` `Baidu` `DiDi`
    
## 解题

此md为[链表/22.23.合并K个有序链表(Hard)](https://github.com/shaoyuanhangyes/LeetCode/tree/master/%E9%93%BE%E8%A1%A8/22.23.%E5%90%88%E5%B9%B6K%E4%B8%AA%E6%8E%92%E5%BA%8F%E9%93%BE%E8%A1%A8(Hard))的另一种解法 堆的解法



```bash
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* createList(vector<int> &nums){
    ListNode* prev=new ListNode(nums[0]);
    ListNode* prevHead=prev;
    for(int i=1;i<nums.size();++i){
        ListNode* temp=new ListNode(nums[i]);
        temp->next=prev->next;
        prev->next=temp;
        prev=temp;
    }
    return prevHead;
}

void ShowList(ListNode* L){
    while(L){
        cout<<L->val<<" ";
        L=L->next;
    }
}
class Solution{
public:
    void makeHeap(int* a,int len,int* b){
        for(int i=(len-1)/2;i>=0;i--){
            adjustHeap(a,i,len,b);
        }
    }

    void adjustHeap(int*a,int i,int len,int* b){
        int left=2*i+1;
        int right=2*i+2;
        int minNum=i;
        if(left<=len&&a[left]<a[minNum]) minNum=left;
        if(right<=len&&a[right]<a[minNum]) minNum=right;
        if(minNum!=i){
            swap(a[i],a[minNum]);
            swap(b[i],b[minNum]);
            adjustHeap(a,minNum,len,b);
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists){
        vector<ListNode*> list;
        ListNode* head=new ListNode(-1);
        ListNode* temp=head;
        int n=lists.size();
        if(n==0) return head->next;
        for(int i=0;i<n;++i){
            if(lists[i]!=NULL) list.push_back(lists[i]);
        }
        n=list.size();
        if(n==0) return head->next;
        int a[n],b[n];
        for(int i=0;i<n;++i){
            a[i]=list[i]->val;b[i]=i;
        }
        makeHeap(a,n-1,b);
        int len=n-1;
        while(len>=0){
            ListNode* node=new ListNode(a[0]);
            temp->next=node;
            temp=node;
            if(list[b[0]]->next!=NULL){
                list[b[0]]=list[b[0]]->next;
                a[0]=list[b[0]]->val;
                adjustHeap(a,0,len,b);
            }
            else{
                swap(a[0],a[len]);
                swap(b[0],b[len]);
                len--;
                adjustHeap(a,0,len,b);
            }
        }
        return head->next;
    }
};
int main(){
    vector<int> nums1={1,4,5};
    vector<int> nums2={1,3,4};
    vector<int> nums3={2,6};
    ListNode* L1=createList(nums1);
    ListNode* L2=createList(nums2);
    ListNode* L3=createList(nums3);
    vector<ListNode*> L;
    L.push_back(L1);L.push_back(L2);L.push_back(L3);
    Solution answer;
    ListNode* res=answer.mergeKLists(L);
    ShowList(res);
    return 0;
}
```

```
执行用时：36 ms, 在所有 C++ 提交中击败了85.79%的用户
内存消耗：11.1 MB, 在所有 C++ 提交中击败了46.94%的用户
```