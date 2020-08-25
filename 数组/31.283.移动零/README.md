# 31(283) 移动零

## 描述

给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序

## 示例

```bash

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]

``` 

说明:
必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。

## Description

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

## Example

```bash

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

```

Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

### 操作局部优化

利用双指针 index i 将数组内非零元素都堆在数组前半段 移动结束后index指向的位置是非零元素的后一个 从这里开始填0直到数组长度恢复原样

```C++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=0) nums[index++]=nums[i];
        }
        for(int i=index;i<nums.size();++i){
            nums[i]=0;
        }
    }
};
```

```
时间复杂度: O(n) 但操作仍然是局部优化的。代码执行的总操作（数组写入）为 n（元素总数）。
空间复杂度: O(1) 只使用常量空间。
```

假如数组为[0,0,0,0,0,0,0,0,0,0,1] 数组浪费了很多操作在写入0上 因此算法还可以进行优化

### 操作最优化

双指针i index 当i所指的元素不为0时 就将i和index所指的元素交换位置 然后index++ 交换次数是非零元素的个数 相比较上一个解法减少了元素的交换次数

```C++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=0){
                int temp=nums[index];
                nums[index]=nums[i];
                nums[i]=temp;
                ++index;
            }
        }
    }
};
```

```
时间复杂度: O(n) 但是，操作是最优的。代码执行的总操作（数组写入）是非 0 元素的数量 
空间复杂度: O(1) 只使用常量空间。
```

此解法更实用于数组内0元素较多的情况 假设数组内所有元素都非0 则数组写入次数与局部优化再填充是一样的
