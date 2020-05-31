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
    bool isSymmetric(TreeNode* root) {
        return (!root)?true:dfs(root->left,root->right);
    }
    bool dfs(TreeNode *p,TreeNode *q){
        if(!p||!q) return !p&&!q;// pq��Ϊ�� ����true pq��һ��Ϊ����һ����Ϊ�� ����false
        return (p->val!=q->val)?false:dfs(p->left,q->right)&&dfs(p->right,q->left);
    }
};
int main(){
    vector<int> nums1={1,2,2,3,4,4,3};//ʾ�� -1��������λ��Ϊ��ֵ
    int len1=nums1.size();
    TreeNode *root=levelCreateBinaryTree(nums1,len1,0);
    Solution answer;
    levelOrder(root);
    bool res=answer.isSymmetric(root);
    cout<<res<<endl;
    return 0;
}
