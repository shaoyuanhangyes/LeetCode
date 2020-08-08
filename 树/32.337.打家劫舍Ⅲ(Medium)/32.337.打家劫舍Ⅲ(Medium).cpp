#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
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
    unordered_map<TreeNode*,int> f,g;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        dfs(root->right);
        f[root]=root->val+g[root->left]+g[root->right];
        g[root]=max(f[root->left],g[root->left])+max(f[root->right],g[root->right]);
    }
    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root],g[root]);
    }
};

int main(){
    vector<int> nums={3,4,5,1,3,-1,1};
    TreeNode* root=createTree(nums,nums.size(),0);
    Solution ans;
    cout<<ans.rob(root);
}