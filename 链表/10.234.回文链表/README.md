# 10(234) 回文链表

## 描述

请判断一个链表是否为回文链表。

## 示例
```bash
输入: 1->2
输出: false

输入: 1->2->2->1
输出: true
```
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
## Description
Given a singly linked list, determine if it is a palindrome.

## Example
```bash
Input: 1->2
Output: false

Input: 1->2->2->1
Output: true
```
Could you do it in O(n) time and O(1) space?
## 解题
### 解法一 利用栈的特性
```bash
#include<iostream>
#include <vector>
#include <stack>
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
class Solution{
public:
    bool isPalindrome(ListNode* head) {
        ListNode *p=head;
        stack<int> st;
        while(p){
            st.push(p->val);
            p=p->next;
        }
        p=head;
        while(p){
            if(p->val==st.top()){
                p=p->next;
                st.pop();
            }
            else return false;
        }
        return true;
    }
};
int main(){
    vector<int> nums={6,5,5};
    ListNode *l1=createNodeList(nums);
    Solution answer;
    bool res=answer.isPalindrome(l1);
    cout<<res;
    return 0;
}
```