#include<iostream>
#include <vector>
#include <queue>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
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
vector<vector<int>> levelOrder(TreeNode* root) {//层序遍历
    vector<vector<int>> res;
    if(!root) return res;
    queue<TreeNode* > Tree;
    Tree.push(root);
    while(!Tree.empty()){
        vector<int> temp;
        int len=Tree.size();
        while(len--){
            TreeNode *pNode=Tree.front();
            Tree.pop();
            temp.push_back(pNode->val);
            if(pNode->left) Tree.push(pNode->left);
            if(pNode->right) Tree.push(pNode->right);
        }
        res.push_back(temp);
    }
    return res;
}
//打印二维数组
void PrintMartrix(vector<vector<int>>& res){
    for(int i=0;i<res.size();++i){
        cout<<"[";
        for(int j=0;j<res[i].size();++j){
            cout<<" "<<res[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
}


class Solution{
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;//链表为空返回NULL
        if(head->next==NULL) return new TreeNode(head->val);//链表只有一个元素返回根结点
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* back=NULL;
        while(fast&&fast->next){
            back=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode* root=new TreeNode(slow->val);
        back->next=NULL;//左半部分断链
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(slow->next);
        return root;
    }
};
int main(){
    vector<int> m1={-10,-3,0,5,9};
    ListNode *l1=createNodeList(m1);
    Solution answer;
    ShowList(l1);
    TreeNode *root=answer.sortedListToBST(l1);
    vector<vector<int>> res=levelOrder(root);
    PrintMartrix(res);
    return 0;
}

