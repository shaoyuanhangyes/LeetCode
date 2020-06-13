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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return head;
        ListNode *p=head;
        ListNode *r1=new ListNode(-1);
        ListNode *q=r1;
        ListNode *r2=new ListNode(-1);
        ListNode *c=r2;
        while(p){
            if(p->val<x){
                q->next=new ListNode(p->val);
                q=q->next;
                p=p->next;
            }
            else{
                c->next=new ListNode(p->val);
                c=c->next;
                p=p->next;
            }
        }
        q->next=r2->next;
        delete r2;
        return r1->next;
    }
};
int main(){
    vector<int> nums={1,4,3,2,5,2};
    ListNode *l1=createNodeList(nums);
    Solution answer;
    l1=answer.partition(l1,3);
    ShowList(l1);
    return 0;
}
