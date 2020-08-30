# 34(42) 接雨水(Hard)

## 描述

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

## 示例

```bash

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

``` 

## Description

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

## Example

```bash

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

### 解法一 暴力按列

关注这一列的左侧最高的墙是多少和右侧最高的墙是多少 求每一列的水 只需要关注左侧最高`max_left`的和右侧最高的`max_right`中较矮的那一个

根据较矮的那个墙和当前列可以区分为三种情况:

1. 较矮的那个墙比当前列高 正在求的列装水的量为`min(max_left,max_right)-height[i]` 

2. 较矮的那个墙和当前列一样高 正在求的列装水的量为0

3. 较矮的那个墙比当前列低 正在求的列装水的量为0


#### 代码

```C++
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int sum=0;
        for(int i=1;i<height.size()-1;++i){
            int max_left=0;
            for(int j=i-1;j>=0;--j){
                if(height[j]>max_left) max_left=height[j];
            }
            int max_right=0;
            for(int j=i+1;j<=height.size()-1;++j){
                if(height[j]>max_right) max_right=height[j];
            }
            int min_both=min(max_left,max_right);
            if(min_both>height[i]) sum+=(min_both-height[i]);
        }
        return sum;
    }
};  
```

时间复杂度O(n^2) 空间复杂度O(1)

### 解法二 动态规划优化暴力

因为每一次外循环都要计算出当前列的左侧最高和右侧最高 所以采取动态规划的空间换时间的方式 用一个数组记录每一列的左侧最高和右侧最高的情况`max_left[height.size()];max_right[height.size()];`

这样就避免了一次循环来记录双最值 

需要注意的情况是 数组初始化里面的值是随机的垃圾数 因为两端的列上是不会装水的 所以循环的时候直接跳过了 但计算最大的列高的时候是会考虑进去的 所以必须要对数组表示两端的值进行初始化

#### 代码

```C++
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int sum=0;
        int max_left[height.size()];
        int max_right[height.size()];
        max_left[0]=max_right[0]=height[0];
        max_left[height.size()-1]=max_right[height.size()-1]=height[height.size()-1];
        for(int i=1;i<height.size()-1;++i){
            max_left[i]=max(max_left[i-1],height[i-1]);
        }
        for(int i=height.size()-2;i>=0;--i){
            max_right[i]=max(max_right[i+1],height[i+1]);
        }
        for(int i=1;i<height.size()-1;++i){
            int min_both=min(max_left[i],max_right[i]);
            if(min_both>height[i]) sum+=(min_both-height[i]);
        }
        return sum;
    }
};
```

时间复杂度O(n) 空间复杂度O(n)


### 解法三 双指针

动态规划优化后 虽然时间复杂度降到了O(n) 但空间复杂度却增加了 并且用来记录最值的数组里的值我们只使用了一次 这样用数组保存有点过于浪费 因此使用双指针优化 将空间复杂度降为O(1)

#### 代码

```C++
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int sum=0;
        int left=0,right=height.size()-1;
        int max_left=height[left],max_right=height[right];
        while(left<right){
            max_left=max(max_left,height[left]);
            max_right=max(max_right,height[right]);
            if(max_left<max_right){
                sum+=max_left-height[left];
                left++;
            }
            else{
                sum+=max_right-height[right];
                right--;
            }
        }
        return sum;
    }
};
```

时间复杂度O(n) 空间复杂度O(1)