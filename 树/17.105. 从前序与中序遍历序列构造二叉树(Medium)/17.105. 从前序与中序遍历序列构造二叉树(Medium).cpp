#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;
        TreeNode* root=new TreeNode(preorder[0]);
        vector<int> preorder_left, inorder_left, preorder_right, inorder_right;
        int i;
        for(i=0;i<inorder.size();++i){
            if(inorder[i]==root->val) break;
            inorder_left.push_back(inorder[i]);
        }//中序遍历根结点的左子树存入inorder_left
        for(++i;i<inorder.size();++i){
            inorder_right.push_back(inorder[i]);
        }//中序遍历根结点的右子树存入inorder_right
        for(int j=1;j<preorder.size();++j){
            //根据中序遍历左子树的长度来确定前序遍历左子树存入preorder_left
            if(j<=inorder_left.size()) preorder_left.push_back(preorder[j]);
                //前序遍历剩下的为右子树 存入前序遍历右子树序列preorder_right
            else preorder_right.push_back(preorder[j]);
        }
        root->left=buildTree(preorder_left,inorder_left);
        root->right=buildTree(preorder_right,inorder_right);
        return root;
   }
};

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

int main(){
    vector<int> preorder={3,9,20,15,7};
    vector<int> inorder={9,3,15,20,7};
    Solution answer;
    TreeNode* root=answer.buildTree(preorder,inorder);
    vector<vector<int>> res=levelOrder(root);
    PrintMartrix(res);
    return 0;
}