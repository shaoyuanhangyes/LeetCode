#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>//sort()
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
};
TreeNode* levelCreateBinaryTree(const vector<int> &nums,int len,int index){//���򴴽�������indexΪλ�����
    TreeNode *root=NULL;
    if(index<len&&nums[index]!=-1){
        root = new TreeNode(nums[index]);
        root->left = levelCreateBinaryTree(nums,len,2*index+1);
        root->right= levelCreateBinaryTree(nums,len,2*index+2);
    }
    return root;
}
void levelOrder(TreeNode *root){//������� ����������ʵ��
    queue<TreeNode* > Tree;
    Tree.push(root);
    while(!Tree.empty()){
        TreeNode *pNode = Tree.front();
        Tree.pop();
        cout<<pNode->val<<" ";
        if(pNode->left!=NULL) Tree.push(pNode->left);
        if(pNode->right!=NULL) Tree.push(pNode->right);
    }
    cout<<endl;
}
class Solution {
public:
    int maxDepth(TreeNode* root) {//�ݹ���������㷨
        if(root==NULL) return 0;
        int l_len=maxDepth(root->left)+1;
        int r_len=maxDepth(root->right)+1;
        return l_len>r_len?l_len:r_len;
    }
};
int main(){
    vector<int> nums={0,1,2,3,4,5,6,7,8};//ʾ�� -1��������λ��Ϊ��ֵ
    int len=nums.size();
    TreeNode *root=levelCreateBinaryTree(nums,len,0);
    Solution answer;
    levelOrder(root);
    cout<<answer.maxDepth(root)<<endl;
    return 0;
}
