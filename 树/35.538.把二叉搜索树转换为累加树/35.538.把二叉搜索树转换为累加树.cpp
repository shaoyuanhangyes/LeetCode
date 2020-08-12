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
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
        if(root!=NULL){
            convertBST(root->right);
            root->val+=sum;
            sum=root->val;
            convertBST(root->left);
        }
        return root;
    }
};

int main(){
    vector<int> nums={5,2,13};
    TreeNode* root=createTree(nums,nums.size(),0);
    Solution ans;
    root=ans.convertBST(root);
}