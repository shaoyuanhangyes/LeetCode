#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
};
//以层序的方式创建二叉树 len为数组长度 index为元素位置序号
TreeNode* createTree(const vector<int> &nums,int len,int index){
    TreeNode *root=NULL;
    if(index<len&&nums[index]!=-1){//值为null和位置不合法时直接返回空节点
        root = new TreeNode(nums[index]);
        root->left = createTree(nums,len,2*index+1);
        root->right= createTree(nums,len,2*index+2);
    }
    return root;
}
//打印二维数组
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
//    TreeNode* insertIntoBST(TreeNode* root, int val) {//递归解法
//        if(root==NULL) return new TreeNode(val);
//        if(val<root->val) root->left=insertIntoBST(root->left,val);
//        if(val>root->val) root->right=insertIntoBST(root->right,val);
//        return root;
//    }
    TreeNode* insertIntoBST(TreeNode* root,int val){
        TreeNode* node=root;
        while(node!=NULL){
            if(val>node->val){
                if(node->right==NULL){
                    node->right=new TreeNode(val);
                    return root;
                }
                else node=node->right;
            }
            else{
                if(node->left==NULL){
                    node->left=new TreeNode(val);
                    return root;
                }
                else node=node->left;
            }
        }
        return new TreeNode(val);
    }
};

int main(){
    vector<int> nums={4,2,7,1,3};
    TreeNode* root=createTree(nums,nums.size(),0);
    Solution answer;
    root=answer.insertIntoBST(root,5);
    vector<vector<int>> res=levelOrder(root);
    PrintMartrix(res);
    return 0;
}