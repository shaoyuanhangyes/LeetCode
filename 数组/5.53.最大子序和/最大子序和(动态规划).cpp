#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {//动态规划
        if(nums.empty()) return 0;//空数组直接返回0
        int dp[nums.size()];//dp[i]中存的是以nums[i]为结尾的最大子序列之和
        dp[0]=nums[0];//dp存数组第一位
        int max=dp[0];//若数组就一个元素 那么这个元素就是最大值
        for(int i=1;i<nums.size();i++){
            if(dp[i-1]>0){
                dp[i]=dp[i-1]+nums[i];
            }
            else dp[i]=nums[i];
            if(max<dp[i]) max=dp[i];//max记录最大的
        }
        return max;
    }
};
int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution answer;
    int max=answer.maxSubArray(nums);
    cout<<max;
    return 0;
}
