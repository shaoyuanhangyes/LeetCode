#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()||grid[0].empty()) return 0;
        int rows=grid.size(),cols=grid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        dp[0][0]=grid[0][0];
        for(int i=1;i<rows;++i){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int j=1;j<cols;++j){
            dp[0][j]=dp[0][j-1]+grid[0][j];
        }
        for(int i=1;i<rows;++i){
            for(int j=1;j<cols;++j){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[rows-1][cols-1];
    }
};

int main(){
    vector<vector<int>> grid={{1,3,1},{1,5,1},{4,2,1}};
    Solution ans;
    cout<<ans.minPathSum(grid);
}