# 24(11) 盛最多水的容器(Medium)
## 描述

给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

## 示例

```bash

输入：[1,8,6,2,5,4,8,3,7]
输出：49

``` 

## Description

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

## Example

```bash

Input: [1,8,6,2,5,4,8,3,7]
Output: 49

```

`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei`

## 解题

### 双指针

盛水的面积计算公式为: `min(height[i],height[j])*(j-i)`

因此 在x轴确定的情况下 盛水面积取决于较短的height值 使用双指针是为了缩短搜索空间 所以计算面积后 移动指针时要移动height值小的那个指针

```C++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int res=0;
        while(i<j){
            res=max(res,(j-i)*min(height[i],height[j]));
            if(height[i]<=height[j]) i++;
            else j--;
        }
        return res;
    }
};
```

```
执行用时：24 ms, 在所有 C++ 提交中击败了12.31%的用户
内存消耗：7.8 MB, 在所有 C++ 提交中击败了5.27%的用户
```