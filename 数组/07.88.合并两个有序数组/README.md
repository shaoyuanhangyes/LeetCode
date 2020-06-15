# 7(88) 合并两个有序数组
## 描述
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。


初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。


## 示例
```bash
输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]

``` 

## Description
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

## Example
```bash
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]

```
`BitDance` `Amazon` `Microsoft` `Adobe` `Apple` `Google` `Tencent` `FaceBook` `Alibaba` `Yahoo` `Cisco` `HuaWei` `JD` `Baidu` `Cisco` `Mi` `DiDi` `Linkedln`
## 解题
```bash
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=nums1.size()-1;//i指向nums1中要插入的位置
        int p1=m-1;//p1指向nums1中要比较的元素的位置
        int p2=n-1;//p2指向nums2中要比较的元素的位置
        while (p1>=0&&p2>=0){//循环条件:p1 p2有一个遍历完数组就退出循环
            if(nums1[p1]<nums2[p2]){
                nums1[i--]=nums2[p2--];
            }
            else{
                nums1[i--]=nums1[p1--];
            }
        }//三种情况
        /*1.nums1中元素都比nums2中的元素值要小 因此把nums2元素复制到nums1尾部即可 直接通过
          2.nums1中元素都比nums2中的元素值要大 nums1元素依序复制到尾部 然后将nums2中元素复制到nums1中剩下的位置
          3.12混合情况 nums1与nums2中元素互有大小 循环到最后数组内剩余元素一定会出现12情况*/
        while (p2>=0) nums1[i--]=nums2[p2--];//p1遍历完 p2还剩余 将nums2中元素依次复制到nums1中剩余的位置
    }
};
int main()
{
    vector<int> nums1={1,0,0};
    vector<int> nums2={1,2};
    Solution answer1;//情况1
    answer1.merge(nums1,nums1.size()-nums2.size(),nums2,nums2.size());
    for(auto x:nums1) cout<<x<<" ";
	cout<<endl; 
    vector<int> nums3={3,4,5,0,0};
    vector<int> nums4={1,2};//情况2
    answer1.merge(nums3,nums3.size()-nums4.size(),nums4,nums4.size());
    for(auto x:nums3) cout<<x<<" ";
    return 0;
}

```