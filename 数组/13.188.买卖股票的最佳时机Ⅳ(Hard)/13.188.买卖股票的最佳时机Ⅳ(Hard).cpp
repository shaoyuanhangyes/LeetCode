
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxProfit_infinite(vector<int>& prices){//解决k相当于无限次 跟Ⅱ一样
        int max_profit=0;
        for(int i=1;i<prices.size();++i){
            if(prices[i]>prices[i-1]) max_profit+=prices[i]-prices[i-1];
        }
        return max_profit;
    }
    int maxProfit(int k,vector<int>& prices){
        if(prices.size()<=1||k<1) return 0;
        int len=prices.size();
        if(k>len/2) return maxProfit_infinite(prices);
        int dp[k][2];
        for(int i=0;i<k;++i) {
            dp[i][0]=INT_MIN;dp[i][1]=INT_MIN;
        }
        for(int price:prices){
            dp[0][0]=max(dp[0][0],-price);
            dp[0][1]=max(dp[0][1],dp[0][0]+price);
            for(int i=1;i<k;++i){
                dp[i][0]=max(dp[i][0],dp[i-1][1]-price);
                dp[i][1]=max(dp[i][1],dp[i][0]+price);
            }
        }
        return dp[k-1][1];
    }
};
int main(){
    vector<int> prices={3,2,6,5,0,3};
    Solution ans;
    int max=ans.maxProfit(2,prices);
    cout<<max;
}