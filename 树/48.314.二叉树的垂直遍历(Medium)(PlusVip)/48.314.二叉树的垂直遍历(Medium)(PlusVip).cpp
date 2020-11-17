#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode* createTree(vector<int>& nums,int len,int index){
    TreeNode* root=NULL;
    if(index<len&&nums[index]!=-1){
        root=new TreeNode(nums[index]);
        root->left=createTree(nums,len,2*index+1);
        root->right=createTree(nums,len,2*index+2);
    }
    return root;
}

void PrintMartrix(vector<vector<int>>& res){
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        visited.push({root,cur_coordinate});
        while(!visited.empty()){
            cur=visited.front().first;
            cur_coordinate=visited.front().second;
            visited.pop();
            m[cur_coordinate].push_back(cur->val);
            if(cur->left){
                visited.push({cur->left,cur_coordinate-1});
            }
            if(cur->right){
                visited.push({cur->right,cur_coordinate+1});
            }
        }
        for(auto x=m.begin();x!=m.end();++x){
            res.push_back(x->second);
        }
        return res;
    }

private:
    map<int,vector<int>> m;
    queue<pair<TreeNode*,int>> visited;
    int cur_coordinate=0;
    TreeNode* cur=NULL;
};

int main(){
    vector<int> nums={3,9,8,4,0,1,7};
    TreeNode* root=createTree(nums,nums.size(),0);
    Solution ans;
    vector<vector<int>> res=ans.verticalOrder(root);
    PrintMartrix(res);
}