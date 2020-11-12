#include <vector>
#include <iostream>

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res=NULL;
        while(root){
            if(p->val < root->val){
                res=root;
                root=root->left;
            }
            else{
                root=root->right;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums={2,1,3};
    TreeNode* root=createTree(nums,nums.size(),0);
    Solution ans;
}