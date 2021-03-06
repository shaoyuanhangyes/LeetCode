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
ListNode* last=NULL;
ListNode* reverseN(ListNode* head,int n){
    if(head==NULL||head->next==NULL||n==1) {
        last=head->next;
        return head;
    }
    ListNode* res=reverseN(head->next,n-1);
    head->next->next=head;
    head->next=last;
    return res;
}
ListNode* reverseBetween(ListNode* head,int m,int n){
    if(m==1) return reverseN(head,n);
    head->next=reverseBetween(head->next,m-1,n-1);
    return head;
}

};
int main(){
    vector<int> m1={1,2,3,4,5,6,7,8};
    ListNode *l1=createNodeList(m1);
    Solution answer;
    ShowList(l1);
    ListNode *l2=answer.reverseBetween(l1,2,4);
    ShowList(l2);
    return 0;
}
