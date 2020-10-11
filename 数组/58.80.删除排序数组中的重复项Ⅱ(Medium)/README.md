# 58(80) 删除排序数组中的重复项(Medium)

## 描述

给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

## 示例

```bash

示例 1:

给定 nums = [1,1,1,2,2,3],

函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,0,1,1,1,1,2,3,3],

函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。

你不需要考虑数组中超出新长度后面的元素。

``` 

## Description

Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

## Example

```bash

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

It doesn't matter what values are set beyond the returned length.

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

双指针解题 只需一次遍历

初始化慢指针sp=1 快指针fp=2 

快指针fp用于从位置序号2开始遍历到数组的尾部

遍历中找出sp-1的元素和fp的元素不等的情况 `nums[sp-1]!=nums[fp]` 若不等 则将慢指针++sp的元素替换为快指针fp的元素

代码流程如下:
```bash
nums={1   1   1   2   2   3}
    sp-1  sp  fp             #nums[sp-1]=nums[fp] 继续遍历

nums={1   1   1   2   2   3}
    sp-1  sp      fp         #nums[sp-1]!=nums[fp] 所以将nums[++sp]=nums[fp]

数组变为:
nums={1   1   2   2   2   3}
        sp-1  sp      fp     #继续比较 nums[sp-1]!=nums[fp] 所以将nums[++sp]=nums[fp]
#因为元素相同所以数组没变化
nums={1   1   2   2   2   3}
            sp-1  sp      fp #继续比较 nums[sp-1]!=nums[fp] 所以将nums[++sp]=nums[fp]

nums={1   1   2   2   3   3}
                sp-1  sp      fp #fp越界 此时sp=4 

返回sp+1 即5  数组元素变为{1 1 2 2 3} 最后的3被sp+1的数值卡住无法被遍历到
```

### 代码

```C++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2) return nums.size();
        int sp=1;
        for(int fp=2;fp<nums.size();++fp){
            if(nums[sp-1]!=nums[fp]) nums[++sp]=nums[fp];
        }
        return sp+1;
    }
};
```