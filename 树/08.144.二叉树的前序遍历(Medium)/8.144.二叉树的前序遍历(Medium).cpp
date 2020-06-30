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
	vector<int> nums={0,1,2,3,4,5,6,7,8,-1,10};//示例 -1代表所在位置为空值
    int len=nums.size();
    TreeNode *root=createTree(nums,len,0);
    cout<<"先序遍历序列为"<<endl;
    Solution answer;
    vector<int> preOrderVector=answer.preorderTraversal(root);
    for(auto x:preOrderVector) cout<<x<<" ";
    return 0;
}
