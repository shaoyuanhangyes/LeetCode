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
class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *prev=new ListNode(-1);
        prev->next=head;
        ListNode *a=prev;
        ListNode *b=prev->next;
        while(b&&b->next){
            if(a->next->val!=b->next->val){
                b=b->next;
                a=a->next;
            }
            else{
               while(b&&b->next&&a->next->val==b->next->val){
                   b=b->next;
               }
               b=b->next;
               a->next=b;
            }
        }
        return prev->next;
    }
};
int main(){
    vector<int> nums={1,1,1,2,2,3,4,5,5,6};
    ListNode *l1=createNodeList(nums);
    Solution answer;
    l1=answer.deleteDuplicates(l1);
    ShowList(l1);
    return 0;
}
