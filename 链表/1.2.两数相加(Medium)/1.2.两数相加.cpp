#include<iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
ListNode* createNodeList(const vector<int> & vec){//头插法
    ListNode* prevHead = new ListNode(vec[0]);//prev始终指向表尾指针
    for (int i = 1; i < vec.size(); i ++) {
        ListNode* next_node = new ListNode(vec[i]);
        next_node -> next = prevHead;//新来的结点插在上一个元素的前面
        prevHead = next_node;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=1;//链表l1的长度
        int len2=1;//链表l2的长度
        ListNode *p=l1;
        ListNode *q=l2;
        while(p->next!=NULL){//这里踩过坑 不能让循环条件变为p 若这样做p会指向不存在的p->next 如果两个链表长度不一致 没办法给短的链表后面加0 
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
        p=l1;q=l2;//回到原来位置

        ListNode *res = new ListNode(-1);
        ListNode *t=res;
        int sum=0;
        int carry=0;
        while(p&&q){
            sum=(p->val+q->val+carry)%10;//sum是这一位的最终结果 
            carry=(p->val+q->val+carry)/10;//进位 
            t->next = new ListNode(sum);
            t=t->next;
            p=p->next;
            q=q->next;
        }
        if(carry){//如果加到最后发现还有进位 
            t->next = new ListNode(1);//新增一个结点 数值必然是1 
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
    ListNode *l3=answer.addTwoNumbers(l1,l2);//l3为元素相加后的链表 
    ShowList(l3);//输出结果也是逆序 
    return 0;
}
