class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size()<=1) return 0;
        int n=prices.size();
        int dp[n][2];
        dp[0][0]=-prices[0];
        dp[0][1]=0;//LC的编译器声明数组的时候初值都是随机数 clion初始化是0
        for(int i=1;i<n;++i){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]-prices[i]);
            dp[i][1]=max(dp[i-1][0]+prices[i]-fee,dp[i-1][1]);
        }
        return dp[n-1][1];
    }
};