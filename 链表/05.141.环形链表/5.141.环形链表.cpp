#include<iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head;//慢指针 一次只移动一格
        ListNode *fast=head;//快指针 一次移动二格
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;//若快慢指针能够相遇 则说明链表有环
        }
        return false;//快指针到了链表尾部 说明链表无环
    }
    
};
