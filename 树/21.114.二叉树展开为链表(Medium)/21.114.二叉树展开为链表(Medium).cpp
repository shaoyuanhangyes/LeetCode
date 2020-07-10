#include <iostream>
#include <vector>

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

class Solution {
public:
    void flatten(TreeNode* root) {
        while(root){
            if(root->left==NULL) root=root->right;
            else{
                TreeNode* node=root->left;
                while(node->right!=NULL) {
                    node=node->right;
                }
                node->right=root->right;
                root->right=root->left;
                root->left=NULL;
                root=root->right;
            }
        }
    }
};

void ShowElement(TreeNode* root){
    while(root){
        cout<<root->val<<" ";
        root=root->right;
    }
}
int main(){
    vector<int> nums={1,2,5,3,4,-1,6};
    TreeNode* root=createTree(nums,nums.size(),0);
    Solution answer;
    answer.flatten(root);
    ShowElement(root);
    return 0;
}
