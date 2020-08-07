#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n=nums.size();
        if(n==1) return nums[0];
        int dp[n][2];
        dp[0][0]=0;dp[0][1]=nums[0];
        dp[1][0]=nums[1];dp[1][1]=nums[0];
        for(int i=2;i<n;++i){
            if(i==n-1){//偷取最后一家
                dp[i][0]=max(dp[i-2][0]+nums[i],dp[i-1][0]);
                dp[i][1]=dp[i-1][1];
            }
            else{
                dp[i][0]=max(dp[i-2][0]+nums[i],dp[i-1][0]);
                dp[i][1]=max(dp[i-2][1]+nums[i],dp[i-1][1]);
            }
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};

int main(){
    vector<int> nums={2,7,9,3,1};
    Solution ans;
    int maxProfit=ans.rob(nums);
    cout<<maxProfit;
}