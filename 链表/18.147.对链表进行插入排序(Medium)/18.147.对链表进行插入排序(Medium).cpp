#include<iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode* createNodeList(const vector<int> & vec){//��巨��������
    ListNode* prev = new ListNode(vec[0]);//prevʼ��ָ���βָ��
    ListNode* prevHead = prev;
    for (int i = 1; i < vec.size(); i ++) {
        ListNode* next_node = new ListNode(vec[i]);
        prev -> next = next_node;
        prev = next_node;
    }
    return prevHead;//prevHeadʼ��ָ���һ��Ԫ��
}
void ShowList(ListNode *l){//�����������
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
        ListNode* now=head->next;//nowΪ�����жϱȽϴ�С�Ļ�Ԫ��
        ListNode* last=head;//lastΪnowǰһ����� ��������
        ListNode* t=prevHead;//tΪheadǰһ����� ��������
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
            //��λ
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
