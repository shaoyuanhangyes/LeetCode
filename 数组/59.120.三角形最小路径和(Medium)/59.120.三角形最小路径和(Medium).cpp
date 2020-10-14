#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;++i){
            dp[i][0]=dp[i-1][0]+triangle[i][0];
            for(int j=1;j<i;++j){
                dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
            }
            dp[i][i]=dp[i-1][i-1]+triangle[i][i];
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};

int main(){
    vector<vector<int>> triangle={{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution ans;
    cout<<ans.minimumTotal(triangle);
}