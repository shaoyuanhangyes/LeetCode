#include<iostream>
#include <vector>
#include <stack>
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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1,s2;
        while(l1){
            s1.push(l1);
            l1=l1->next;
        }
        while(l2){
            s2.push(l2);
            l2=l2->next;
        }
        int sum=0;
        int carry=0;
        ListNode* res=new ListNode(-1);
        ListNode* temp=NULL;
        while(!s1.empty()||!s2.empty()||carry!=0){
            if(s1.empty()) l1=new ListNode(0);
            else {
                l1=s1.top();s1.pop();
            }
            if(s2.empty()) l2=new ListNode(0);
            else{
                l2=s2.top();s2.pop();
            }
            sum=(l1->val+l2->val+carry)%10;
            carry=(l1->val+l2->val+carry)/10;
            temp=new ListNode(sum);
            temp->next=res->next;
            res->next=temp;
        }
        return res->next;
    }
};

int main(){
    vector<int> nums1={7,2,4,3};
    vector<int> nums2={5,6,4,1};
    ListNode* l1=createNodeList(nums1);
    ListNode* l2=createNodeList(nums2);
    Solution answer;
    ListNode* l3=answer.addTwoNumbers(l1,l2);
    ShowList(l3);
    return 0;
}