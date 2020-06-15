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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* prevHead=new ListNode(-1);
        prevHead->next=head;
        ListNode* now=head->next;//now为进行判断比较大小的基元素
        ListNode* last=head;//last为now前一个结点 用于连接
        ListNode* t=prevHead;//t为head前一个结点 用于连接
        while(now){
            while(head!=now){
                if(now->val>head->val){
                    t=head;
                    head=head->next;
                }
                else{
                    last->next=now->next;
                    now->next=head;
                    t->next=now;
                    now=last;
                    break;
                }
            }
            last=now;
            now=now->next;
            //归位
            t=prevHead;
            head=t->next;
        }
        return prevHead->next;
    }

};
int main(){
    vector<int> m1={6,7,1,4,2};
    ListNode *l1=createNodeList(m1);
    Solution answer;
    l1=answer.insertionSortList(l1);
    ShowList(l1);
    return 0;
}
