#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode* createTree(vector<int>& nums,int len,int index){
    TreeNode* root=NULL;
    if(index<len&&nums[index]!=INT_MIN){
        root=new TreeNode(nums[index]);
        root->left= createTree(nums,len,2*index+1);
        root->right=createTree(nums,len,2*index+2);
    }
    return root;
}
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string res;
        queue<TreeNode*> st;
        TreeNode* node=root;
        res=res+to_string(root->val)+",";
        st.push(root);
        while(!st.empty()){
            TreeNode* node=st.front();
            st.pop();
            if(node->left){
                st.push(node->left);
                res=res+to_string(node->left->val)+",";
            }
            else res.append("null,");
            if(node->right){
                st.push(node->right);
                res=res+to_string(node->right->val)+",";
            }
            else res.append("null,");
        }
        res.pop_back();//删除最后一个多余的,
        return res;
    }

//     Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        data.append(",");
        vector<string> convertdata;
        int len=0;
        for(int i=0;i<data.size();++i){
            if(data[i]==','){
                convertdata.push_back(data.substr(i-len,len));
                len=0;
            }
            else len++;
        }
        TreeNode* root=new TreeNode(stoi(convertdata[0]));
        TreeNode* node=root;
        queue<TreeNode*> st;
        st.push(node);
        int index=0;
        while(!st.empty()){
            node=st.front();
            st.pop();
            if(++index>=convertdata.size()) break;
            if(convertdata[index]!="null"){
                node->left=new TreeNode(stoi(convertdata[index]));
                st.push(node->left);
            }
            if(++index>=convertdata.size()) break;
            if(convertdata[index]!="null"){
                node->right=new TreeNode(stoi(convertdata[index]));
                st.push(node->right);
            }
        }
        return root;
    }
};

int main(){
    Codec codec;
    vector<int> nums={1,2,3,INT_MIN,INT_MIN,4,5};
    TreeNode* root=createTree(nums,nums.size(),0);
    codec.deserialize(codec.serialize(root));
    return 0;
}