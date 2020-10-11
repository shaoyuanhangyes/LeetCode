#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
    TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right) {}
};

TreeNode* createTree(vector<int>& nums,int len,int index){
    TreeNode* root=NULL;
    if(index<len&&nums[index]!=-1){
        root=new TreeNode(nums[index]);
        root->left=createTree(nums,len,2*index+1);
        root->right=createTree(nums,len,2*index+2);
    }
    return root;
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* node=root;
        vector<int> res;
        stack<TreeNode*> st;
        while(!st.empty()||node){
            while(node){
                st.push(node);
                node=node->left;
            }
            node=st.top();st.pop();
            res.push_back(node->val);
            node=node->right;
        }
        return res[k-1];
    }
};


int main(){
    vector<int> nums={5,3,6,2,4,-1,-1,1};
    Solution ans;
    TreeNode* root=createTree(nums,nums.size(),0);
    cout<<ans.kthSmallest(root,3);
}