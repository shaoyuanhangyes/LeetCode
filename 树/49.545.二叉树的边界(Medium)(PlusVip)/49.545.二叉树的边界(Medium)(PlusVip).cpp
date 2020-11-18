#include <iostream>
#include <vector>

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

class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        res.push_back(root->val);
        dfs(root->left,-1,res);
        dfs(root->right,1,res);
        return res;
    }
    void dfs(TreeNode* root,int direction,vector<int>& res){
        if(root==NULL) return;
        if(direction==0){//寻找叶子结点
            if(root->left==NULL&&root->right==NULL) res.push_back(root->val);
            else{
                dfs(root->left,0,res);
                dfs(root->right,0,res);
            }
            return;
        }
        if(direction==-1){//向左先序遍历
            res.push_back(root->val);
            if(root->left){
                dfs(root->left,direction,res);
                dfs(root->right,0,res);
            }
            else dfs(root->right,direction,res);
        }
        if(direction==1){//向右后序遍历
            if(root->right){
                dfs(root->left,0,res);
                dfs(root->right,direction,res);
            }
            else dfs(root->left,direction,res);
            res.push_back(root->val);
        }
    }
};

int main(){
    vector<int> nums={1,2,3,4,5,6,-1,-1,-1,7,8,9,10};
    TreeNode* root=createTree(nums,nums.size(),0);
    Solution ans;
    vector<int> res=ans.boundaryOfBinaryTree(root);
    for(auto x:res) cout<<x<<" ";
}