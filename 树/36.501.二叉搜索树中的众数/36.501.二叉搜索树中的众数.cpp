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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        TreeNode* cur=root;
        TreeNode* mostright=NULL;
        TreeNode* pre=NULL;
        int count=0,maxCount=0;
        while(cur!=NULL){
            mostright=cur->left;
            if(mostright!=NULL){
                while(mostright->right!=NULL&&mostright->right!=cur) mostright=mostright->right;
                if(mostright->right==NULL){
                    mostright->right=cur;
                    cur=cur->left;
                    continue;
                }
                else{
                    if(pre&&pre->val==cur->val) count++;
                    else count=1;
                    if(count>maxCount){
                        maxCount=count;
                        res.clear();
                        res.push_back(cur->val);
                    }
                    else if(count==maxCount) res.push_back(cur->val);
                    mostright->right=NULL;
                }
            }
            else{//左子树为空
                if(pre&&pre->val==cur->val) count++;
                else count=1;
                if(count>maxCount){
                    maxCount=count;
                    res.clear();
                    res.push_back(cur->val);
                }
                else if(count==maxCount) res.push_back(cur->val);
            }
            pre=cur;
            cur=cur->right;
        }
        return res;
    }
};

int main(){
    vector<int> nums={1,-1,2,-1,-1,2};
    Solution ans;
    TreeNode* root=createTree(nums,nums.size(),0);
    nums=ans.findMode(root);
    for(auto x:nums) cout<<x<<" ";
}