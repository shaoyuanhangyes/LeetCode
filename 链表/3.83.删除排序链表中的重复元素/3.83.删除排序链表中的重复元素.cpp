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
        ListNode *p=head;
        while(p&&p->next){
            if(p->val==p->next->val){
                p->next=p->next->next;
            }
            else{
                p=p->next;
            }
        }
        return head;
    }
};
int main(){
    vector<int> nums={1,2,2,3,4,4};
    ListNode *l1=createNodeList(nums);
    Solution answer;
    ListNode *l2=answer.deleteDuplicates(l1);
    ShowList(l2);
    return 0;
}