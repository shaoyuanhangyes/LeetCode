#include<iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode* createNodeList(const vector<int> & vec){//ͷ�巨
    ListNode* prevHead = new ListNode(vec[0]);//prevʼ��ָ���βָ��
    for (int i = 1; i < vec.size(); i ++) {
        ListNode* next_node = new ListNode(vec[i]);
        next_node -> next = prevHead;//�����Ľ�������һ��Ԫ�ص�ǰ��
        prevHead = next_node;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=1;//����l1�ĳ���
        int len2=1;//����l2�ĳ���
        ListNode *p=l1;
        ListNode *q=l2;
        while(p->next!=NULL){//����ȹ��� ������ѭ��������Ϊp ��������p��ָ�򲻴��ڵ�p->next ������������Ȳ�һ�� û�취���̵���������0 
            len1++;
            p=p->next;
        }
        while(q->next!=NULL){
            len2++;
            q=q->next;
        }
        if(len1<len2){
            for(int i=0;i<len2-len1;i++){
                p->next = new ListNode(0);
                p=p->next;
            }
        }
        else{
            for(int i=0;i<len1-len2;i++){
                q->next = new ListNode(0);
                q=q->next;
            }
        }
        p=l1;q=l2;//�ص�ԭ��λ��

        ListNode *res = new ListNode(-1);
        ListNode *t=res;
        int sum=0;
        int carry=0;
        while(p&&q){
            sum=(p->val+q->val+carry)%10;//sum����һλ�����ս�� 
            carry=(p->val+q->val+carry)/10;//��λ 
            t->next = new ListNode(sum);
            t=t->next;
            p=p->next;
            q=q->next;
        }
        if(carry){//����ӵ�����ֻ��н�λ 
            t->next = new ListNode(1);//����һ����� ��ֵ��Ȼ��1 
        }
        return res->next;
    }
};
int main(){
    vector<int> m1={9,9};
    vector<int> m2={1};
    ListNode *l1=createNodeList(m1);
    ListNode *l2=createNodeList(m2);
    Solution answer;
    ListNode *l3=answer.addTwoNumbers(l1,l2);//l3ΪԪ����Ӻ������ 
    ShowList(l3);//������Ҳ������ 
    return 0;
}
