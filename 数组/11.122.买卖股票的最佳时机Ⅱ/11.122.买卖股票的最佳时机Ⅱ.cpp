#include <iostream>
#include <vector>
using namespace std; 
class Solution {
public:
    int maxProfit(vector<int>& prices){//贪心算法
        if(prices.size()<=1) return 0;
        int max_profit=0;
        for(int i=1;i<prices.size();++i){
            max_profit+=max(prices[i]-prices[i-1],0);
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
