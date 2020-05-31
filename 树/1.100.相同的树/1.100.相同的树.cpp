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
    bool isSameTree(TreeNode* p,TreeNode* q){//�ݹ�
        if(!p&&!q) return true;//��������Ϊ��Ҳ����ͬ���� 
        if(!p||!q) return false;//��һ������Ϊ����һ��Ϊ����һ��������ͬ����
        return (p->val==q->val)&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        //�ݹ�Աȸ�������valֵ�Ƿ���ͬ �����ͬ ����&&��������Ķ�·���� ����һ�����������ֵΪfalse��ֱ�ӷ���false ����ǰ�����ݹ�ֱ�ӷ��ؽ�� ������ɶ�����˷�
    }
};
int main(){
    vector<int> nums1={1,2,3,4,5,-1,7};//ʾ�� ������Ԫ��Ϊ-1��������λ���ڶ�������Ϊnull
    int len1=nums1.size();
    TreeNode *root1=levelCreateBinaryTree(nums1,len1,0);//index����Ϊ0��������Ϊ��������ڵ��������Ϊ0
    vector<int> nums2={1,2,3,4,-1,-1,7};
    int len2=nums2.size();
    TreeNode *root2=levelCreateBinaryTree(nums2,len2,0);
    Solution answer;
    levelOrder(root1);//������������������� ֻ��Ϊ�˷���۲�
    levelOrder(root2);
    bool res=answer.isSameTree(root1,root2);//��root1/root2�������������жԱ��ж�
    cout<<res<<endl;
    return 0;
}
