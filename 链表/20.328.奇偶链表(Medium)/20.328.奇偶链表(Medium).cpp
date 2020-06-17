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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenHead=new ListNode(-1);
        ListNode* temp=evenHead;
        while(even&&even->next){
            odd->next=even->next;
            temp->next=even;
            temp=temp->next;
            temp->next=NULL;
            odd=odd->next;
            even=odd->next;
        }
        if(even!=NULL&&even->next==NULL) temp->next=even;
        odd->next=evenHead->next;
        return head;
    }

};
int main(){
    vector<int> m1={1,2,3,4,5};
    ListNode *l1=createNodeList(m1);
    Solution answer;
    l1=answer.oddEvenList(l1);
    ShowList(l1);
    return 0;
}
