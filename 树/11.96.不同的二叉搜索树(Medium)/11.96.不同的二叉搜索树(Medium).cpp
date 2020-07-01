#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
int numTrees(int n) {
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<n+1;i++){
        for(int j=1;j<i+1;j++){
            dp[i]+=dp[j-1]*dp[i-j];
        }
    }
    return dp[n];
}
int main(){
    int n;
    cout<<"请输入二叉搜索树结点的个数n=";
    cin>>n;
    cout<<endl
        <<n<<"个结点的二叉搜索树的个数为"
        <<numTrees(n);
    return 0;
}
