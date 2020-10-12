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
        root->left=createTree(nums,len,2*len+1);
        root->right=createTree(nums,len,2*index+2);
    }
    return root;
}
class Solution{
public:
    int function(TreeNode* root){

    }
    int dfs(TreeNode* root){
        if(!root) return 0;

    }
};
int main(){
    vector<int> nums={1,-1,3,-1,-1,2};
    TreeNode* root=createTree(nums,nums.size(),0);
    Solution ans;
    cout<<ans.function(root);
}