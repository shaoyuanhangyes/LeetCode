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
//����һ������ n������ 1 ... n Ϊ�ڵ���ɵĶ����������ж����֣�
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
    cout<<"������������������ĸ���n=";
    cin>>n;
    cout<<endl
        <<n<<"�����Ķ����������ĸ���Ϊ"
        <<numTrees(n);
    return 0;
}
