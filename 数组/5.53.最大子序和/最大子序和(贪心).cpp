#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {//贪心
        if(nums.empty()) return 0;//空数组直接返回0
        int max=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(max<sum) max=sum;//max记录最大的
            if(sum<0) sum=0;//若序列和<0就重置回0
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
