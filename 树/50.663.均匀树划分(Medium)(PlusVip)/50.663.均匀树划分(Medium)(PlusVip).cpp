#include <iostream>
#include <vector>
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
    if(index<len&&nums[index]!=-10){
        root=new TreeNode(nums[index]);
        root->left=createTree(nums,len,2*index+1);
        root->right=createTree(nums,len,2*index+2);
    }
    return root;
}

class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        int sumVal= dfs_sum(root);
        if((sumVal&1)==0){
            for(auto x:m){
                TreeNode* node=x.first;
                int val=x.second;
                if((x.second==sumVal/2)&&(node!=root)) return true;
            }
        }
        return false;
    }
    int dfs_sum(TreeNode* root){
        if(!root) return 0;
        int nodeVal= root->val + dfs_sum(root->left) + dfs_sum(root->right);
        m[root]=nodeVal;
        return nodeVal;
    }
private:
    unordered_map<TreeNode*,int> m;
};

int main(){
    vector<int> nums={0,-10,0};
    TreeNode* root=createTree(nums,nums.size(),0);
    Solution ans;
    cout<<ans.checkEqualTree(root);
}