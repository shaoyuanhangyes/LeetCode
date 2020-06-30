#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
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
class Solution{
public:
	vector<int> preorderTraversal(TreeNode* root) {
	    vector<int> res;
	    stack<TreeNode* > st;
	    TreeNode* node=root;
	    while(!st.empty()||node){
	        while(node){
	            st.push(node);
	            res.push_back(node->val);
	            node=node->left;
	        }
	        node=st.top();
	        st.pop();
	        node=node->right;
	    }
	    return res;
	}
}; 

int main(){
	vector<int> nums={0,1,2,3,4,5,6,7,8,-1,10};//ʾ�� -1��������λ��Ϊ��ֵ
    int len=nums.size();
    TreeNode *root=createTree(nums,len,0);
    cout<<"�����������Ϊ"<<endl;
    Solution answer;
    vector<int> preOrderVector=answer.preorderTraversal(root);
    for(auto x:preOrderVector) cout<<x<<" ";
    return 0;
}
