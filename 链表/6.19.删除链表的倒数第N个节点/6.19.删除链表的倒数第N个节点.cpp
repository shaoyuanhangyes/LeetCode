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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first=head;
        ListNode *second=head;
        while(n--){
            first=first->next;
        }
        if(first!=NULL){
            while(first->next){
                first=first->next;
                second=second->next;
            }
            second->next=second->next->next;
            return head;
        }
        else return head->next;
    }
};
int main(){
    vector<int> nums={6,5,4,3,2,1};
    ListNode *l1=createNodeList(nums);
    Solution answer;
    ShowList(answer.removeNthFromEnd(l1,6));
    return 0;
}
