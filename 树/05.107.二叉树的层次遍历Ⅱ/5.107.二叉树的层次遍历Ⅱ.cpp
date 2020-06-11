#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
};
TreeNode* levelCreateBinaryTree(const vector<int> &nums,int len,int index){//层序创建二叉树index为位置序号
    TreeNode *root=NULL;
    if(index<len&&nums[index]!=-1){
        root = new TreeNode(nums[index]);
        root->left = levelCreateBinaryTree(nums,len,2*index+1);
        root->right= levelCreateBinaryTree(nums,len,2*index+2);
    }
    return root;
}
void PrintMartrix(vector<vector<int>>& res){//打印二维数组
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        stack<vector<int>> st;
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
            st.push(temp);
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
int main(){
    vector<int> nums={0,1,2,3,4,5,6,7,8};//示例 -1代表所在位置为空值
    int len=nums.size();
    TreeNode *root=levelCreateBinaryTree(nums,len,0);
    Solution answer;
    vector<vector<int>> res=answer.levelOrderBottom(root);
    PrintMartrix(res);
    return 0;
}
