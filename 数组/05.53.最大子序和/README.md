# 5(53) 最大子序和

## 描述
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
## 示例
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
``` 
## Description
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.


## Example
```bash
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

```
`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei` `JD` `Baidu` `Cisco` `Mi` `DiDi` `Linkedln` `Intel` `NetEase` `Sina`
## 解题
动态规划
```bash

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

```