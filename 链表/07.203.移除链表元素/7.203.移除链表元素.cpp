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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *s=new ListNode(-1);
        s->next=head;
        ListNode *q=s;
        while(q->next){
            if(q->next->val==val){
                q->next=q->next->next;
            }
            else{
                q=q->next;
            }
        }
        return s->next;
    }
};
int main(){
    vector<int> nums={3,1,3,1};
    ListNode *l1=createNodeList(nums);
    Solution answer;
    ShowList(answer.removeElements(l1,1));
    return 0;
}
