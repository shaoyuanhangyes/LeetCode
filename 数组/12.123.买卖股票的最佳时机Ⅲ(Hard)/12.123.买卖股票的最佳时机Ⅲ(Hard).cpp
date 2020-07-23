#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int len=prices.size();
        int dp[len][2][3];
        dp[0][0][0]=dp[0][0][1]=dp[0][0][2]=0;
        dp[0][1][0]=dp[0][1][1]=dp[0][1][2]=-prices[0];
        for(int i=1;i<len;++i){
            dp[i][0][0]=0;
            dp[i][0][1]=max(dp[i-1][0][1],dp[i-1][1][0]+prices[i]);
            dp[i][0][2]=max(dp[i-1][0][2],dp[i-1][1][1]+prices[i]);
            dp[i][1][0]=max(dp[i-1][1][0],dp[i-1][0][0]-prices[i]);
            dp[i][1][1]=max(dp[i-1][1][1],dp[i-1][0][1]-prices[i]);
            dp[i][1][2]=0;
        }
        return max(dp[len-1][0][2],dp[len-1][0][1]);
    }
};

int main(){
    vector<int> price={3,3,5,0,0,3,1,4};
    Solution ans;
    int max=ans.maxProfit(price);
    cout<<max;
}