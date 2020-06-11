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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode *p=head;
        int len=1;//记录链表长度
        while(p->next){
            len++;
            p=p->next;
        }
        p->next=head;
        int remain=k%len;//记录余数
        if(remain==0){
            p->next=NULL;
            return head;
        }
        ListNode *q=head;
        for(int i=0;i<len-remain;i++){//移动节点的次数为 表长-余数
            q=q->next;
            p=p->next;
        }
        p->next=NULL;
        return q;
    }
};
int main(){
    vector<int> nums={0,1,2};
    ListNode *l1=createNodeList(nums);
    Solution answer;
    l1=answer.rotateRight(l1,4);
    ShowList(l1);
    return 0;
}
