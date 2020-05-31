# 9(15) 三数之和(Medium)
## 描述
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

## 示例
```bash
给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

``` 

## Description
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.
## Example
```bash
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

```
## 解题
```bash
#include <iostream>
#include <vector>
#include <algorithm>//sort()
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3) return res;//元素数量小于3
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;++i){
            if(i>0&&nums[i]==nums[i-1]) continue;//有序数组 跳过数值一样的 除重一
            int low=i+1,high=nums.size()-1;
            while(low<high){
                int sum=nums[i]+nums[low]+nums[high];
                if(sum==0){
                    res.push_back(vector<int> {nums[i],nums[low],nums[high]});
                    while(low<high&&nums[low]==nums[low+1]) low++;//二分遍历数组跳过相同的数值 除重二
                    low++;
                    while(low<high&&nums[high]==nums[high-1]) high--;//二分遍历数组跳过相同的数值 除重三
                    high--;
                }
                else if(sum>0){
                    high--;
                }
                else{
                    low++;
                }
            }
        }
        return res;
    }
    void PrintMartrix(vector<vector<int>>& res){//打印二维vector
        for(int i=0;i<res.size();++i){
            cout<<"[";
            for(int j=0;j<res[i].size();++j){
                cout<<" "<<res[i][j]<<" ";
            }
            cout<<"]"<<endl;
        }
    }
};
int main(){
    vector<int> nums={-1,0,1,2,-1,-4};//示例
    Solution answer;
    vector<vector<int>> res=answer.threeSum(nums);
    answer.PrintMartrix(res);
    return 0;
}
```