#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices){
        if(prices.size()<=1) return 0;
        int min_price=prices[0];//买入的最小值
        int max_profit=0;//最大利润
        for(int i=1;i<prices.size();++i){
            max_profit=max(max_profit,prices[i]-min_price);
            min_price=min(min_price,prices[i]);
        }
        return max_profit;
    }
};
int main(){
    vector<int> price={7,1,5,3,6,4};
    Solution ans;
    int max=ans.maxProfit(price);
    cout<<max;
}