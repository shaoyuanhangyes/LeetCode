#include <iostream>
#include <vector>
#include <stack>

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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        stack<pair<TreeNode*,string>> st;
        string sum;
        int res=0;
        while(!st.empty()||root){
            while(root){
                sum+=to_string(root->val);
                st.push({root,sum});
                root=root->left;
            }
            pair<TreeNode*,string> temp=st.top();
            st.pop();
            root=temp.first;
            sum=temp.second;
            if(!root->left&&!root->right) res+=stoi(sum);
            root=root->right;
        }
        return res;
    }
};

int main(){
    vector<int> nums={3,4,5};
    TreeNode* root=createTree(nums,nums.size(),0);
    Solution answer;
    int sum=answer.sumNumbers(root);
    cout<<sum;
    return 0;
}
