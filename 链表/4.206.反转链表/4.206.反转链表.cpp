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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* res=reverseList(head->next);//以{1,2,3,4,5}为例
        head->next->next=head;//reverse递归传参 到5返回5结点 res指向5 回到4这一层 head指向4 head->next->next=head是4->next->next
        //是4->next->next=4即5->next=4
        head->next=NULL;//然后4->next=NULL断链 再将5-4返回给上一层连上3 在连上2 1 反转成功
        return res;
    }
};
int main(){
    vector<int> m1={1,2,3,4,5};
    ListNode *l1=createNodeList(m1);
    Solution answer;
    ListNode *l2=answer.reverseList(l1);//l2为l1元素翻转的链表
    ShowList(l2);
    return 0;
}
