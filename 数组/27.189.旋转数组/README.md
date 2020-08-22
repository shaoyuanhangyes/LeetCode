# 27(189) 旋转数组

## 描述

给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数

## 示例

```bash

示例 1:

输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]

``` 

说明:

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的 原地 算法。

## Description

Given an array, rotate the array to the right by k steps, where k is non-negative.

Constraints:

1 <= nums.length <= 2 * 10^4
It's guaranteed that nums[i] fits in a 32 bit-signed integer.
k >= 0

## Example

```bash

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]


```

Follow up:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?


`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

### 代码

`nums.size()%k!=0`时 即数组长度不是被向后移动次数k整倍数的时候 循环移动数组内元素向后移动k次 总是能回到第一个移动的元素的原位

eg: `nums=[0,1,2,3,4]` `k=2` `nums.size()=5` 因此`nums.size()%k!=0` 所以 `nums[2]=0 nums[4]=2 nums[1]=4 nums[3]=1 nums[0]=3` 回到了第一个移动元素的原位

`nums.size()%k==0`时 即数组长度是向后移动次数k的整倍数的时候 数组内`nums.size()/k`个元素移动后 就回到了第一个移动元素的原位 但数组内元素并没全部移动完毕 因此将回到原位的指示物向后移动一格 继续下一次的循环移动

eg: `nums=[0,1,2,3]` `k=2` `nums.size()=4` 因此`nums.size()%k==0` 所以 第一轮移动 `nums[2]=0 nums[0]=2` 回到了原位 所以向后移动一格继续第二轮移动 从`nums[1]`开始移动 `nums[3]=1 nums[1]=3` 又回到了原位 若还有未移动的元素 就继续向后移动一格 继续下一轮移动

变量释义:
    `start`记录这一轮移动的初始位置
    `count`记录已经移动了的元素的个数 
    `index`记录需要移动的元素的序号 从0开始
    `need`记录需要移动元素的值
    `next`记录将当前元素向后移动k个位置的序号
    `temp`记录nums[next]里存放的值

`nums[next]=need` 将需要移动的元素存入指定位置 `need=temp` 这个指定位置的元素成为下一个需要移动的元素
`index=next` 下一个移动元素的序号也随之更新 一个元素移动过后count就加1 

若index序号回到了初始位置start 但数组内元素并未全部更换位置即`count!=nums.size()` 就从初始位置start的下一个位置开始继续循环 

```C++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        int count=0; //已移动元素的个数
        for(int start=0;count<nums.size();++start){
            int index=start;
            int need=nums[start];
            do{
                int next=(index+k)%nums.size();
                int temp=nums[next];
                nums[next]=need;
                need=temp;
                index=next;
                count++;
            }while(start!=index);
        }
    }
};
```

```
执行用时：16 ms, 在所有 C++ 提交中击败了13.30%的用户
内存消耗：9.8 MB, 在所有 C++ 提交中击败了81.03%的用户
```

