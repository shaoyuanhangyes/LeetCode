#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode* createTree(vector<int>&nums,int len,int index){
    TreeNode* root=NULL;
    if(index<len&&nums[index]!=-1) {
        root=new TreeNode(nums[index]);
        root->left = createTree(nums, len, 2 * index + 1);
        root->right = createTree(nums, len, 2 * index + 2);
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
//层序遍历 利用队列进行迭代
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) return res;
    queue<TreeNode* > Tree;
    Tree.push(root);
    while(!Tree.empty()){
        vector<int> temp;
        int len=Tree.size();
        while(len--){
            TreeNode *pNode=Tree.front();
            Tree.pop();
            temp.push_back(pNode->val);
            if(pNode->left) Tree.push(pNode->left);
            if(pNode->right) Tree.push(pNode->right);
        }
        res.push_back(temp);
    }
    return res;
}
class Solution {
public:
//    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
//        if(!t1) return t2;
//        if(!t2) return t1;
//        t1->val+=t2->val;
//        t1->left=mergeTrees(t1->left,t2->left);
//        t1->right=mergeTrees(t1->right,t2->right);
//        return t1;
//    }
    TreeNode* mergeTrees(TreeNode* t1,TreeNode* t2){
        if(!t1) return t2;
        stack<pair<TreeNode*,TreeNode*>> st;
        if(t1&&t2) st.push({t1,t2});
        while(!st.empty()){
            pair<TreeNode*,TreeNode*> temp=st.top();
            st.pop();
            temp.first->val=temp.first->val+temp.second->val;
            if(temp.first->left||temp.second->left) {
                if(!temp.second->left) temp.second->left=new TreeNode(0);
                if(!temp.first->left)  temp.first->left=new TreeNode(0);
                st.push({temp.first->left, temp.second->left});
            }
            if(temp.first->right||temp.second->right) {
                if(!temp.second->right) temp.second->right=new TreeNode(0);
                if(!temp.first->right)  temp.first->right=new TreeNode(0);
                st.push({temp.first->right,temp.second->right});
            }
        }
        return t1;
    }
};

int main(){
    vector<int> nums1={1,3,2,5};
    vector<int> nums2={2,1,3,-1,4,-1,7};
    TreeNode* t1=createTree(nums1,nums1.size(),0);
    TreeNode* t2=createTree(nums2,nums2.size(),0);
    Solution answer;
    TreeNode* t3=answer.mergeTrees(t1,t2);
    vector<vector<int>> res=levelOrder(t3);
    PrintMartrix(res);
    return 0;
}