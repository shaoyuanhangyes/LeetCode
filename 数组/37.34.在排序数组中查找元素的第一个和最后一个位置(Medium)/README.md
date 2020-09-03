# 37(34) 在排序数组中查找元素的第一个和最后一个位置(Medium)

## 描述

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

## 示例

```bash

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

``` 

## Description

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

## Example

```bash

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

```

Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non decreasing array.
-10^9 <= target <= 10^9

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

查找排序数组中的第一个和最后一个位置 因为是排序 所以想到二分查找

至于第一个位置和最后一个位置 就取决于二分过程中指针的移动

查找第一个位置:

```bash

if(nums[mid]<target) low=mid+1 
if(nums[mid]>target) high=mid-1
if(nums[mid]==target) high=mid-1  # 当查找到mid所对应的的值与target相等时 继续向左半区搜索

eg: [5,7,7,8,8,10] low=0,high=nums.size()-1=5 target=8
low=0 high=5 mid=2 nums[mid]=7<target low=mid+1=3 
low=3 high=5 mid=4 nums[mid]=8=target high=mid-1=4
low=3 high=4 mid=3 nums[mid]=8=target high=mid-1=3
low=3 high=3 mid=3 nums[mid]=8=target high=mid-1=2
low=3 high=2 越界 所以返回low指向的位置 即为所求的target第一次出现在数组的位置

返回low之前 需要判断low是否越界 and nums[low]是否等于target 

因为如果数组是[1,2,3,4] target=5 二分查找过程中low会越界 

如果数组是[2,3,4,5] target=1 二分查找中high会越界 此时只判断nums[low]==target即可
```

若查找第一个位置的时候就未查找到 就没必要再执行查找最后一个位置的函数了 直接返回{-1,-1}

查找最后一个位置:

```bash

if(nums[mid]<target)  low=mid+1 
if(nums[mid]>target)  high=mid-1
if(nums[mid]==target) low=mid+1   # 当查找到mid所对应的的值与target相等时 继续向右半区搜索

eg: [5,7,7,8,8,10] low=0,high=nums.size()-1=5 target=8
low=0 high=5 mid=2 nums[mid]=7<target low=mid+1=3 
low=3 high=5 mid=4 nums[mid]=8=target low=mid+1=4
low=4 high=5 mid=4 nums[mid]=8=target low=mid+1=5
low=5 high=5 mid=5 nums[mid]=10>target high=mid-1=4
low=5 high=4 越界 所以返回high指向的位置 即为所求的target第一次出现在数组的位置

没必要判断是否越界 因为查找第一个位置的时候 如果能查找到 那么就一定能够找到最后一个位置 查找不到就压根不会执行这个函数

```

所以这道题实际上考察了二分查找的时候对于相等条件是往左半区靠还是右半区 往左半区靠的时候low指针指向的就是第一次出现的位置 往右半区靠的时候high指针指向的就是最后一次出现的位置

同时二分查找的时候 mid=(low+high)/2 可能会出现溢出 因为low+high会超过int表示的最大范围 溢出了就会变成负数 

所以为了避免溢出 使用 mid=low+(high-low)/2

### 代码

```C++
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=FirstPosition(nums,target);
        if(first==-1) return vector<int> {-1,-1};
        int last=LastPosition(nums,target);
        return vector<int> {first,last};
    }
private:
    int FirstPosition(vector<int>& nums,int target){
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=target) high=mid-1;
            else low=mid+1;
        }
        if(low<nums.size()&&nums[low]==target) return low;
        return -1;
    }
    int LastPosition(vector<int>& nums,int target){
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<=target) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};

int main(){
    vector<int> nums={5,7,7,8,8,10};
    Solution ans;
    vector<int> res=ans.searchRange(nums,8);
    for(auto x:res) cout<<x<<" ";
}
```