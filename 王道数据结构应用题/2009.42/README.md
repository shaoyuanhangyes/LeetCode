## 题目描述

已知一个带表头结点的单链表 假设链表只给出了头指针list 在不改变链表的前提下 请设计一个尽可能高效的算法 查找链表中倒数第k个位置上的结点 k为正整数 若查找成功 算法输出该结点的data值 并返回1 否则 只返回0

链表的结构如下

|data|link|
|:------:|:------:|

## 题解 

使用双指针求解 

left和right指针都指向`list->link`

right先向后移动k个位置 然后将right和left同时向链表尾部移动 直到right位于链表尾部时 此时left指向的元素就是题意要寻找的倒数第k个元素

## 代码

```C++
#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
    int data;
    ListNode* link;
    ListNode(int x):data(x),link(NULL){}
};

ListNode* createList(vector<int>& nums){
    ListNode* list=new ListNode(-1);
    ListNode* prev=list;
    for(int i=0;i<nums.size();++i){
        ListNode* node=new ListNode(nums[i]);
        prev->link=node;
        prev=node;
    }
    return list;
}

bool searchKpositon(ListNode* list,int k){
    ListNode* left=list->link;
    ListNode* right=list->link;
    while(--k) right=right->link;//倒数第k个位置 k从1开始 如果循环条件是k-- left和right之间的距离会少1 即会输出倒数第k+1个元素
    if(right==NULL) return 0;//若right移动k个后为NULL 则说明k的值大于链表长度 非法
    while(right->link!=NULL){
        right=right->link;
        left=left->link;
    }
    cout<<left->data<<endl;
    return 1;
}


int main(){
    vector<int> nums={5,4,3,2,1};
    ListNode* list=createList(nums);
    int k;
    cout<<"k value="<<endl;
    cin>>k;
    cout<<searchKpositon(list,k);
    return 0;
}
```