# 1(1) 两数之和
## 描述
给定一个整数数组 `nums` 和一个目标值 `target`，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。


## 示例
```bash
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
``` 
## Description
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

## Example
```bash
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```
`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei` `JD` `Baidu` `Cisco` `Mi` `DiDi` `Linkedln` `iQiyi` `Uber` `NetEase` `360` `Visa`
## 解题
```bash
#include<iostream>
#include<vector>
#include<map>
using namespace std; 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;//first存nums的值 second存迭代器 
        vector<int> result;//结果数组 
        for(int i=0;i<nums.size();++i){
            if(m.find(nums[i])==m.end()){//未找到 
                m[target-nums[i]]=i;//m[7]=0;m[2]=1;break;后面不用运行m[-2]=3;m[-6]=4
            }
            else{
                result.push_back(m[nums[i]]);//m[7]=0 0存入result
                result.push_back(i);//i=1 1存入result  
                break;//题目强调每种输入只对应一个答案 所以break节省空间 
            }
        }
        return result;
    }
};
int main(){//测试用例
	Solution answer;
	vector<int> nums={2,7,11,15};
	int target=9;
	vector<int> result=answer.twoSum(nums,target);
	for(auto x:result) cout<<x<<" ";
} 

```