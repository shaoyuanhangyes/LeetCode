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
    void reorderList(ListNode *head){
        if(head==NULL||head->next==NULL) return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* rL=reverse(slow->next);
        slow->next=NULL;
        while(rL){
            ListNode* temp=rL->next;
            rL->next=head->next;
            head->next=rL;
            head=rL->next;
            rL=temp;
        }
    }
    ListNode* reverse(ListNode* head){
        if(head==NULL||head->next==NULL) return head;
        ListNode* res=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return res;
    }

};
int main(){
    vector<int> m1={1,2,3,4,5,6,7};
    ListNode *l1=createNodeList(m1);
    Solution answer;
    answer.reorderList(l1);
    ShowList(l1);
    return 0;
}
