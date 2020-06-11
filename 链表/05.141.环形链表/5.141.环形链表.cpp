#include<iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head;//��ָ�� һ��ֻ�ƶ�һ��
        ListNode *fast=head;//��ָ�� һ���ƶ�����
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;//������ָ���ܹ����� ��˵�������л�
        }
        return false;//��ָ�뵽������β�� ˵�������޻�
    }
    
};
