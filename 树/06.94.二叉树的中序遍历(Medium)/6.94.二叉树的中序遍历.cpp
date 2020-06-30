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
vector<int> res;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root!=NULL){
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);
        }
        return res;
    }
};
int main(){
    vector<int> nums={0,1,2,3,4,5,6,7,8};//示例 -1代表所在位置为空值
    int len=nums.size();
    TreeNode *root=levelCreateBinaryTree(nums,len,0);
    Solution answer;
    res=answer.inorderTraversal(root);
    for(auto x:res) cout<<x<<" ";
    return 0;
}
