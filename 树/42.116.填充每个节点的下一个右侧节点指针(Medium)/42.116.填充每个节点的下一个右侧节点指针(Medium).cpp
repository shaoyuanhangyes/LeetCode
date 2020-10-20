#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

Node* createTree(vector<int> &nums,int len,int index){
    Node* root=NULL;
    if(index<len&&nums[index]!=-1){
        root=new Node(nums[index]);
        root->left=createTree(nums,len,2*index+1);
        root->right=createTree(nums,len,2*index+2);
    }
    return root;
}
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if(root) que.push(root);
        while(!que.empty()){
            int len=que.size();
            Node* cur;
            Node* pre;
            for(int i=0;i<len;++i){
                if(i==0){
                    cur=que.front();que.pop();
                    pre=cur;
                }
                else{
                    cur=que.front();que.pop();
                    pre->next=cur;
                    pre=pre->next;
                }
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            pre->next=NULL;
        }
        return root;
    }
};

int main(){
    vector<int> nums={1,2,3,4,5,6,7};
    Solution ans;
    Node* root=createTree(nums,nums.size(),0);
    root=ans.connect(root);
}