# 4(35) 搜索插入位置
## 描述
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

## 示例
```bash
输入: [1,3,5,6], 5
输出: 2
输入: [1,3,5,6], 2
输出: 1
输入: [1,3,5,6], 7
输出: 4
输入: [1,3,5,6], 0
输出: 0
``` 
## Description
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

## Example
```bash
Input: [1,3,5,6], 5
Output: 2
Input: [1,3,5,6], 2
Output: 1
Input: [1,3,5,6], 7
Output: 4
Input: [1,3,5,6], 0
Output: 0
```

## 解题
```bash
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        if(nums.empty()) return 0;//数组为空时输入任何数据序号都是0
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        //考察的是折半查找失败时 low指向的位置就是该数据应该插入的位置
        return low;
    }
};
int main(){//测试
    Solution answer;
    vector<int> nums={1,3,5,6,7};
    int target=3;
    int pos=answer.searchInsert(nums,target);
    cout<<pos;
    return 0;
}


```