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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        diameter=1;
        maxDepth(root);
        return diameter-1;
    }
    int maxDepth(TreeNode* root){
        if(root==NULL) return 0;
        int l_left=maxDepth(root->left);
        int l_right=maxDepth(root->right);
        diameter=max(diameter,l_left+l_right+1);
        return max(l_left,l_right)+1;
    }
private:
    int diameter;
};

int main(){
    vector<int> nums={1,2,3,4,5};
    TreeNode* root=createTree(nums,nums.size(),0);
    Solution ans;
    cout<<ans.diameterOfBinaryTree(root);
}
