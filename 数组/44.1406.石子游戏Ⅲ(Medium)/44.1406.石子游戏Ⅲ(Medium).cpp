#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size()+3,0);
        int sum=0;
        for(int i=stoneValue.size()-1;i>=0;--i){
            dp[i]=INT_MIN;
            sum+=stoneValue[i];
            for(int j=1;j<=3;++j){
                dp[i]=max(dp[i],sum-dp[i+j]);
            }
        }
        if(dp[0]>sum-dp[0]) return "Alice";
        else if(dp[0]<sum-dp[0]) return "Bob";
        else return "Tie";
    }
};

int main(){
    vector<int> stoneValue={1,2,3,7};
    Solution ans;
    cout<<ans.stoneGameIII(stoneValue);
}