# 62(33) 搜索旋转排序数组(Medium)

## 描述

整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 


## 示例

```bash

示例 1：

输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4

示例 2：

输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1

示例 3：

输入：nums = [1], target = 0
输出：-1

``` 

提示：

提示：

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
nums 中的每个值都 独一无二
题目数据保证 nums 在预先未知的某个下标上进行了旋转
-10^4 <= target <= 10^4

进阶：你可以设计一个时间复杂度为 O(log n) 的解决方案吗？

## Description

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

## Example

```bash

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:

Input: nums = [1], target = 0
Output: -1

```

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

使用二分法
将目标数组`[l,r]`分为两个数组`[l,mid] and [mid+1,r]` 其中一个数组一定是有序的 另一个数组是有序或部分有序

因为题目给定了数组长度的限制条件 所以不用考虑`mid = (l+r)/2`的溢出问题

假设 `[l,mid]`是有序数组 若`nums[l]<=target<nums[mid]` 则搜索范围缩小至`[l,mid-1]`  否则搜索范围就变为`[mid+1,r]`
假设 `[mid+1,r]`是有序数组 若`nums[mid]<target<=nums[r]` 则搜索范围缩小至`[mid+1,r]` 否则搜索范围就变为`[l,mid-1]`

### 代码

```C++
class Solution {
public:
    int search(vector<int>& nums, int target) {
      int l = 0, r = nums.size() - 1;
      while (l <= r) {
         int mid = (l + r) / 2;
         if (nums[mid] == target)
            return mid;
         if (nums[l] <= nums[mid]) {
            if (nums[l] <= target && target < nums[mid])
               r = mid - 1;
            else
               l = mid + 1;
         } else {
            if (nums[mid] < target && target <= nums[r])
               l = mid + 1;
            else
               r = mid - 1;
         }
      }
      return -1;
   }
};
```