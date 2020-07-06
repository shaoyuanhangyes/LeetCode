#include <iostream>
#include <vector>
#include <stack>

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//�Բ���ķ�ʽ���������� lenΪ���鳤�� indexΪԪ��λ�����
TreeNode* createTree(const vector<int> &nums,int len,int index){
    TreeNode *root=NULL;
    if(index<len&&nums[index]!=-1){//ֵΪnull��λ�ò��Ϸ�ʱֱ�ӷ��ؿսڵ�
        root = new TreeNode(nums[index]);
        root->left = createTree(nums,len,2*index+1);
        root->right= createTree(nums,len,2*index+2);
    }
    return root;
}
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node=root;
        long long key=LLONG_MIN;
        while(!st.empty()||node){
            while(node){
                st.push(node);
                node=node->left;
            }
            node=st.top();
            st.pop();
            if(node->val<=key) return false;
            key=node->val;
            node=node->right;
        }
        return true;
    }
};
int main(){
    vector<int> nums={2,1,3};
    TreeNode* root=createTree(nums,nums.size(),0);
    Solution answer;
    cout<<answer.isValidBST(root);
    return 0;
}


