# 8(4) 寻找两个正序数组的中位数(Hard)
## 描述
给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。

请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

## 示例
```bash
nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
``` 

## Description
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.
## Example
```bash
nums1 = [1, 3]
nums2 = [2]

The median is 2.0

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
```
## 解题
### 变量释义
对传值过来的有序数组进行分割 分割后数组分为两部分 分割的位置有两种情况 第一种是分割的位置是一个数存在的位置 那么这个数既属于左部分 又属于右部分 第二种是分割的位置是两个数中间
定义LMax为数组分割后左部分最大的值 定义RMin为数组分割后右部分最小的值
eg: `数组[2,3,5]` 假定在3的位置进行分割 数组变为`[2,3/3,5]` 因此`LMax=3` `RMin=3`
`数组[1,4,7,9]` 假定在4和7的中间分割 数组变为`[1,4/7,9]`因此`LMax=4` `RMin=7`

题目中涉及到nums1和nums2两个数组 因此声明`LMax1`为nums1中左部分最大的值 `RMin1`为nums1中右部分最小的值 `LMax2`为nums2中左部分最大的值 `RMin2`为nums2中右部分最小的值
声明c1为nums1中进行分割的位置 声明c2为nums2中进行分割的位置

首先 有一个公认的事实 `LMax1<=RMin1 LMax2<=RMin2`恒成立 因为数组有序 若分割的位置是某个数 则等号成立
其次 一个判断条件 能否使`LMax1<=RMin2 LMax2<=RMin1`成立呢 

|LeftPart|Position=k|RightPart|
|:------:|:------:|:------:|
|`LMax1`|/|`RMin1`|
|`LMax2`|/|`RMin2`|

若数组nums1分割的位置为c1 数组nums2分割的位置为c2时(c1+c2=k 后面会用到这个和k) `LMax1<=RMin2 LMax2<=RMin1`这个条件成立 则两个数组的左部分所有元素都小于右部分的元素 那么这两个数组左部分的最大值就是`max(LMax1,LMax2)` 同理这两个数组右部分的最小值就是`min(RMin1,RMin2)` <b>那么所求的中位数就是 `(max(LMax1,LMax2)+min(RMin1,RMin2))/2.0` </b>这样求中位数的要求是数组的长度必须是偶数 若不是偶数就不成立(下面会解决数组长度偶数的问题)

但如果`LMax1>RMin2`呢 说明数组nums1中左部分的元素多了 需要减少nums1中左部分元素的数量 所以先减小c1的值 c2=k-c1就增大了 
同理 `LMax2>RMin1` 说明数组nums2中左部分的元素多了 需要减少nums2中左部分元素的数量 所以先减小c2的值 c1=k-c2就增大了

### 情景假设
```bash
vector<int> nums1={2,3,5};
vector<int> nums2={1,4,7,9};
```
假设k=3(k为什么为3我们下面再提) `c1=1 c2=k-c1=2`
数组nums1变为`[2/3,5]` 数组nums2变为`[1,4/7,9]`
`LMax1=2 RMin1=3` `LMax2=4 RMin2=7` 满足`LMax1<RMin2` 但不满足`LMax2<RMin1` 
所以我们要减少c2的值 所以`c2=1 c1=2`
数组nums1变为`[2,3/5]` 数组nums2变为`[1/4,7,9]` 
`LMax1=3 RMin1=5` `LMax2=1 RMin2=4` 满足`LMax1<=RMin2 LMax2<=RMin1`
但此时问题来了 两个数组的长度加起来是7是奇数 所以中位数一定是数组里的元素 而不是两个值除以2 
所以我们要解决掉数组合并后长度和是奇数的问题
解决这个问题有一个巧妙的方法 就是通过给数组元素的空档填充`#`来改变数组的长度

|Old vector|Old length|New vector|New length|
|:------:|:------:|:------:|:------:|
|`[2,3,5]`|3|`[# 2 # 3 # 5 #]`|7|
|`[1,4,7,9]`|4|`[# 1 # 4 # 7 # 9 #]`|9|

假设数组nums1长度为`m` 数组nums2长度为`n` 合并后长度`m+n`可能是奇数也有可能是偶数 通过给数组元素空档填充`#` 数组nums1长度变为`2m+1` 数组nums2长度变为`2n+1` 合并后长度变为`2m+2n+2` 恒为偶数
接下来我们要保证填充了`#`后原来的元素的位置和现在的位置能够一一对应上
对于nums1的元素2 原来的位置序号是`0` 现在是`1` 因为`1/2=0`
对于nums1的元素3 原来的位置序号是`1` 现在是`3` 因为`3/2=1`
对于nums1的元素5 原来的位置序号是`2` 现在是`5` 因为`5/2=2`
对于nums2的元素1 原来的位置序号是`0` 现在是`1` 因为`1/2=0`
对于nums2的元素4 原来的位置序号是`1` 现在是`3` 因为`3/2=1`
对于nums2的元素7 原来的位置序号是`2` 现在是`5` 因为`5/2=2`
对于nums2的元素9 原来的位置序号是`3` 现在是`7` 因为`7/2=3`

进行数组分割时 如果分割的位置上是`#` 就等于在两个数之间分割 如果分割的位置上是数字 等于把数字划分到两个部分 
<b>因此总是成立 `LMaxi=(ci-1)/2位置上的元素` `RMini=ci/2位置上的元素`</b>

原来的例子
```bash
vector<int> nums1={2,3,5};
vector<int> nums2={1,4,7,9};
```
数组nums1变为`[# 2 # 3 # 5 #]` 数组nums2变为`[# 1 # 4 # 7 # 9 #]` 
经过多次的查找 最终确定`c1=4` `c2=3`
数组nums1变为`[2,3/5]` 数组nums2变为`[1,4/4,7,9]`
即`LMax1=3 RMin1=5` `LMax2=4 RMin2=4` 满足`LMax1<=RMin2 LMax2<=RMin1`
所以中位数`(max(LMax1,LMax2)+min(RMin1,RMin2))/2.0=(4+4)/2.0=4.0`

### 代码逻辑
例子数组的情况已经分析完毕 可以正确的找到两个正序数组的中位数 接下来是处理代码逻辑
首先 如何确定分割的位置 确认分割的位置其实就是一种查找 最快的查找是二分查找(折半查找)
其次 对哪一个数组进行二分查找 根据之前的分析 只要c1和c2中的任意一个确定了 另外一个也会随之确定 因此我们为了提升查找的效率 我们肯定选择长度短的数组来进行二分查找 因此一定要判断两个数组的长度 对短数组进行二分查找
<b>若`LMax1>RMin2` 把c1减小 c2增大</b> <b>若`LMax2>RMin1`</b> (本应把c2减小 c1增大 但只对nums1进行二分查找且c1+c2=k 所以)<b>把c1增大 c2减小</b>

如果c1或者c2已经到达了数组边缘怎么办?
这种情况会出现在:`有个数组内的元素的值全都小于或大于中值`
假设数组nums1长度为`m` 数组nums2长度为`n` 通过给数组元素空档填充`#` 数组nums1长度变为`2m+1` 数组nums2长度变为`2n+1` nums1序号为`0-2m` nums2序号为`0-2n` 假定`m<n` 会出现4种情况:
`c1=0` nums1所有的元素都在右部分 所以都比中值大 中值在nums2中 所以我们假定`LMax1= INT_MIN`
`c1=2m` nums1所有的元素都在左部分 所以都比中值小 中值在nums2中 所以我们假定`RMin1=INT_MAX` 来确保`LMax2<=RMin1`恒成立
`c2=0` nums2所有的元素都在右部分 所以都比中值大 中值在nums1中 所以我们假定`LMax2=INT_MIN`
`c2=2n` nums2所有的元素都在左部分 所以都比中值小 中值在nums1中 所以我们假定`RMin2=INT_MAX` 来确保`LMax1<=RMin2`恒成立

### 完整代码
```bash
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /*中位数的作用是把一个集合划分为两个长度相等的集合 其中一个子集中的元素总是大于另一个子集中的元素*/
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        if(len1>len2) return findMedianSortedArrays(nums2,nums1);//确保第一个传参的数组长度是最短的 因为要对短数组进行二分查找
        int LMax1,LMax2,RMin1,RMin2,c1,c2,low=0,high=2*len1;
        while(low<=high){//对长度较短的数组进行二分查找确认c1的位置
            c1=(low+high)/2;
            c2=len1+len2-c1;

            LMax1=(c1==0)?INT_MIN:nums1[(c1-1)/2];
            RMin1=(c1==2*len1)?INT_MAX:nums1[c1/2];
            LMax2=(c2==0)?INT_MIN:nums2[(c2-1)/2];
            RMin2=(c2==2*len2)?INT_MAX:nums2[c2/2];

            if(LMax1>RMin2) high=c1-1;
            else if(LMax2>RMin1) low=c1+1;
            else break;
        }
        return (max(LMax1,LMax2)+min(RMin1,RMin2))/2.0;
    }
    int max(int n1,int n2){//返回两个数中的最大值
        if(n1>n2) return n1;
        else return n2;
    }
    int min(int n1,int n2){//返回两个数中的最小值
        if(n1<n2) return n1;
        else return n2;
    }
};
int main(){
    vector<int> nums1={2,3,5};
    vector<int> nums2={1,4,7,9};
    Solution answer;
    double res=answer.findMedianSortedArrays(nums1,nums2);
    cout<<res<<endl;
    return 0;
}
```