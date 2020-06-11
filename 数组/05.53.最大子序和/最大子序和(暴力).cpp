#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {//暴力解法
        int max=nums[0];
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum>max) max=sum;
            }
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
