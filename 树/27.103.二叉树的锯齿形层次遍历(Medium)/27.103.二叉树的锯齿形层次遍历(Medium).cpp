#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
void PrintMartrix(vector<vector<int>>& res){
    for(int i=0;i<res.size();++i){
        cout<<"[";
        for(int j=0;j<res[i].size();++j){
            cout<<" "<<res[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
}

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> st;
        st.push(root);
        int sign=0;
        while(!st.empty()){
            sign++;
            vector<int> temp;
            int len=st.size();
            while(len--){
                root=st.front();st.pop();
                temp.push_back(root->val);
                if(root->left) st.push(root->left);
                if(root->right) st.push(root->right);
            }
            if(sign%2==0) reverse(temp.begin(),temp.end());
            res.push_back(temp);
        }
        return res;
    }
};

int main(){
    vector<int> nums={3,9,20,-1,-1,15,7};
    TreeNode* root=createTree(nums,nums.size(),0);
    Solution ans;
    vector<vector<int>> res=ans.zigzagLevelOrder(root);
    PrintMartrix(res);
    return 0;
}