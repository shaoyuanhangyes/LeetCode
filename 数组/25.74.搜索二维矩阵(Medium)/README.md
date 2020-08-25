# 25(74) 搜索二维矩阵(Medium)

## 描述

编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。


## 示例

```bash

示例 1:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
输出: true
示例 2:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
输出: false


``` 

## Description

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

## Example

```bash

Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false

```

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
