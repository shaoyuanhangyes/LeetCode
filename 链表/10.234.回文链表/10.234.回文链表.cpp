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
    bool isPalindrome(ListNode* head) {
        ListNode *p=head;
        stack<int> st;
        while(p){
            st.push(p->val);
            p=p->next;
        }
        p=head;
        while(p){
            if(p->val==st.top()){
                p=p->next;
                st.pop();
            }
            else{
                return false;
            }
        }
        return true;
    }
};
int main(){
    vector<int> nums={6,5,5,6};
    ListNode *l1=createNodeList(nums);
    Solution answer;
    ShowList(l1);
    bool res=answer.isPalindrome(l1);
    cout<<res;
    return 0;
}
