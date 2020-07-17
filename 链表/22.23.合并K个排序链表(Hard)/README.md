# 22(23) 合并K个排序链表

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

此题为[02.21.合并两个有序链表](https://github.com/shaoyuanhangyes/LeetCode/tree/master/%E9%93%BE%E8%A1%A8/02.21.%E5%90%88%E5%B9%B6%E4%B8%A4%E4%B8%AA%E6%9C%89%E5%BA%8F%E9%93%BE%E8%A1%A8)的进阶版本 因此只需在原版本上加以修改即可

### 顺序合并

使用了利用合并两个有序链表的解法 对传值的数组进行循环遍历 将res->next与数组内的K个链表依次合并两个有序链表 最后输出

```bash
#include<iostream>
#include<vector>

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
    ListNode* MergeList(ListNode* L1,ListNode* L2){
        ListNode* res=new ListNode(-1);
        ListNode* temp=res;
        while(L1&&L2){
            if(L1->val<L2->val){
                temp->next=L1;
                L1=L1->next;
            }
            else{
                temp->next=L2;
                L2=L2->next;
            }
            temp=temp->next;
        }
        if(!L1) temp->next=L2;
        else temp->next=L1;
        return res->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res=new ListNode(-1);
        for(int i=0;i<lists.size();++i){
            res->next=MergeList(res->next,lists[i]);
        }
        return res->next;
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
时间复杂度为![](http://latex.codecogs.com/svg.latex?公式代码O(k^2n))
空间复杂度![](http://latex.codecogs.com/svg.latex?公式代码O(1))
```
执行用时：172 ms, 在所有 C++ 提交中击败了22.95%的用户
内存消耗：10.2 MB, 在所有 C++ 提交中击败了100.00%的用户
```

### 分治法(归并)

将K个链表合并为k/2个链表 然后继续合并成k/4个链表 直到链表数变为1 那么这个链表就是最终的有序链表

```bash
ListNode* MergeTwoList(ListNode* L1,ListNode* L2){
        if(!L1||!L2) return L1?L1:L2;
        ListNode* res=new ListNode(-1);
        ListNode* temp=res;
        while(L1&&L2){
            if(L1->val<L2->val){
                temp->next=L1;
                L1=L1->next;
            }
            else{
                temp->next=L2;
                L2=L2->next;
            }
            temp=temp->next;
        }
        if(!L1) temp->next=L2;
        else temp->next=L1;
        return res->next;
    }
    ListNode* Merge(vector<ListNode*>& lists,int left,int right){
        if(left>right) return NULL;
        if(left==right) return lists[left];
        int mid=(left+right)/2;
        return MergeTwoList(Merge(lists,left,mid),Merge(lists,mid+1,right));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return Merge(lists,0,lists.size()-1);
    }
```
时间复杂度:![](http://latex.codecogs.com/svg.latex?公式代码O(knlog_2k))
空间复杂度:递归会使用到![](http://latex.codecogs.com/svg.latex?公式代码O(log_2k))空间代价的栈空间
```bash
执行用时：48 ms, 在所有 C++ 提交中击败了62.78%的用户
内存消耗：19.7 MB, 在所有 C++ 提交中击败了6.12%的用户
```