#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
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

TreeNode* modifyTree(TreeNode* root){
    TreeNode* p=root;
    p=p->left->left;
    p->right=root->right->right;
    return root;
}

void levelOrder(TreeNode* root){
    queue<TreeNode*> st;
    st.push(root);
    TreeNode* temp=NULL;
    while(!st.empty()){
        temp=st.front();st.pop();
        cout<<temp->val<<" ";
        if(temp->left) st.push(temp->left);
        if(temp->right) st.push(temp->right);
    }
}

class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        if(!root) return NULL;
        queue<pair<TreeNode*,TreeNode*>> st;
        st.push({root,NULL});
        TreeNode* node=NULL;TreeNode* parent=NULL;
        while(!st.empty()){
            int len=st.size();
            unordered_map<TreeNode*,TreeNode*> m;
            while(len--){
                node=st.front().first;parent=st.front().second;
                st.pop();
                m[node]=parent;
                if(node->left) st.push({node->left, node});
                if(node->right) st.push({node->right, node});
            }
            for(auto x:m){
                node=x.first;
                if(m.count(node->right)){
                    parent=x.second;
                    if(parent->left==node) parent->left=NULL;
                    else parent->right=NULL;
                    return root;
                }
            }
        }
        return root;
    }
};


int main(){
    vector<int> nums={8,3,1,7,-1,9,4,2,-1,-1,-1,-1,-1,5,6};
    TreeNode* root=createTree(nums,nums.size(),0);
    root=modifyTree(root);// 7->4
    Solution ans;
    root=ans.correctBinaryTree(root);
    levelOrder(root);
}