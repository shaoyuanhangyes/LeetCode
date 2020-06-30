#include <iostream>// SortedArray to BST
#include <vector>
#include <queue>
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

    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {//递归算法
        if(root!=NULL){
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);
        }
        return res;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	if(nums.size()==0) return NULL;
		if(nums.size()==1) return new TreeNode(nums[0]);
		int mid=nums.size()/2;
		TreeNode* node=new TreeNode(nums[mid]);
		vector<int>::const_iterator first;
		vector<int>::const_iterator last;
		first=nums.begin();
		last=nums.begin()+mid;
		vector<int> v_temp(first,last);
		node->left=sortedArrayToBST(v_temp);
		if(mid==nums.size()-1) node->right=NULL;
		else{
		    first=nums.begin()+mid+1;
		    last=nums.end();
		    vector<int> v_temp(first,last);
		    node->right=sortedArrayToBST(v_temp);
		}
		return node;
    }
};
int main(){
    vector<int> nums={0,1,2,3,4,5};//示例 值为-1代表所在位置为空值
    int len=nums.size();
    Solution answer;
    TreeNode *root=answer.sortedArrayToBST(nums);
    vector<vector<int>> res=answer.levelOrder(root);
    PrintMartrix(res);//打印层序遍历的二维数组
    vector<int> print=answer.inorderTraversal(root);
    for(auto x:print) cout<<x<<" ";//打印中序遍历的序列
    return 0;
}
