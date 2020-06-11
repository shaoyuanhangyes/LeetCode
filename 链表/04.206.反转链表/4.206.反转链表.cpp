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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* res=reverseList(head->next);//��{1,2,3,4,5}Ϊ��
        head->next->next=head;//reverse�ݹ鴫�� ��5����5��� resָ��5 �ص�4��һ�� headָ��4 head->next->next=head��4->next->next
        //��4->next->next=4��5->next=4
        head->next=NULL;//Ȼ��4->next=NULL���� �ٽ�5-4���ظ���һ������3 ������2 1 ��ת�ɹ�
        return res;
    }
};
int main(){
    vector<int> m1={1,2,3,4,5};
    ListNode *l1=createNodeList(m1);
    Solution answer;
    ListNode *l2=answer.reverseList(l1);//l2Ϊl1Ԫ�ط�ת������
    ShowList(l2);
    return 0;
}
