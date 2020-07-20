#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* createList(vector<int>& nums){
    ListNode* prevHead=new ListNode(nums[0]);
    ListNode* prev=prevHead;
    for(int i=1;i<nums.size();++i){
        ListNode* node=new ListNode(nums[i]);
        prev->next=node;
        prev=node;
    }
    return prevHead;
}

void ShowList(ListNode* L){
    while(L!=NULL){
        cout<<L->val<<" ";
        L=L->next;
    }
}
ListNode* reverseList(ListNode *head){//翻转整个链表
    if(!head||!head->next) return head;
    ListNode* res=reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    return res;
}
class Solution{
public:
    ListNode* last=NULL;
    ListNode* reverseNList(ListNode* head,int n){//翻转链表前n个元素
        if(!head||!head->next||n==1){
            last=head->next;
            return head;
        }
        ListNode* res=reverseNList(head->next,n-1);
        head->next->next=head;
        head->next=last;
        return res;
    }
    ListNode* reverseBetween(ListNode* head,int n,int m){//翻转链表n-m之间的元素
        if(n==1) return reverseNList(head,m);
        head->next=reverseBetween(head->next,n-1,m-1);
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {//k个一组翻转
        ListNode* prevHead=new ListNode(-1);
        prevHead->next=head;
        ListNode* front=prevHead;
        ListNode* back=head;
        while(back!=NULL){
            int i=0;
            while(i++<k&&back!=NULL){
                back=back->next;
            }
            if(i!=k+1) break;//back中途停了下来
            ListNode* temp=front->next;
            front->next=reverseNList(temp,k);
            front=temp;
        }
        return prevHead->next;
    }
};
int main(){
    vector<int> nums={1,2,3,4,5};
    ListNode* L=createList(nums);
    Solution ans;
    L=ans.reverseKGroup(L,3);
    ShowList(L);
    return 0;
}